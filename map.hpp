#ifndef MAP_HPP

# define MAP_HPP

#include <iostream>
#include <limits>

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
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) { }

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

    // function template make_pair
    template <typename T1, typename T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y) { return (ft::pair<T1, T2>(x, y)); }

    // struct tree
    template<typename Key, typename T, typename Compare>
    struct tree{
        ft::pair<const Key, T> val;
        tree *parent;
        tree *left;
        tree *right;
        int h;

        tree(ft::pair<const Key, T> value) : val(value), parent(0), left(0), right(0), h(0) { }

        ft::tree<Key, T, Compare> *front(){
            ft::tree<Key, T, Compare>   *temp = this;

            while (temp != 0 && temp->left != 0)
                temp = temp->left;
            return (temp);
        }

        ft::tree<Key, T, Compare> *back(){
            ft::tree<Key, T, Compare>   *temp = this;

            while (temp != 0 && temp->right != 0)
                temp = temp->right;
            return (temp);
        }

        ft::tree<Key, T, Compare> *prev(){
            ft::tree<Key, T, Compare>   *ptr = this;

            if (ptr->left != 0)
            {
                ptr = ptr->left;
                if (ptr->right == 0)
                    return (ptr);
                while (1)
                {
                    if (ptr->right != 0)
                        ptr = ptr->right;
                    else
                        break ;
                }
            }
            else
            {
                ft::tree<Key, T, Compare>    *temp;

                while (1)
                {
                    temp = ptr;
                    ptr = ptr->parent;
                    if (ptr == 0)
                        break ;
                    else if (ptr->right == temp)
                        break ;
                }     
            }
            return (ptr);
        }

        ft::tree<Key, T, Compare> *next(){
            ft::tree<Key, T, Compare>   *ptr = this;

            if (ptr->right != 0) 
            {
                ptr = ptr->right;
                if (ptr->left == 0)
                    return (ptr);
                while (1)
                {
                    if (ptr->left != 0)
                        ptr = ptr->left;
                    else
                        break ;
                }
            }
            else
            {
                ft::tree<Key, T, Compare>    *temp;

                while (1)
                {
                    temp = ptr;
                    ptr = ptr->parent;
                    if (ptr == 0)
                        break ;
                    else if (ptr->left == temp)
                        break ;
                }
            }
            return (ptr);
        }

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
            while (temp != 0)   // bf check
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

                if (h1 > 1 && h2 > 0) // LLrotation(3, 2, 1)
                {
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 < 0) // RRrotation(1, 2, 3)
                {
                    temp->RRrotation();
                }
                else if (h1 > 1 && h2 < 0) // LRrotation(3, 1, 2)
                {
                    temp->left->RRrotation();
                    temp->left->left->checkHeight(); // before : temp->left - RRrotation - after : temp->left->left
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 > 0) // RLrotation(1, 3, 2)
                {
                    temp->right->LLrotation();
                    temp->right->right->checkHeight();
                    temp->RRrotation();
                }
                temp->checkHeight();
            }
        }
    };

    template <typename Key, typename T, typename Compare>
    class MapConstIterator;

    // class map_iterator
    template <typename Key, typename T, typename Compare>
    class MapIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
            ft::tree<Key, T, Compare> *root;
            ft::tree<Key, T, Compare> *leaf;
        public:
            MapIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~MapIterator() { }

            MapIterator(const MapIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            MapIterator &operator=(const MapIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            explicit MapIterator(ft::tree<Key, T, Compare> *p, ft::tree<Key, T, Compare> *r = 0, ft::tree<Key, T, Compare> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            ft::tree<Key, T, Compare> *getRoot() const { return (root); }

            ft::tree<Key, T, Compare> *getLeaf() const { return (leaf); }

            bool operator==(const MapIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapConstIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapConstIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapIterator operator++(int){	// i++;
                MapIterator<Key, T, Compare>    temp = *this;

                if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
                return (temp);
            }

            MapIterator &operator++(){		// ++i;
                if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
				return (*this);
			}

			MapIterator operator--(int){	// i--;
				MapIterator<Key, T, Compare>    temp = *this;

                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (temp);
			}

			MapIterator &operator--(){		// --i;
                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (*this);
			}
    };

    // class map_const_iterator
    template <typename Key, typename T, typename Compare>
    class MapConstIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
            ft::tree<Key, T, Compare> *root;
            ft::tree<Key, T, Compare> *leaf;
        public:
            MapConstIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~MapConstIterator() { }

            MapConstIterator(const MapConstIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            MapConstIterator(const MapIterator<Key, T, Compare> &src) : ptr(src.getPtr()), root(src.getRoot()), leaf(src.getLeaf()) { }  

            MapConstIterator &operator=(const MapConstIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            MapConstIterator &operator=(const MapIterator<Key, T, Compare> &src){
                ptr = src.getPtr();
                root = src.getRoot();
                leaf = src.getLeaf();
                return (*this);
            }

            explicit MapConstIterator(ft::tree<Key, T, Compare> *p, ft::tree<Key, T, Compare> *r = 0, ft::tree<Key, T, Compare> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            ft::tree<Key, T, Compare> *getRoot() const { return (root); }

            ft::tree<Key, T, Compare> *getLeaf() const { return (leaf); }

            bool operator==(const MapConstIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapConstIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            const ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            const ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapConstIterator operator++(int){	// i++;
                MapConstIterator<Key, T, Compare>   temp = *this;

                if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
                return (temp);
            }

            MapConstIterator &operator++(){		// ++i;
                if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
				return (*this);
			}

			MapConstIterator operator--(int){	// i--;
				MapConstIterator<Key, T, Compare>   temp = *this;

                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
                return (temp);
			}

			MapConstIterator &operator--(){		// --i;
                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (*this);
			}
    };

    template <typename Key, typename T, typename Compare>
    class MapConstReverseIterator;

    // class map_reverse_iterator
    template <typename Key, typename T, typename Compare>
    class MapReverseIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
            ft::tree<Key, T, Compare> *root;
            ft::tree<Key, T, Compare> *leaf;
        public:
            MapReverseIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~MapReverseIterator() { }

            explicit MapReverseIterator(MapIterator<Key, T, Compare> it){
                ptr = it.getPtr();
                root = it.getRoot();
                leaf = it.getLeaf();
                if (root == 0)
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
                if (ptr == 0)
                    ptr = leaf;
            }

            MapReverseIterator(const MapReverseIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            MapReverseIterator &operator=(const MapReverseIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            explicit MapReverseIterator(ft::tree<Key, T, Compare> *p, ft::tree<Key, T, Compare> *r = 0, ft::tree<Key, T, Compare> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            ft::tree<Key, T, Compare> *getRoot() const { return (root); }

            ft::tree<Key, T, Compare> *getLeaf() const { return (leaf); }

            MapIterator<Key, T, Compare> base(){
                ft::tree<Key, T, Compare> *temp = ptr;

                if (temp == leaf)
                    temp = root->front();
                else
                    temp = ptr->next();
                return (MapIterator<Key, T, Compare>(temp));
            }

            bool operator==(const MapReverseIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapConstReverseIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapReverseIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapConstReverseIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapReverseIterator operator++(int){     // i++;
                MapReverseIterator<Key, T, Compare>    temp = *this;
                
                if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
                return (temp);
            }

            MapReverseIterator &operator++(){		// ++i;
                if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
				return (*this);
			}

			MapReverseIterator operator--(int){	    // i--;
				MapReverseIterator<Key, T, Compare>    temp = *this;

                if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (temp);
			}

			MapReverseIterator &operator--(){		// --i;
                if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (*this);
			}
    };

    // class map_reverse_const_iterator
    template <typename Key, typename T, typename Compare>
    class MapConstReverseIterator{
        private:
            ft::tree<Key, T, Compare> *ptr;
            ft::tree<Key, T, Compare> *root;
            ft::tree<Key, T, Compare> *leaf;
        public:
            MapConstReverseIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~MapConstReverseIterator() { }

            explicit MapConstReverseIterator(MapConstIterator<Key, T, Compare> it){
                ptr = it.getPtr();
                root = it.getRoot();
                leaf = it.getLeaf();
                if (root == 0)
                    ptr = leaf;
                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
                if (ptr == 0)
                    ptr = leaf;
            }

            MapConstReverseIterator(const MapConstReverseIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            MapConstReverseIterator(const MapReverseIterator<Key, T, Compare> &src) : ptr(src.getPtr()), root(src.getRoot()), leaf(src.getLeaf()) { }

            MapConstReverseIterator &operator=(const MapConstReverseIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            MapConstReverseIterator &operator=(const MapReverseIterator<Key, T, Compare> &src){
                ptr = src.getPtr();
                root = src.getRoot();
                leaf = src.getLeaf();
                return (*this);
            }

            explicit MapConstReverseIterator(ft::tree<Key, T, Compare> *p, ft::tree<Key, T, Compare> *r = 0, ft::tree<Key, T, Compare> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<Key, T, Compare> *getPtr() const { return (ptr); }

            ft::tree<Key, T, Compare> *getRoot() const { return (root); }

            ft::tree<Key, T, Compare> *getLeaf() const { return (leaf); }

            MapConstIterator<Key, T, Compare> base(){
                ft::tree<Key, T, Compare> *temp = ptr;

                if (temp == leaf)
                    temp = root->front();
                else
                    temp = ptr->next();
                return (MapConstIterator<Key, T, Compare>(temp));
            }

            bool operator==(const MapConstReverseIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const MapReverseIterator<Key, T, Compare> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const MapConstReverseIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const MapReverseIterator<Key, T, Compare> &src) const { return (ptr != src.getPtr()); }

            const ft::pair<const Key, T> &operator*() const { return (ptr->val); }

            const ft::pair<const Key, T> *operator->() const { return (&ptr->val); }

            MapConstReverseIterator operator++(int){    // i++;
                MapConstReverseIterator<Key, T, Compare>    temp = *this;

                if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
                return (temp);
            }

            MapConstReverseIterator &operator++(){		// ++i;
                if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
				return (*this);
			}

			MapConstReverseIterator operator--(int){    // i--;
				MapConstReverseIterator<Key, T, Compare>    temp = *this;

                if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (temp);
			}

			MapConstReverseIterator &operator--(){      // --i;
                if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
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
                friend class map;
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
            typedef MapReverseIterator<Key, T, Compare> reverse_iterator;
            typedef MapConstReverseIterator<Key, T, Compare> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            ft::tree<Key, T, Compare> *root;
            ft::tree<Key, T, Compare> *leaf;
            size_type _size;
        public:
            // empty constructor
            explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                (void)comp;
                (void)alloc;
                root = 0;
                leaf = new ft::tree<Key, T, Compare>(value_type());
                _size = 0;
            }
            
            // destructor
            ~map(){
                clear();
                delete leaf;
            }

            // range constructor
            template <typename InputIterator>
            map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()){
                (void)comp;
                (void)alloc;
                root = 0;
                leaf = new ft::tree<Key, T, Compare>(value_type());
                _size = 0;
                insert(first, last);
            }

            // copy constructor
            map(const map &x){
                root = 0;
                leaf = new ft::tree<Key, T, Compare>(value_type());
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
                                std::numeric_limits<size_type>::max() / sizeof(ft::tree<Key, T, Compare>)));
            }

            // [Element access]
            mapped_type &operator[](const key_type &k){
                return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
            }

            // [Modifiers]
            // single element insert
            pair<iterator, bool> insert(const value_type &val){
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *new_node;
                ft::pair<iterator, bool>    ret;
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
                    while (1) // 들어갈 위치 찾기
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
                erase(position->first);
            }

            size_type erase(const key_type &k){
                iterator    it = find(k);
                ft::tree<Key, T, Compare>   *temp;

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
                    delete temp;
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
                    delete temp;
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
                    delete temp;
                }
                // 자식노드가 둘 다 있는 경우
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
                    erase(temp);
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
                return (iterator(temp, root, leaf));
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
                return (const_iterator(temp, root, leaf));
            }

            size_type count(const key_type &k) const{
                if (find(k) != end())
                    return (1);
                return (0);
            }

            iterator lower_bound(const key_type &k){
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(temp->val.first, k) == true)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val.first));
            }

            const_iterator lower_bound(const key_type &k) const{
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(temp->val.first, k) == true)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val.first));
            }

            iterator upper_bound(const key_type &k){
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(k, temp->val.first) == false)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val.first));
            }

            const_iterator upper_bound(const key_type &k) const{
                ft::tree<Key, T, Compare>   *temp = root;
                ft::tree<Key, T, Compare>   *ret = 0;
                key_compare cmp = key_comp();

                while (temp != 0)
                {
                    if (cmp(k, temp->val.first) == false)
                        temp = temp->right;
                    else
                    {
                        ret = temp;
                        temp = temp->left;
                    }
                }
                if (ret == 0)
                    return (end());
                return (find(ret->val.first));
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
	template <typename Key, typename T, typename Compare, typename Alloc>
    bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
        typename ft::map<Key, T>::const_iterator left = lhs.begin();
        typename ft::map<Key, T>::const_iterator right = rhs.begin();

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

    template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (!(lhs == rhs)); }
	
	template <typename Key, typename T, typename Compare, typename Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
	{
        typename ft::map<Key, T>::const_iterator left = lhs.begin();
        typename ft::map<Key, T>::const_iterator right = rhs.begin();

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
	
	template <typename Key, typename T, typename Compare, typename Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (!(rhs < lhs)); }

	template <typename Key, typename T, typename Compare, typename Alloc>
    bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (rhs < lhs); }

	template <typename Key, typename T, typename Compare, typename Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs) { return (!(lhs < rhs)); }

	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) { x.swap(y); }
}

#endif
