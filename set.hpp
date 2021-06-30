#ifndef SET_HPP

# define SET_HPP

#include <iostream>
#include <limits>
#include "iterator.hpp"

namespace ft{
    // class set
    template <typename T, typename Compare = ft::less<T>, typename Alloc = std::allocator<T> >
    class set{
        public:
            typedef T key_type;
            typedef T value_type;
            typedef Compare key_compare;
            typedef Compare value_compare;
            typedef std::allocator<value_type> allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef ConstIterator<value_type> iterator;
            typedef ConstIterator<value_type> const_iterator;
            typedef ConstReverseIterator<value_type> reverse_iterator;
            typedef ConstReverseIterator<value_type> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            ft::tree<value_type> *root;
            ft::tree<value_type> *leaf;
            size_type _size;
        public:
            // empty constructor
            explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                typename Alloc::template rebind<ft::tree<value_type> >::other   _alloc;

                (void)comp;
                (void)alloc;
                root = 0;
                leaf = _alloc.allocate(1);
                _alloc.construct(leaf, value_type());
                _size = 0;
            }
            
            // destructor
            ~set(){
                typename Alloc::template rebind<ft::tree<value_type> >::other   alloc;

                clear();
                alloc.destroy(leaf);
                alloc.deallocate(leaf, 1);
            }

            // range constructor
            template <typename InputIterator>
            set(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                typename Alloc::template rebind<ft::tree<value_type> >::other   _alloc;

                (void)comp;
                (void)alloc;
                root = 0;
                leaf = _alloc.allocate(1);
                _alloc.construct(leaf, value_type());
                _size = 0;
                insert(first, last);
            }

            // copy constructor
            set(const set &x){
                typename Alloc::template rebind<ft::tree<value_type> >::other   alloc;

                root = 0;
                leaf = alloc.allocate(1);
                alloc.construct(leaf, value_type());
                _size = 0;
                insert(x.begin(), x.end());
            }
            
            // assign content
            set &operator=(const set &x){
                clear();
                insert(x.begin(), x.end());
                return (*this);
            }

            // [Iterators]
            iterator begin(){
                if (root == 0)
                    return (iterator(leaf, root, leaf));
                return (iterator(root->front(), root, leaf));
            }

            const_iterator begin() const{
                if (root == 0)
                    return (const_iterator(leaf, root, leaf));
                return (const_iterator(root->front(), root, leaf));
            }
 
            iterator end(){
                return (iterator(leaf, root, leaf));
            }

            const_iterator end() const{
                return (const_iterator(leaf, root, leaf));
            }

            reverse_iterator rbegin(){
                if (root == 0)
                    return (reverse_iterator(leaf, root, leaf));
                return (reverse_iterator(root->back(), root, leaf));
            }

            const_reverse_iterator rbegin() const{
                if (root == 0)
                    return (const_reverse_iterator(leaf, root, leaf));
                return (const_reverse_iterator(root->back(), root, leaf));
            }

            reverse_iterator rend(){
                return (reverse_iterator(leaf, root, leaf));
            }

            const_reverse_iterator rend() const{
                return (const_reverse_iterator(leaf, root, leaf));
            }

            // [Capacity]
            bool empty() const { return (_size == 0); }

            size_type size() const { return (_size); }

            size_type max_size() const{
                return (std::min((size_type)std::numeric_limits<difference_type>::max(),
                                std::numeric_limits<size_type>::max() / sizeof(ft::tree<value_type>)));
            }

            // [Modifiers]
            // single element insert
            pair<iterator, bool> insert(const value_type &val){
                typename Alloc::template rebind<ft::tree<value_type> >::other   alloc;
                ft::tree<value_type>   *temp = root;
                ft::tree<value_type>   *new_node;
                ft::pair<iterator, bool>    ret;
                key_compare cmp;

                if (find(val) != end())
                {
                    ret.first = find(val);
                    ret.second = false;
                    return (ret);
                }
                new_node = alloc.allocate(1);
                alloc.construct(new_node, val);
                if (root == 0)
                    root = new_node;
                else
                {
                    while (1) // 들어갈 위치 찾기
                    {
                        if (cmp(temp->val, val) == true)
                        {
                            if (temp->right == 0)
                                break ;
                            temp = temp->right;
                        }
                        else
                        {
                            if (temp->left == 0)
                                break ;
                            temp = temp->left;
                        }
                    }
                    // 위치에 새로운 노드 넣기
                    if (cmp(temp->val, val) == true)
                    {
                        temp->right = new_node;
                        new_node->parent = temp;
                    }
                    else
                    {
                        temp->left = new_node;
                        new_node->parent = temp;
                    }
                    temp = new_node;
                    temp->rebalance();
                    while (root->parent != 0)
                        root = root->parent;
                }
                _size++;
                ret.first = find(val);
                ret.second = true;
                return (ret);
            }

            // with hint insert
            iterator insert(iterator position, const value_type &val){
                (void)position;
                return (insert(val).first);
            }

            // range insert
            template <typename InputIterator>
            void insert(InputIterator first, InputIterator last){
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }

            void erase(iterator position)
            {
                erase(*position);
            }

            size_type erase(const key_type &k){
                typename Alloc::template rebind<ft::tree<value_type> >::other   alloc;
                iterator    it = find(k);
                ft::tree<value_type>   *temp;

                if (it == end())
                    return (0);
                temp = it.getPtr();
                // 자식노드가 없는 경우
                if (temp->left == 0 && temp->right == 0)
                {
                    if (temp->parent == 0)
                        root = 0;
                    else
                    {
                        if (temp->parent->left == temp)
                            temp->parent->left = 0;
                        else if (temp->parent->right == temp)
                            temp->parent->right = 0;
                        temp->parent->rebalance();
                        while (root->parent != 0)
                            root = root->parent;
                    }
                    alloc.destroy(temp);
                    alloc.deallocate(temp, 1);
                }
                // 자식노드(왼쪽) 하나만 있는 경우
                else if (temp->left != 0 && temp->right == 0)
                {
                    if (temp->parent == 0)
                    {
                        temp->left->parent = temp->parent;
                        root = temp->left;
                    }
                    else{
                        if (temp->parent->left == temp)
                            temp->parent->left = temp->left;
                        else if (temp->parent->right == temp)
                            temp->parent->right = temp->left;
                        temp->left->parent = temp->parent;
                        temp->parent->rebalance();
                        while (root->parent != 0)
                            root = root->parent;
                    }
                    alloc.destroy(temp);
                    alloc.deallocate(temp, 1);
                }
                // 자식노드(오른쪽) 하나만 있는 경우
                else if (temp->left == 0 && temp->right != 0)
                {
                    if (temp->parent == 0)
                    {
                        temp->right->parent = temp->parent;
                        root = temp->right;
                    }
                    else{
                        if (temp->parent->left == temp)
                            temp->parent->left = temp->right;
                        else if (temp->parent->right == temp)
                            temp->parent->right = temp->right;
                        temp->right->parent = temp->parent;
                        temp->parent->rebalance();
                        while (root->parent != 0)
                            root = root->parent;
                    }
                    alloc.destroy(temp);
                    alloc.deallocate(temp, 1);
                }
                // 자식노드가 둘 다 있는 경우
                else
                {
                    ft::tree<value_type>   *temp_next;
                    ft::tree<value_type>   *test;
                    
                    it++;
                    temp_next = it.getPtr();
                    test = temp_next->parent;
                    if (temp->parent == 0)
                    {
                        if (temp_next->parent == temp)
                        {
                            temp_next->left = temp->left;
                            temp->left->parent = temp_next;
                            temp_next->parent = temp->parent;
                            root = temp_next;
                            temp_next->rebalance();
                        }
                        else
                        {
                            if (temp_next->parent->left == temp_next)
                                temp_next->parent->left = temp_next->right;
                            else if (temp_next->parent->right == temp_next)
                                temp_next->parent->right = temp_next->right;
                            if (temp_next->right != 0)
                                temp_next->right->parent = temp_next->parent;
                            temp_next->left = temp->left;
                            temp->left->parent = temp_next;
                            temp_next->right = temp->right;
                            temp->right->parent = temp_next;
                            temp_next->parent = temp->parent;
                            root = temp_next;
                            test->rebalance();
                        }
                    }
                    else
                    {
                        if (temp_next->parent == temp)
                        {
                            temp_next->left = temp->left;
                            temp->left->parent = temp_next;
                            temp_next->parent = temp->parent;
                            if (temp->parent->left == temp)
                                temp->parent->left = temp_next;
                            if (temp->parent->right == temp)
                                temp->parent->right = temp_next;
                            temp_next->rebalance();
                            while (root->parent != 0)
                                root = root->parent;
                        }
                        else
                        {
                            if (temp_next->parent->left == temp_next)
                                temp_next->parent->left = temp_next->right;
                            else if (temp_next->parent->right == temp_next)
                                temp_next->parent->right = temp_next->right;
                            if (temp_next->right != 0)
                                temp_next->right->parent = temp_next->parent;
                            temp_next->left = temp->left;
                            temp->left->parent = temp_next;
                            temp_next->right = temp->right;
                            temp->right->parent = temp_next;
                            temp_next->parent = temp->parent;
                            if (temp->parent->left == temp)
                                temp->parent->left = temp_next;
                            if (temp->parent->right == temp)
                                temp->parent->right = temp_next;
                            test->rebalance();
                            while (root->parent != 0)
                                root = root->parent;
                        }
                    }
                    alloc.destroy(temp);
                    alloc.deallocate(temp, 1);
                }
                _size--;
                return (1);
            }

            void erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    erase(first++);
                    first.setRoot(root);
                }
            }

            void swap(set &x){
                ft::tree<value_type> *r = root;
                size_type s = _size;

                root = x.root;
                _size = x._size;

                x.root = r;
                x._size = s;
            }

            void clear(){
                erase(begin(), end());
                root = 0;
                _size = 0;
            }

            // [Observers]
            key_compare key_comp() const { return (key_compare()); }

            value_compare value_comp() const { return (value_compare(key_compare())); }

            // [Operations]
            iterator find(const key_type &k){
                ft::tree<value_type>   *temp = root;
                Compare cmp;

                while (temp != 0)
                {
                    if (temp->val == k)
                        break ;
                    if (cmp(temp->val, k) == true)
                        temp = temp->right;
                    else
                        temp = temp->left;
                }
                if (temp == 0)
                    return (end());
                return (iterator(temp, root, leaf));
            }

            const_iterator find(const key_type &k) const{
                ft::tree<value_type>   *temp = root;
                Compare cmp;

                while (temp != 0)
                {
                    if (temp->val == k)
                        break ;
                    if (cmp(temp->val, k) == true)
                        temp = temp->right;
                    else
                        temp = temp->left;
                }
                if (temp == 0)
                    return (end());
                return (const_iterator(temp, root, leaf));
            }

            size_type count(const key_type &k) const{
                if (find(k) != end())
                    return (1);
                return (0);
            }

            iterator lower_bound(const key_type &k){
                ft::tree<value_type>   *temp = root;
                ft::tree<value_type>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(temp->val, k) == true)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val));
            }

            const_iterator lower_bound(const key_type &k) const{
                ft::tree<value_type>   *temp = root;
                ft::tree<value_type>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(temp->val, k) == true)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val));
            }

            iterator upper_bound(const key_type &k){
                ft::tree<value_type>   *temp = root;
                ft::tree<value_type>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(k, temp->val) == false)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val));
            }

            const_iterator upper_bound(const key_type &k) const{
                ft::tree<value_type>   *temp = root;
                ft::tree<value_type>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(k, temp->val) == false)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val));
            }

            pair<const_iterator, const_iterator> equal_range(const key_type &k) const{
                ft::pair<const_iterator, const_iterator>    ret;

                ret.first = lower_bound(k);
                ret.second = upper_bound(k);
                return (ret);
            }

            pair<iterator, iterator> equal_range(const key_type &k){
                ft::pair<iterator, iterator>    ret;

                ret.first = lower_bound(k);
                ret.second = upper_bound(k);
                return (ret);
            }
    };

    // [Non-member function overloads]
	template <typename T, typename Compare, typename Alloc>
    bool operator==(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
        typename ft::set<T>::const_iterator left = lhs.begin();
        typename ft::set<T>::const_iterator right = rhs.begin();

		if (lhs.size() != rhs.size())
		    return (false);
        while (left != lhs.end() && right != rhs.end())
        {
            if (*left != *right)
                return (false);
            left++;
            right++;
        }
        if (left != lhs.end() || right != rhs.end())
            return (false);
		return (true);
	}

    template <typename T, typename Compare, typename Alloc>
	bool operator!=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) { return (!(lhs == rhs)); }
	
	template <typename T, typename Compare, typename Alloc>
	bool operator<(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs)
	{
        typename ft::set<T>::const_iterator left = lhs.begin();
        typename ft::set<T>::const_iterator right = rhs.begin();

        while (left != lhs.end() && right != rhs.end())
        {
            if (*left < *right)
                return (true);
            else if (*left > *right)
                return (false);
            left++;
            right++;
        }
        if (right != rhs.end())
            return (true);
		return (false);
	}
	
	template <typename T, typename Compare, typename Alloc>
    bool operator<=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) { return (!(rhs < lhs)); }

	template <typename T, typename Compare, typename Alloc>
    bool operator>(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) { return (rhs < lhs); }

	template <typename T, typename Compare, typename Alloc>
    bool operator>=(const set<T, Compare, Alloc> &lhs, const set<T, Compare, Alloc> &rhs) { return (!(lhs < rhs)); }

	template <typename T, typename Compare, typename Alloc>
	void swap(set<T, Compare, Alloc> &x, set<T, Compare, Alloc> &y) { x.swap(y); }
}

#endif
