#ifndef MAP_HPP

# define MAP_HPP

#include <iostream>
#include <limits>
#include "utils.hpp"

namespace ft{
    // struct less
    template <typename T>
    struct less{
        bool operator()(const T &x, const T &y) const { return (x < y); }
    };

    // struct pair
    template <typename T1, typename T2>
    struct pair{
        typedef	T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        // default
        pair() : first(first_type()), second(second_type()) { }

        // copy
        template <typename U, typename V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){ }

        // initialization
        pair(const first_type &a, const second_type &b) : first(a), second(b) { }

        // assign content
        pair &operator=(const pair &pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };

    template <typename T1, typename T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <typename T1, typename T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs == rhs)); }

    template <typename T1, typename T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs){
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    
    template <typename T1, typename T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(rhs < lhs)); }

    template <typename T1, typename T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }

    template <typename T1, typename T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs < rhs)); }















    // struct tree
    template<typename Key, typename T, typename Compare>
    struct tree{
        ft::pair<const Key, T> val;
        tree *parent;
        tree *left;
        tree *right;
        int h;

        tree(ft::pair<const Key, T> value) : val(value), parent(0), left(0), right(0), h(0) { }

        int getBalanceFactor(){
            int lh = -1;
            int rh = -1;

            if (left != 0)
                lh = left->h;
            if (right != 0)
                rh = right->h;
            return (lh - rh);
        }

        void checkHeight(){
            ft::tree<Key, T, Compare>   *temp = this;

            while (temp != 0)
            {
                int lh = -1;
                int rh = -1;

                if (temp->left != 0)
                    lh = temp->left->h;
                if (temp->right != 0)
                    rh = temp->right->h;
                temp->h = std::max(lh, rh) + 1;
                temp = temp->parent;
            }
        }

        void LLrotation(){
            ft::tree<Key, T, Compare>   *temp = this;
            ft::tree<Key, T, Compare>   *pnode = temp->parent;
            ft::tree<Key, T, Compare>   *cnode = temp->left;
                         
            temp->left = temp->left->right;
            if (temp->left != 0)
                temp->left->parent = temp;
            cnode->right = temp;
            temp->parent = cnode;
            cnode->parent = pnode;
            if (pnode != 0)
            {
                if (pnode->left == temp)
                    pnode->left = cnode;
                else if (pnode->right == temp)
                    pnode->right = cnode;
            }
        }

        void RRrotation(){
            ft::tree<Key, T, Compare>   *temp = this;
            ft::tree<Key, T, Compare>   *pnode = temp->parent;
            ft::tree<Key, T, Compare>   *cnode = temp->right;

            temp->right = temp->right->left;
            if (temp->right != 0)
                temp->right->parent = temp;
            cnode->left = temp;
            temp->parent = cnode;
            cnode->parent = pnode;
            if (pnode != 0)
            {
                if (pnode->left == temp)
                    pnode->left = cnode;
                else if (pnode->right == temp)
                    pnode->right = cnode;
            }
        }

        void rebalance(){
            ft::tree<Key, T, Compare>   *temp = this;

            temp->checkHeight();
            while (temp != 0)   // bf 체크
            {
                int bf = temp->getBalanceFactor();

                if (bf < -1 || bf > 1)
                    break ;
                temp = temp->parent;
            }
            if (temp != 0)
            {
                int h1 = temp->getBalanceFactor();
                int h2 = 0;

                if (h1 > 1)
                    h2 = temp->left->getBalanceFactor();
                else if (h1 < -1)
                    h2 = temp->right->getBalanceFactor();

                if (h1 > 1 && h2 > 0)   // LLrotation(3, 2, 1 순으로 넣는 경우)
                {
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 < 0) // RRrotation(1, 2, 3 순으로 넣는 경우)
                {
                    temp->RRrotation();
                }
                else if (h1 > 1 && h2 < 0) // LRrotation(3, 1, 2 순으로 넣는 경우)
                {
                    temp->left->RRrotation();
                    temp->left->left->checkHeight(); // RRroation으로 원래 temp->left가 temp->left->left로 변함
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 > 0) // RLrotation(1, 3, 2 순으로 넣는 경우)
                {
                    temp->right->LLrotation();
                    temp->right->right->checkHeight();
                    temp->RRrotation();
                }
                temp->checkHeight(); // 높이 다시 조정
            }
        }
    };

    template <typename T1, typename T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y) { return (ft::pair<T1, T2>(x, y)); }

    template <typename Key, typename T, typename Compare>
    class MapConstIterator;

    // class map_iterator
    template <typename Key, typename T, typename Compare>
    class MapIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
        public:
            MapIterator() { ptr = 0; }

            ~MapIterator() { }

            MapIterator(const MapIterator &src) : ptr(src.ptr) { }

            MapIterator &operator=(const MapIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            explicit MapIterator(ft::tree<Key, T, Compare> *p) : ptr(p) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            bool operator==(const MapIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapConstIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapConstIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapIterator operator++(int){	// i++;
                MapIterator<Key, T, Compare> temp = *this;

                if (ptr->right != 0)
                {
                    ptr = ptr->right;
                    if (ptr->left == 0)
                        return (temp);
                    while (1)
                    {
                        if (ptr->left != 0)
                            ptr = ptr->left;
                        else if (ptr->right != 0)
                            ptr = ptr->right;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->left == p)
                            break ;
                    }
                }
                return (temp);
            }

            MapIterator &operator++(){		// ++i;
                if (ptr->right != 0)
                {
                    ptr = ptr->right;
                    if (ptr->left == 0)
                        return (*this);
                    while (1)
                    {
                        if (ptr->left != 0)
                            ptr = ptr->left;
                        else if (ptr->right != 0)
                            ptr = ptr->right;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->left == p)
                            break ;
                    }     
                }
				return (*this);
			}

			MapIterator operator--(int){	// i--;
				MapIterator<Key, T, Compare> temp = *this;

                if (ptr->left != 0)
                {
                    ptr = ptr->left;
                    if (ptr->right == 0)
                        return (temp);
                    while (1)
                    {
                        if (ptr->right != 0)
                            ptr = ptr->right;
                        else if (ptr->left != 0)
                            ptr = ptr->left;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        if (ptr->parent == 0)
                            break ;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->right == p)
                            break ;
                    }     
                }
				return (temp);
			}

			MapIterator &operator--(){		// --i;
                if (ptr->left != 0)
                {
                    ptr = ptr->left;
                    if (ptr->right == 0)
                        return (*this);
                    while (1)
                    {
                        if (ptr->right != 0)
                            ptr = ptr->right;
                        else if (ptr->left != 0)
                            ptr = ptr->left;
                        else
                            break ;
                    }
                }
                else
                {
                    ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        if (ptr->parent == 0)
                            break ;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->right == p)
                            break ;
                    }     
                }
				return (*this);
			}
    };

    // class map_const_iterator
    template <typename Key, typename T, typename Compare>
    class MapConstIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
        public:
            MapConstIterator() { ptr = 0; }

            ~MapConstIterator() { }

            MapConstIterator(const MapConstIterator &src) : ptr(src.ptr) { }

            MapConstIterator(const MapIterator<Key, T, Compare> &src) : ptr(src.getPtr()) { }  

            MapConstIterator &operator=(const MapConstIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            MapConstIterator &operator=(const MapIterator<Key, T, Compare> &src){
                ptr = src.getPtr();
                return (*this);
            }

            explicit MapConstIterator(ft::tree<Key, T, Compare> *p) : ptr(p) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            bool operator==(const MapConstIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapConstIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            const ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            const ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapConstIterator operator++(int){	// i++;
                MapConstIterator<Key, T, Compare> temp = *this;

                if (ptr->right != 0)
                {
                    ptr = ptr->right;
                    if (ptr->left == 0)
                        return (temp);
                    while (1)
                    {
                        if (ptr->left != 0)
                            ptr = ptr->left;
                        else if (ptr->right != 0)
                            ptr = ptr->right;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->left == p)
                            break ;
                    }     
                }
                return (temp);
            }

            MapConstIterator &operator++(){		// ++i;
                if (ptr->right != 0)
                {
                    ptr = ptr->right;
                    if (ptr->left == 0)
                        return (*this);
                    while (1)
                    {
                        if (ptr->left != 0)
                            ptr = ptr->left;
                        else if (ptr->right != 0)
                            ptr = ptr->right;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->left == p)
                            break ;
                    }     
                }
				return (*this);
			}

			MapConstIterator operator--(int){	// i--;
				MapConstIterator<Key, T, Compare> temp = *this;

                if (ptr->left != 0)
                {
                    ptr = ptr->left;
                    if (ptr->right == 0)
                        return (temp);
                    while (1)
                    {
                        if (ptr->right != 0)
                            ptr = ptr->right;
                        else if (ptr->left != 0)
                            ptr = ptr->left;
                        else
                            break ;
                    }
                }
                else
                {
                     ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        if (ptr->parent == 0)
                            break ;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->right == p)
                            break ;
                    }     
                }
				return (temp);
			}

			MapConstIterator &operator--(){		// --i;
                if (ptr->left != 0)
                {
                    ptr = ptr->left;
                    if (ptr->right == 0)
                        return (*this);
                    while (1)
                    {
                        if (ptr->right != 0)
                            ptr = ptr->right;
                        else if (ptr->left != 0)
                            ptr = ptr->left;
                        else
                            break ;
                    }
                }
                else
                {
                    ft::tree<Key, T, Compare>    *p;

                    while (1)
                    {
                        p = ptr;
                        if (ptr->parent == 0)
                            break ;
                        ptr = ptr->parent;
                        if (ptr == 0)
                            break ;
                        else if (ptr->right == p)
                            break ;
                    }     
                }
				return (*this);
			}
    };











    // class map
    template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
    class map{
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            class value_compare{
                friend class map;   // check-----------------!!!!!!!!!!!!!!!
                protected:
                    Compare comp;
                    value_compare(Compare c) : comp(c) { }
                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator()(const value_type &x, const value_type &y) const { return (comp(x.first, y.first)); }
            };
            typedef std::allocator<value_type> allocator_type;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef value_type* pointer;
            typedef const value_type* const_pointer;
            typedef MapIterator<Key, T, Compare> iterator;
            typedef MapConstIterator<Key, T, Compare> const_iterator;
            // typedef MapReverseIterator<T> reverse_iterator;
            // typedef MapReverseConstIterator<T> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        // private: // 테스트 중
        public:
            ft::tree<Key, T, Compare> *root;
            size_type _size;
        public:
            // empty constructor
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                (void)comp;
                (void)alloc;
                root = 0;
                _size = 0;
            }
            
            // destructor
            ~map(){
                clear();
            }

            // range constructor
            template <typename InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                (void)comp;
                (void)alloc;
                insert(first, last);
            }

            // copy constructor
            map(const map &x){
                root = 0;
                _size = 0;
                insert(x.begin(), x.end());
            }
            
            // assign content
            map &operator=(const map &x){
                clear();
                insert(x.begin(), x.end());
                return (*this);
            }

            // [Iterators]
            iterator begin(){
                ft::tree<Key, T, Compare> *temp = root;

                if (temp == 0)
                    return (iterator(temp));
                while (1)
                {
                    if (temp->left != 0)
                        temp = temp->left;
                    else
                        break ;
                }
                return (iterator(temp));
            }

            const_iterator begin() const{
                ft::tree<Key, T, Compare> *temp = root;

                if (temp == 0)
                    return (iterator(temp));
                while (1)
                {
                    if (temp->left != 0)
                        temp = temp->left;
                    else
                        break ;
                }
                return (const_iterator(temp));
            }

            iterator end(){
                ft::tree<Key, T, Compare> *temp = root;

                if (temp == 0)
                    return (iterator(temp));
                while (1)
                {
                    if (temp->right != 0)
                        temp = temp->right;
                    else
                        break ;
                }
                return (iterator(temp->right));
            }

            const_iterator end() const{
                ft::tree<Key, T, Compare> *temp = root;

                if (temp == 0)
                    return (iterator(temp));
                while (1)
                {
                    if (temp->right != 0)
                        temp = temp->right;
                    else
                        break ;
                }
                return (const_iterator(temp->right));
            }

            // reverse_iterator rbegin() { }
            // const_reverse_iterator rbegin() const { }
            // reverse_iterator rend() { }
            // const_reverse_iterator rend() const { }

            // [Capacity]
            bool empty() const { return (_size == 0); }

            size_type size() const { return (_size); }

            size_type max_size() const{
                return (std::min((size_type)std::numeric_limits<difference_type>::max(),
                                std::numeric_limits<size_type>::max() / sizeof(ft::tree<Key, T, Compare>)));
            }

            // [Element access]
            mapped_type &operator[](const key_type &k){
                return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
            }

            // [Modifiers]
            // single element insert
            ft::pair<iterator, bool> insert(const value_type &val){
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *new_node;
                ft::pair<iterator, bool> ret;
                key_compare cmp;

                if (find(val.first) != end())
                {
                    ret.first = find(val.first);
                    ret.second = false;
                    return (ret);
                }
                new_node = new ft::tree<Key, T, Compare>(val);
                if (root == 0)
                    root = new_node;
                else
                {
                    while (1)   // 들어갈 위치 찾기
                    {
                        if (cmp(temp->val.first, val.first) == true)
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
                    if (cmp(temp->val.first, val.first) == true)
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
                ret.first = find(val.first);
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
                erase(position.getPtr()->val.first);
            }

            size_type erase(const key_type &k){
                iterator    it = find(k);
                ft::tree<Key, T, Compare>   *temp;

                if (it == end())
                    return (0);
                temp = it.getPtr();
                // 자식노드가 없는 경우 case1
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
                        while (root->parent != 0)   // 루트 혹시나 옴겨졌는지 확인
                            root = root->parent;
                    }
                    delete temp;
                }
                // 자식노드(왼쪽) 하나만 있는 경우 case2
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
                        while (root->parent != 0)   // 루트 혹시나 옴겨졌는지 확인
                            root = root->parent;
                    }
                    delete temp;
                }
                // 자식노드(오른쪽) 하나만 있는 경우 case2
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
                        while (root->parent != 0)   // 루트 혹시나 옴겨졌는지 확인
                            root = root->parent;
                    }
                    delete temp;
                }
                // 자식노드가 두개 있는 경우 case3
                else
                {
                    ft::tree<Key, T, Compare>   *temp_next;
                    ft::tree<Key, T, Compare>   *test;
                    
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
                    delete temp;
                }
                _size--;
                return (1);
            }

            void erase(iterator first, iterator last)
            {
                while (first != last)
                    erase(first++);
            }

            void swap(map &x){
                ft::tree<Key, T, Compare> *r = root;
                size_type s = _size;

                root = x.root;
                _size = x._size;

                x.root = r;
                x._size = s;
            }

            void clear(){
                iterator    i = begin();
                iterator    temp;

                while (i != end()){
                    temp = i;
                    i++;
                    delete temp.getPtr();
                }
                root = 0;
                _size = 0;
            }

            // [Observers]
            key_compare key_comp() const { return (key_compare()); }

            value_compare value_comp() const { return (value_compare(key_compare())); }

            // [Operations]
            iterator find(const key_type &k){
                ft::tree<Key, T, Compare>   *temp = root;
                Compare cmp;

                while (temp != 0)
                {
                    if (temp->val.first == k)
                        break ;
                    if (cmp(temp->val.first, k) == true)
                        temp = temp->right;
                    else
                        temp = temp->left;
                }
                if (temp == 0)
                    return (end());
                return (iterator(temp));
            }

            const_iterator find(const key_type &k) const{
                ft::tree<Key, T, Compare>   *temp = root;
                Compare cmp;

                while (temp != 0)
                {
                    if (temp->val.first == k)
                        break ;
                    if (cmp(temp->val.first, k) == true)
                        temp = temp->right;
                    else
                        temp = temp->left;
                }
                if (temp == 0)
                    return (end());
                return (const_iterator(temp));
            }

            size_type count(const key_type &k) const{
                if (find(k) != end())
                    return (1);
                return (0);
            }

    };
}

#endif

#include <map>

void test(){
    ft::map<int, int> a;
    ft::map<int, int>::iterator it;
    ft::pair<ft::map<int, int>::iterator, bool> ww;

    //a.insert(std::pair<int, int>(1,2));
    //a.insert(std::pair<int, int>(2,2));
    ww = a.insert(ft::pair<int, int>(3, 211));
    ww = a.insert(ft::pair<int, int>(3, 111));
    std::cout << ww.first->first << " vs " << ww.first->second << std::endl;
    if (ww.second == true)
        std::cout << "this is true" << std::endl;
    else
        std::cout << "this is false" << std::endl;
    //a.insert(std::pair<int, int>(4,2));
    //a.insert(std::pair<int, int>(5,2));

    it = a.begin();
    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
    
    a[3] = 1234;
    it = a.begin();

    std::cout << it->first << std::endl;
    std::cout << it->second << std::endl;
}

void test2(){
    ft::map<int, int> a, b;
    ft::map<int, int>::iterator it;

    a.insert(ft::pair<int, int>(4,4));
    a.insert(ft::pair<int, int>(1,1));
    a.insert(ft::pair<int, int>(7,7));

    ft::map<int, int> c(a);;

 //   it = a.begin();
   // a.insert(a.begin(), std::pair<int, int>(5, 5));

    b.insert(a.begin(), a.end());

    it = c.begin();
    while (it != c.end())
    {
        std::cout << it->first << ", " << it->second << std::endl;
        it++;
    }

   
}

void test3()
{
    ft::map<int, int> a;
    ft::pair<int, int> p;

    p = ft::make_pair(1, 2);
    a.insert(p);
    p = ft::make_pair(2, 2);
    a.insert(p);
    p = ft::make_pair(3, 2);
    a.insert(p);
    p = ft::make_pair(4, 2);
    a.insert(p);

    size_t n = a.erase(4);

    std::cout << n << std::endl;

}

void test4()
{
    ft::map<int, int> a;
    ft::map<int, int>::iterator it;
    ft::pair<int, int> p;


    p = ft::make_pair(1, 2);
    a.insert(p);
    p = ft::make_pair(2, 4);
    a.insert(p);
    it = a.begin();
    it--;
    it--;
    it--;
    it--;
    it--;
    it--;

    std::cout << it->first << " vss " << it->second << std::endl;
}

void test5()
{
   std::map<char,int> mymap;
   std::map<char, int> m;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

    m = mymap;

    if (m <= mymap)
        std::cout << "same\n";

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

}

int main(void)
{
    test5();
    return (0);

    ft::map<int, int> a;

    ft::pair<int, int> data(1, 1);
    ft::pair<int, int> data2(12, 12);
    ft::pair<int, int> data3(3, 3);
    ft::pair<int, int> data4(14, 14);
    ft::pair<int, int> data5(5, 5);
    ft::pair<int, int> data6(16, 16);
    ft::pair<int, int> data7(7, 7);
    ft::pair<int, int> data8(18, 18);
    ft::pair<int, int> data9(9, 9);
    ft::pair<int, int> data10(20, 20);
    ft::pair<int, int> data11(11, 11);


    a.insert(data7);
    a.insert(data);
    a.insert(data8);
    a.insert(data11);
    a.insert(data10);
    a.insert(data4);
    a.insert(data5);
    a.insert(data6);
    a.insert(data2);
    a.insert(data9);
    a.insert(data3);

    a.erase(11);

    std::cout << "\n\n\n";
    ft::map<int, int>::iterator i;

    // i = a.find(5);

    // std::cout << i->first << std::endl;
    // if (i.getPtr()->right == 0)
    //     std::cout << "Ok\n";

    i = a.begin();

    if (a.value_comp()(*i, ft::pair<int, int>(19, 2)))
        std::cout << "Ok\n";

    while (i != a.end())
    {
        std::cout << i->first << ", " << i->second << std::endl;
        i++;
    }

    std::cout << a.root->val.first << " vs ";
    std::cout << a.root->val.second << " h = " << a.root->h << std::endl;

    std::cout << a.root->left->val.first << " vs ";
    std::cout << a.root->left->val.second << " h = " << a.root->left->h << std::endl;

    std::cout << a.root->right->val.first << " vs ";
    std::cout << a.root->right->val.second << " h = " << a.root->right->h << std::endl;

    // std::cout << a.root->right->left->val.first << " vs ";
    // std::cout << a.root->right->left->val.second << " h = " << a.root->right->left->h << std::endl;

    // std::cout << a.root->right->right->val.first << " vs ";
    // std::cout << a.root->right->right->val.second << " h = " << a.root->right->right->h << std::endl;

    // std::cout << a.root->left->left->val.first << " vs ";
    // std::cout << a.root->left->left->val.second << " h = " << a.root->left->left->h << std::endl;

    // std::cout << a.root->right->left->val.first << " vs ";
    // std::cout << a.root->right->left->val.second << " h = " << a.root->right->left->h << std::endl;

    // std::cout << a.root->right->right->val.first << " vs ";
    // std::cout << a.root->right->right->val.second << " h = " << a.root->right->right->h << std::endl;

    // std::cout << a.root->right->right->val.first << " vs ";
    // std::cout << a.root->right->right->val.second << " h = " << a.root->right->right->h << std::endl;

    // std::cout << a.root->left->val.first << " vs ";
    // std::cout << a.root->left->val.second << " h = " << a.root->left->h << std::endl;

    return (0);
}
