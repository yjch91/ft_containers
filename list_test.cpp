#include <iostream>
#include <limits>
#include <list>
#include "utils.hpp"
#include <cmath>

namespace ft{

    template <typename T>
    struct Node
    {
        T   val;
        bool is_node;
        Node    *prev;
        Node    *next;

        Node() { is_node = false; }
    };
    
    template <typename T>
    class ListConstIterator;

    // class list_iterator
    template <typename T>
    class ListIterator{
        private:
            ft::Node<T> *ptr;
        public:
            ListIterator() { ptr = 0; }

            ~ListIterator() { }

            ListIterator(const ListIterator &src) : ptr(src.ptr) { }

            ListIterator    &operator=(const ListIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            explicit ListIterator(ft::Node<T> *p) : ptr(p) { }

            ft::Node<T> *getPtr() const { return (ptr); }

            bool    operator==(const ListIterator &src) { return (ptr == src.ptr); }
            bool    operator==(const ListConstIterator<T> &src) { return (ptr == src.getPtr()); }

            bool    operator!=(const ListIterator &src) { return (ptr != src.ptr); }
            bool    operator!=(const ListConstIterator<T> &src) { return (ptr != src.getPtr()); }

            T   &operator*() { return (ptr->val); }

            T   *operator->() { return (&ptr->val); }

            ListIterator	operator++(int){	// i++;
                ListIterator<T> temp = *this;
                ptr = ptr->next;
                return (temp);
            }

            ListIterator	operator++(){		// ++i;
				ptr = ptr->next;
				return (*this);
			}

			ListIterator	operator--(int){	// i--;
				ListIterator<T> temp = *this;
				ptr = ptr->prev;
				return (temp);
			}

			ListIterator	operator--(){		// --i;
				ptr = ptr->prev;
				return (*this);
			}
    };

    // class list_const_iterator
    template <typename T>
    class ListConstIterator{
        private:
            ft::Node<T> *ptr;
        public:
            ListConstIterator() { ptr = 0; }

            ~ListConstIterator() { }

            ListConstIterator(const ListConstIterator &src) : ptr(src.ptr) { }

            ListConstIterator(const ListIterator<T> &src) : ptr(src.getPtr()) { }

            ListConstIterator    &operator=(const ListConstIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            ListConstIterator    &operator=(const ListIterator<T> &src){
                ptr = src.getPtr();
                return (*this);
            }

            explicit ListConstIterator(ft::Node<T> *p) : ptr(p) { }

            ft::Node<T> *getPtr() const { return (ptr); }

            bool    operator==(const ListConstIterator &src) { return (ptr == src.ptr); }
            bool    operator==(const ListIterator<T> &src) { return (ptr == src.getPtr()); }

            bool    operator!=(const ListConstIterator &src) { return (ptr != src.ptr); }
            bool    operator!=(const ListIterator<T> &src) { return (ptr != src.getPtr()); }

            const T &operator*() { return (ptr->val); }

            const T *operator->() { return (&ptr->val); }

            ListConstIterator	operator++(int){	// i++;
                ListConstIterator<T> temp = *this;
                ptr = ptr->next;
                return (temp);
            }

			ListConstIterator	operator++(){		// ++i;
				ptr = ptr->next;
				return (*this);
			}

			ListConstIterator	operator--(int){	// i--;
				ListIterator<T> temp = *this;
				ptr = ptr->prev;
				return (temp);
			}

			ListConstIterator	operator--(){		// --i;
				ptr = ptr->prev;
				return (*this);
			}
    };

    template <typename T>
    class ListReverseConstIterator;

    // class list_reverse_iterator
    template <typename T>
    class ListReverseIterator{
        private:
            ft::Node<T> *ptr;
        public:
            ListReverseIterator() { ptr = 0; }

            ~ListReverseIterator() { }

            explicit ListReverseIterator(ListIterator<T> it){
				ptr = it.getPtr();
				ptr = ptr->prev;
			}

            ListReverseIterator(const ListReverseIterator &src) : ptr(src.ptr) { }

            ListReverseIterator    &operator=(const ListReverseIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            explicit ListReverseIterator(ft::Node<T> *p) : ptr(p) { }

            ft::Node<T> *getPtr() const { return (ptr); }

            ListIterator<T>	base() { return (ListIterator<T>(ptr->next)); }

            bool    operator==(const ListReverseIterator &src) { return (ptr == src.ptr); }
            bool    operator==(const ListReverseConstIterator<T> &src) { return (ptr == src.getPtr()); }

            bool    operator!=(const ListReverseIterator &src) { return (ptr != src.ptr); }
            bool    operator!=(const ListReverseConstIterator<T> &src) { return (ptr != src.getPtr()); }

            T   &operator*() { return (ptr->val); }

            T   *operator->() { return (&ptr->val); }

            ListReverseIterator	operator++(int){	// i++;
                ListReverseIterator<T> temp = *this;
                ptr = ptr->prev;
                return (temp);
            }

			ListReverseIterator	operator++(){		// ++i;
				ptr = ptr->prev;
				return (*this);
			}

			ListReverseIterator	operator--(int){	// i--;
				ListReverseIterator<T> temp = *this;
				ptr = ptr->next;
				return (temp);
			}

			ListReverseIterator	operator--(){		// --i;
				ptr = ptr->next;
				return (*this);
			}
    };

    // class list_reverse_const_iterator
    template <typename T>
    class ListReverseConstIterator{
        private:
            ft::Node<T> *ptr;
        public:
            ListReverseConstIterator() { ptr = 0; }

            ~ListReverseConstIterator() { }

            explicit ListReverseConstIterator(ListConstIterator<T> it){
				ptr = it.getPtr();
				ptr = ptr->prev;
			}

            ListReverseConstIterator(const ListReverseConstIterator &src) : ptr(src.ptr) { }

            ListReverseConstIterator(const ListReverseIterator<T> &src) : ptr(src.getPtr()) { }

            ListReverseConstIterator    &operator=(const ListReverseConstIterator &src){
                ptr = src.ptr;
                return (*this);
            }

            ListReverseConstIterator    &operator=(const ListReverseIterator<T> &src){
                ptr = src.getPtr();
                return (*this);
            }

            explicit ListReverseConstIterator(ft::Node<T> *p) : ptr(p) { }

            ft::Node<T> *getPtr() const { return (ptr); }

            ListConstIterator<T>	base() { return (ListConstIterator<T>(ptr->next)); }

            bool    operator==(const ListReverseConstIterator &src) { return (ptr == src.ptr); }
            bool    operator==(const ListReverseIterator<T> &src) { return (ptr == src.getPtr()); }

            bool    operator!=(const ListReverseConstIterator &src) { return (ptr != src.ptr); }
            bool    operator!=(const ListReverseIterator<T> &src) { return (ptr != src.getPtr()); }

            const T &operator*() { return (ptr->val); }

            const T *operator->() { return (&ptr->val); }

            ListReverseConstIterator	operator++(int){	// i++;
                ListReverseConstIterator<T> temp = *this;
                ptr = ptr->prev;
                return (temp);
            }

			ListReverseConstIterator	operator++(){		// ++i;
				ptr = ptr->prev;
				return (*this);
			}

			ListReverseConstIterator	operator--(int){	// i--;
				ListReverseConstIterator<T> temp = *this;
				ptr = ptr->next;
				return (temp);
			}

			ListReverseConstIterator	operator--(){		// --i;
				ptr = ptr->next;
				return (*this);
			}
    };

    template <typename T, typename Alloc = std::allocator<T> >
    class list{
        public:
            typedef T value_type;
            typedef std::allocator<T> allocator_type;
            typedef T& reference;
            typedef const T& const_reference;
            typedef T* pointer;
            typedef const T* const_pointer;
            typedef ListIterator<T> iterator;
            typedef ListConstIterator<T> const_iterator;
            typedef ListReverseIterator<T> reverse_iterator;
            typedef ListReverseConstIterator<T> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;

            class   PopException : public std::exception{
                public:
                    virtual const char  *what() const throw(){
                        return ("free(): invalid pointer"); // check plz!!!!!!!!!!!!!!
                    }
            };

            class   EraseException : public std::exception{
                public:
                    virtual const char  *what() const throw(){
                        return ("munmap_chunk(): invalid pointer"); // check plz!!!!!!!!!!!!!!
                    }
            };
            // lst lst2 있을 때 둘다 push_back하고 lst 지우는거 테스트해보고 lst2는 push_back 안하고 테스트해서
            // mummap_chunk랑 free 다른데 mac에서도 다른지 확인
        private:
            ft::Node<T> *node;
            size_type _size;

            void    nodeChange(ft::Node<T> *left, ft::Node<T> *right){
                ft::Node<T> *prev_backup = left->prev;

                left->prev = right;

                left->next = right->next;
                right->next->prev = left;
                                    
                right->prev = prev_backup;
                prev_backup->next = right;
                                    
                right->next = left;
            }
        public:
            // default constructor
            explicit list(const allocator_type &alloc = allocator_type()){
                (void)alloc;
                node = new ft::Node<T>;
                node->val = value_type();
                node->is_node = true;
                node->prev = node;
                node->next = node;
                _size = 0;
            }

            // destructor
            ~list(){
                ft::Node<T> *end_node = node;
                ft::Node<T> *temp = node->next;

                while (temp != end_node)
                {
                    node = temp->next;
                    delete temp;
                    temp = node;
                }
                delete temp;
            }

            // fill constructor
            explicit list(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
                (void)alloc;
                node = new ft::Node<T>;
                node->val = value_type();
                node->is_node = true;
                node->prev = node;
                node->next = node;
                _size = 0;
                for (size_type i = 0; i < n; i++)
                    push_back(val);
            }

            // range constructor
            template <class InputIterator>
            list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
                (void)alloc;
                (void)type;
                node = new ft::Node<T>;
                node->val = value_type();
                node->is_node = true;
                node->prev = node;
                node->next = node;
                _size = 0;
                while (first != last)
                    push_back(*first++);
            }

            // copy constructor
            list(const list &x){
                ft::Node<T> *temp = 0;

                node = new ft::Node<T>;
                node->val = value_type();
                node->is_node = true;
                node->prev = node;
                node->next = node;
                _size = 0;
                temp = x.node->next;
                while (temp != x.node)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
            }

            // Assign content
            list    &operator=(const list &x){
                ft::Node<T> *temp = 0;

                if (node != node->next)
                {
                    // ft::Node<T> *end_node = node;

                    // temp = node->next;
                    // while (temp != end_node)
                    // {
                    //     node = temp->next;
                    //     delete temp;
                    //     temp = node;
                    // }
                    // node->prev = node;
                    // node->next = node;
                    // _size = 0;
                    clear();
                }
                temp = x.node->next;
                while (temp != x.node)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
                return (*this);
            }

            // [Iterators]
            iterator    begin() { return (iterator(node->next)); }
            const_iterator  begin() const { return (const_iterator(node->next)); }

            iterator    end() { return (iterator(node)); }
            const_iterator  end() const { return (const_iterator(node)); }

            reverse_iterator rbegin() { return (reverse_iterator(node->prev)); }
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(node->prev)); }

            reverse_iterator rend() { return (reverse_iterator(node)); }
            const_reverse_iterator rend() const { return (const_reverse_iterator(node)); }

            // [Capacity]
            bool    empty() const { return (_size == 0); }

            size_type   size() const { return (_size); }

            size_type	max_size() const{
                return (std::min((size_type)std::numeric_limits<difference_type>::max(),
                            std::numeric_limits<size_type>::max() / sizeof(ft::Node<T>)));
            }

            // [Element access]
            reference   front() { return (node->next->val); }
            const_reference front() const { return (node->next->val); }

            reference back() { return (node->prev->val); }
            const_reference back() const { return (node->prev->val); }

            // [Modifiers]
            // range assign
            template <typename InputIterator>
            void assign (InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
                // ft::Node<T> *end_node = node;
                // ft::Node<T> *temp = node->next;

                // while (temp != end_node)
                // {
                //     node = temp->next;
                //     delete temp;
                //     temp = node;
                // }
                // node->prev = node;
                // node->next = node;
                // _size = 0;
                (void)type;
                clear();
                while (first != last)
                    push_back(*first++);
            }

            // fill assign
            void assign (size_type n, const value_type &val){
                // ft::Node<T> *end_node = node;
                // ft::Node<T> *temp = node->next;

                // while (temp != end_node)
                // {
                //     node = temp->next;
                //     delete temp;
                //     temp = node;
                // }
                // node->prev = node;
                // node->next = node;
                // _size = 0;
                clear();
                for (size_type i = 0; i < n; i++)
                    push_back(val);
            }

            void    push_front(const value_type &val){
                ft::Node<T> *new_node = new ft::Node<T>;

                new_node->val = val;
                node->next->prev = new_node;
                new_node->next = node->next;
                node->next = new_node;
                new_node->prev = node;
                _size++;
            }

            void    pop_front(){
                ft::Node<T> *temp = node->next;

                if (temp == node)
                    throw PopException();       // check plz!!!!!!!!!!!!!!!!
                node->next->next->prev = node;
                node->next = node->next->next;
                delete temp;
                _size--;
            }

            void    push_back(const value_type &val){
                ft::Node<T> *new_node = new ft::Node<T>;

                new_node->val = val;
                node->prev->next = new_node;
                new_node->prev = node->prev;
                node->prev = new_node;
                new_node->next = node;
                _size++;
            }

            void    pop_back(){
                ft::Node<T> *temp = node->prev;

                if (temp == node)
                    throw PopException();       // check plz!!!!!!!!!!!!!!!!
                node->prev->prev->next = node;
                node->prev = node->prev->prev;
                delete temp;
                _size--;
            }

            // single element insert
            iterator insert (iterator position, const value_type &val){
                ft::Node<T> *new_node = new ft::Node<T>;
                ft::Node<T> *pos = position.getPtr();

                new_node->val = val;
                pos->prev->next = new_node;
                new_node->prev = pos->prev;
                new_node->next = pos;
                pos->prev = new_node;
                _size++;
                return (iterator(new_node));
            }

            // fill insert
            void insert (iterator position, size_type n, const value_type &val){
                ft::Node<T> *left_node = 0;
                ft::Node<T> *right_node = 0;
                ft::Node<T> *pos = position.getPtr();

                for (size_type i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        left_node = new ft::Node<T>;
                        left_node->val = val;
                        left_node->prev = 0;
                        left_node->next = 0;
                        right_node = left_node;
                    }
                    else{
                        ft::Node<T> *new_node = new ft::Node<T>;

                        new_node->val = val;
                        right_node->next = new_node;
                        new_node->prev = right_node;
                        new_node->next = 0;
                        right_node = new_node;
                    }
                }
                if (left_node != 0 && right_node != 0)
                {
                    pos->prev->next = left_node;
                    left_node->prev = pos->prev;
                    right_node->next = pos;
                    pos->prev = right_node;
                }
                _size += n;
            }

            // range insert
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
                ft::Node<T> *left_node = 0;
                ft::Node<T> *right_node = 0;
                ft::Node<T> *pos = position.getPtr();
                size_type   n = 0;

                (void)type;
                for (InputIterator i = first; i != last; i++)
                {
                    if (i == first)
                    {
                        left_node = new ft::Node<T>;
                        left_node->val = *i;
                        left_node->prev = 0;
                        left_node->next = 0;
                        right_node = left_node;
                    }
                    else{
                        ft::Node<T> *new_node = new ft::Node<T>;

                        new_node->val = *i;
                        right_node->next = new_node;
                        new_node->prev = right_node;
                        new_node->next = 0;
                        right_node = new_node;
                    }
                    n++;
                }
                if (left_node != 0 && right_node != 0)
                {
                    pos->prev->next = left_node;
                    left_node->prev = pos->prev;
                    right_node->next = pos;
                    pos->prev = right_node;
                }
                _size += n;
            }

            iterator    erase(iterator position)
            {
                ft::Node<T> *pos = position.getPtr();
                ft::Node<T> *ret = pos->next;

                if (pos->is_node == true)
                    throw EraseException();     // check plz!!!!!!!!!!!!!!!!!!!
                pos->prev->next = pos->next;
                pos->next->prev = pos->prev;
                delete pos;
                _size--;
                return (iterator(ret));
            }

            iterator    erase(iterator first, iterator last)
            {
                ft::Node<T> *left = first.getPtr();
                ft::Node<T> *right = last.getPtr();
                ft::Node<T> *temp = 0;
   
                left->prev->next = right;
                right->prev = left->prev;
                temp = left;
                while (temp != right)
                {
                    if (temp->is_node == true)
                        throw EraseException();     // check plz!!!!!!!!!!!!!!!!!!!
                    left = left->next;
                    delete temp;
                    temp = left;
                    _size--;
                }
                return (iterator(right));
            }

            void    swap(list &x){
                size_type s = _size;
                ft::Node<T> *n = node;

                _size = x._size;
                node = x.node;

                x._size = s;
                x.node = n;
            }

            void    resize(size_type n, value_type val = value_type())
            {
                if (_size < n)
                {
                    while (_size < n)
                        push_back(val);
                }
                else if (_size > n)
                {
                    size_type count = 0;
                    ft::Node<T> *temp = node->next;
                    while (temp != node)
                    {
                        count++;
                        temp = temp->next;
                    }
                    // std::cout << "_size = " << _size << std::endl;
                    // std::cout << "n = " << n << std::endl;
                    // std::cout << "count = " << count << std::endl;
                    // std::cout << "\n\n";
                    if (_size - n <= count && n > count)
                    {
                        count = _size - n;
                        while (count--)
                            pop_back();
                    }
                    else
                    {
                        if (n > static_cast<size_type>(std::numeric_limits<difference_type>::max()))
                            count = (_size - n) % (count + 1);
                        else
                            count = count - (n % (count + 1));
                        while (count--)
                            pop_back();
                    }
                }
            }

            void    clear(){
                ft::Node<T> *end_node = node;
                ft::Node<T> *temp = node->next;

                while (temp != end_node)
                {
                    node = temp->next;
                    delete temp;
                    temp = node;
                }
                node->prev = node;
                node->next = node;
                _size = 0;
            }

            // [Operations]
            // entire list splice
            void    splice(iterator position, list &x){
                ft::Node<T> *left_node = x.node->next;
                ft::Node<T> *right_node = x.node->prev;
                ft::Node<T> *pos = position.getPtr();
                
                if (left_node == right_node && left_node == x.node)
                    return ;

                x.node->prev = x.node;
                x.node->next = x.node;
                
                pos->prev->next = left_node;
                left_node->prev = pos->prev;
                pos->prev = right_node;
                right_node->next = pos;
                _size += x._size;
                x._size = 0;
            }            

            // single element splice
            void    splice(iterator position, list &x, iterator i){
                ft::Node<T> *pos = position.getPtr();
                ft::Node<T> *i_pos = i.getPtr();

                i_pos->prev->next = i_pos->next;
                i_pos->next->prev = i_pos->prev;

                pos->prev->next = i_pos;
                i_pos->prev = pos->prev;
                pos->prev = i_pos;
                i_pos->next = pos;
                
                _size++;
                x._size--;
            }

            // element range splice
            void    splice(iterator position, list &x, iterator first, iterator last){
                ft::Node<T> *left_node = first.getPtr();
                ft::Node<T> *right_node = last.getPtr()->prev;
                ft::Node<T> *pos = position.getPtr();
                size_type   n = 0;
                
                if (first == last)
                    return ;

                for (; first != last; first++)
                    n++;

                left_node->prev->next = right_node->next;
                right_node->next->prev = left_node->prev;
                
                pos->prev->next = left_node;
                left_node->prev = pos->prev;
                pos->prev = right_node;
                right_node->next = pos;
                _size += n;
                x._size -= n;
            }

            void    remove(const value_type &val){
                iterator    i = begin();

                while (i != end())
                {
                    if (*i == val)
                        i = erase(i);
                    else
                        i++;
                }
            }

            template <typename Predicate>
            void    remove_if(Predicate pred){
                iterator    i = begin();

                while (i != end())
                {
                    if (pred(*i) == true)
                        i = erase(i);
                    else
                        i++;
                }
            }

            void    unique(){
                iterator    i = begin();

                i++;
                while (i != end())
                {
                    iterator    j = i;

                    j--;
                    if (*j == *i)
                        i = erase(i);
                    else
                        i++;
                }
            }

            template <class BinaryPredicate>
            void unique(BinaryPredicate binary_pred){
                iterator    i = begin();

                i++;
                while (i != end())
                {
                    iterator    j = i;

                    j--;
                    if (binary_pred(*j, *i) == true)
                        i = erase(i);
                    else
                        i++;
                }
            }

            void    merge(list &x){
                iterator    i;
                
                if (&x == this)
                    return ;
                i = begin();
                while (i != end())
                {
                    iterator    j = x.begin();

                    while (j != x.end())
                    {
                        if (*i > *j)
                        {
                            iterator    k = j;

                            k++;
                            splice(i, x, j);
                            j = k;
                        }
                        else if(*i < *j)
                            break ;
                        else
                            j++;
                    }
                    i++;
                }
                splice(end(), x);
            }

            template <typename Compare>
            void    merge(list &x, Compare comp){
                iterator    i;
                
                if (&x == this)
                    return ;
                i = begin();
                while (i != end())
                {
                    iterator    j = x.begin();

                    while (j != x.end())
                    {
                        if (comp(*j, *i) == true)
                        {
                            iterator    k = j;

                            k++;
                            splice(i, x, j);
                            j = k;
                        }
                        else if(*i < *j)
                            break ;
                        else
                            j++;
                    }
                    i++;
                }
                splice(end(), x);
            }

            void    sort(){
                iterator    i;
                iterator    j;
                size_type   n = 0;

                i = end();
                i--;
                if (i.getPtr()->prev == i.getPtr()->next)
                    return ;
                while (i != end())
                {
                    j = begin();
                    while (j != i)
                    {
                        iterator    j_next = j;

                        j_next++;
                        if (*j > *j_next)
                        {
                            nodeChange(j.getPtr(), j_next.getPtr());
                            if (j_next == i)
                                i = j;
                            j = j_next;
                        }
                        j++;
                    }
                    i--;
                    n++;
                }
                _size = n;
            }

            template <typename Compare>
            void    sort(Compare comp){
                iterator    i;
                iterator    j;
                size_type   n = 0;

                i = end();
                i--;
                if (i.getPtr()->prev == i.getPtr()->next)
                    return ;
                while (i != end())
                {
                    j = begin();
                    while (j != i)
                    {
                        iterator    j_next = j;

                        j_next++;
                        if (comp(*j_next, *j) == true)
                        {
                            nodeChange(j.getPtr(), j_next.getPtr());
                            if (j_next == i)
                                i = j;
                            j = j_next;
                        }
                        j++;
                    }
                    i--;
                    n++;
                }
                _size = n;
            }

            void    reverse(){
                iterator    i = begin();
                ft::Node<T> *p = 0;
                ft::Node<T> *temp = 0;

                while (i != end())
                {
                    p = i.getPtr();
                    i++;
                    temp = p->next;
                    p->next = p->prev;
                    p->prev = temp;
                }
                p = i.getPtr();
                temp = p->next;
                p->next = p->prev;
                p->prev = temp;
            }
            
            void    print()
            {
                Node<T> *end_node = node;
                Node<T> *temp = node->next;
                
                while (temp != end_node)
                {
                    std::cout << "val = " << temp->val << std::endl;
                    temp = temp->next;
                }
                std::cout << "end_node : " << end_node->val << std::endl;
            }
    };

    // [Non-member function overloads]
	template <typename T, typename Alloc>
    bool operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
        typename ft::list<T>::const_iterator left = lhs.begin();
        typename ft::list<T>::const_iterator right = rhs.begin();

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
	
	template <typename T, typename Alloc>
	bool operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) { return (!(lhs == rhs)); }
	
	template <typename T, typename Alloc>
	bool operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
	{
        typename ft::list<T>::const_iterator left = lhs.begin();
        typename ft::list<T>::const_iterator right = rhs.begin();

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
	
	template <typename T, typename Alloc>
    bool operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) { return (!(rhs < lhs)); }

	template <typename T, typename Alloc>
    bool operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) { return (rhs < lhs); }

	template <typename T, typename Alloc>
    bool operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) { return (!(lhs < rhs)); }

	template <typename T, typename Alloc>
	void swap(list<T, Alloc> &x, list<T, Alloc> &y) { x.swap(y); }

}



class	test{
	public:
		int x;
		test(int a = 0) { x = a; }
		~test() { }
};

#include "vector.hpp"
#include <vector>

void assign_test()
{
  ft::list<int> first;
  ft::list<int> second;

  second.push_back(111);
  second.push_back(1111);
  second.push_back(11111);


  first.assign(7,100);                      // 7 ints with value 100

  second.assign (first.begin(),first.end()); // a copy of first

    ft::list<int>::iterator it = second.begin();
    while (it != second.end())
        std::cout << *it++ << std::endl;

  int myints[]={1776,7,4};
  first.assign (myints,myints+3);            // assigning from array

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';

}

void    push_front_test()
{
     ft::list<int> mylist;         // two ints with a value of 100
mylist.push_front (100);
    mylist.push_front (100);
  mylist.push_front (200);
  mylist.push_front (300);

    // mylist.pop_back();
    // mylist.pop_back();
    // mylist.pop_back();
    // mylist.pop_back();
    // mylist.pop_back();

    mylist.pop_front();
    mylist.pop_front();
    mylist.pop_front();
    mylist.pop_front();
     //mylist.pop_front();
    //  mylist.pop_front();
    // mylist.pop_front();
    // mylist.pop_front();
    // mylist.pop_front();

    //exit(0);
    //mylist.pop_front();
    // mylist.pop_front();
    // mylist.pop_front();
//    mylist.pop_front();


    //exit(1);
    // mylist.pop_front();

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
   std::cout << ' ' << *it;

  std::cout << '\n';

}

void    insert_test()
{
    std::list<int> lst, lst2, lst3;
    std::list<int>::iterator a, b, c, d;
    std::vector<int> vec;

    for (int i = 1; i < 11; i++)
        vec.push_back(i * 100);

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    lst2.push_back(1111);
    lst2.push_back(2222);
    lst2.push_back(3333);

    a = lst.end();
    d = lst2.end();
    d++;
    // a++;
    // a++;

    b = lst.insert(d, 99);
    std::cout << "b = " << *b << std::endl;
    lst3.assign(5, 10);
    lst3 = lst2;
    a = lst2.begin();
    d = lst.begin();
    //ft::list<int>::iterator xy(e);
    //d++;
    //d++;
    b = lst2.erase(d);
    std::cout << "b = " << *b << std::endl;
    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;

    //lst2.insert(d, vec.begin() + 3, vec.begin() + 6);
    //lst2.insert(a, 7, 11);

    //std::cout << "lst size = " << lst.size() << std::endl;
    //std::cout << "lst2 size = " << lst2.size() << std::endl;

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << std::endl;
}

void    range_erase_test()
{
    std::list<int> lst, lst2, lst3;
    std::list<int>::iterator a, b, c, d;

    for (int i = 0; i < 2; i++)
        lst.push_back(i + 1);


    for (int i = 0; i < 120; i++)
        lst2.push_back(1111);
    lst2.push_back(2222);
    lst2.push_back(3333);
    lst2.push_back(4444);
    lst2.push_back(5555);
    lst2.push_back(6666);
    lst2.push_back(7777);

    c = lst.begin();
    for (int i = 0; i < 1; i++)
        c++;

    
    //b = lst.erase(lst.begin(), c);
    // c = lst2.begin();
    // c++;
    // c++;
    //b = lst.erase(c, lst2.end());

    std::cout << "lst size = " << lst.size() << std::endl;
    // std::cout << "lst2 size = " << lst2.size() << std::endl;
    
   lst.pop_back();
   lst.pop_back();
   lst.pop_back();


  // lst.resize(-123, 2222);
//    lst2.resize(0, 11100);

    std::cout << "lst size = " << lst.size() << std::endl;
    // std::cout << "lst2 size = " << lst2.size() << std::endl;

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    // for (c = lst2.begin(); c != lst2.end(); c++)
    //     std::cout << *c << std::endl;
}

void    swap_test()
{
    std::list<int> first (3,100);   // three ints with a value of 100
    std::list<int> second (5,200);  // five ints with a value of 200
    std::list<int>::iterator it;

    std::cout << "first size = " << first.size() << std::endl;
    std::cout << "second size = " << second.size() << std::endl;
    std::cout << "first contains:";
    for (it=first.begin(); it!=first.end(); it++)
        std::cout << ' ' << *it;
    std::cout << "\n";

    std::cout << "second contains:";
    for (it=second.begin(); it!=second.end(); it++)
        std::cout << ' ' << *it;
    std::cout << "\n";

    first.swap(second);

    std::cout << "first contains:";
    for (it=first.begin(); it!=first.end(); it++)
        std::cout << ' ' << *it;
    std::cout << "\n";

    std::cout << "second contains:";
    for (it=second.begin(); it!=second.end(); it++)
        std::cout << ' ' << *it;
    std::cout << "\n";
    
    std::cout << "first size = " << first.size() << std::endl;
    std::cout << "second size = " << second.size() << std::endl;
}

void    range_erase_test1()
{
    ft::list<int> lst;
    ft::list<int>::iterator a, b, c, d;

    lst.push_back(19);
    lst.push_back(119);
    lst.push_back(119);

    lst.push_back(119);



    b = lst.begin();

   // lst.pop_front();
    std::cout << *b << std::endl;
    //lst.pop_front();

   //lst.pop_front();

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";

//    b = lst.begin();
    // std::cout << "b = " << *b << std::endl;
    // b = lst.erase(lst.begin());
    // b = lst.begin();
        std::cout << "b = " << *b << std::endl;

        //lst.erase(b);
    lst.resize(0, 119);



    std::cout << "size = " << lst.size() << std::endl;
    std::cout << "b = " << *b << std::endl;

   
}

void    range_erase_test3()
{
    ft::list<int> lst, lst2, lst3;
    ft::list<int>::iterator a, b, c, d;

    lst.push_back(19);
    lst.push_back(29);
    lst.push_back(39);
    lst.push_back(49);


    lst2.push_back(1111);
    lst2.push_back(2222);
    lst2.push_back(3333);
    lst2.push_back(4444);
    lst2.push_back(5555);
    lst2.push_back(6666);
    lst2.push_back(7777);

    c = lst2.begin();
    c++;
    c++;
    c++;
    c++;
    c++;
    b = lst.erase(lst2.begin(), c);
    // c = lst2.begin();
    // c++;
    // c++;
    //b = lst.erase(c, lst2.end());

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    
    // 323 - 1

    // 6 - 3
    // 5 - 4
    // 4 - 0
    // 3 - 1
    // 2 - 2
    // 1 - 3
    // 0 - 4
    // -1 - 0
    // -2 - 1
    // -3 - 2
    // -4 - 3
    // -5 - 4
    // -6 - 4   0
    // -7 - 0   1
    // -8 - 1   2
    // -9 - 2   3
    // -10 - 3  4
    // -11 - 4  0



   lst.resize(323, 2222);
   lst2.resize(0, 11100);

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << std::endl;
}

void clear_test()
{
  ft::list<int> mylist;
  ft::list<int>::iterator it;

  mylist.push_back (100);
  mylist.push_back (200);
  mylist.push_back (300);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.clear();

  mylist.push_back (1101);
  mylist.push_back (2202);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void    splice_test()
{
    ft::list<int> lst, lst2, lst3;
    ft::list<int>::iterator a, b, c, d;

    for (int i = 0; i < 6; i++)
        lst.push_back(i + 10);

    for (int i = 0; i < 4; i++)
        lst2.push_back(i + 1000);

    for (int i = 0; i < 3; i++)
        lst3.push_back(0);

    lst2.erase(lst3.begin(), lst3.end());

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;

    // for (c = lst.begin(); c != lst.end(); c++)
    //     std::cout << *c << " ptr = " << c.getPtr() << std::endl;
    // for (c = lst2.begin(); c != lst2.end(); c++)
    //     std::cout << *c << " ptr = " << c.getPtr() << std::endl;
    // std::cout << "\n\n";

    //lst2.splice(lst.begin(), lst2);
    c = lst2.begin();
    c++;
    c++;
    // lst.splice(lst.begin(), lst2, c, lst2.end());
    lst.splice(lst.begin(), lst2);

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    
    // std::cout << lst.end().getPtr() << std::endl;

    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    // std::cout << c.getPtr() << std::endl;
    // c++;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << std::endl;
}

void    remove_test()
{
    std::list<int> lst, lst2, lst3;
    std::list<int>::iterator a, b, c, d;

    for (int i = 0; i < 6; i++)
        lst.push_back(i + 10);

    // for (int i = 0; i < 4; i++)
        // lst2.push_back(i + 1000);

    lst2.push_back(1);
    lst2.push_back(4);
    lst2.push_back(1);
    lst2.push_back(1);
    lst2.push_back(1);
    lst2.push_back(1);
    lst2.push_back(1);
    lst2.push_back(4);



    for (int i = 0; i < 10; i++)
        lst3.push_back(0);

    lst2.erase(lst3.begin(), lst3.end());

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";

    lst2.remove(4);

    std::cout << "lst size = " << lst.size() << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    

    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << std::endl;
    std::cout << "\n\n";
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << std::endl;
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

void    remove_if_test()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

  mylist.remove_if (single_digit);           // 15 36 17 20 39

  mylist.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first) == int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

void    unique_test()
{
    ft::list<int> lst;//, lst2;
    ft::list<int>::iterator c;

    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(1);
    // for (int i = 0; i < 5; i++)
    //     lst2.push_back(123);

    // lst.erase(lst2.begin(), lst2.end());
    lst.push_back(3);
    lst.push_back(2);
    lst.push_back(2);
    lst.push_back(2);
    lst.push_back(1);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(1);
    // lst.push_back(1);
    // lst.push_back(2);
    // lst.push_back(3);
    // lst.push_back(4);
    // lst.push_back(5);
    // lst.push_back(4);
    // lst.push_back(3);
    // lst.push_back(2);
    // lst.push_back(1);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << "ptr = " << c.getPtr() << std::endl;
    std::cout << std::endl;

    //lst.unique();
    // lst.unique(is_near());
    lst.unique(same_integral_part);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << "ptr = " << c.getPtr() << std::endl;
}

void    reverse_test()
{
    ft::list<int> lst, lst2;
    ft::list<int>::iterator c;

    for (int i = 0; i < 6; i++)
        lst.push_back(i + 11);
    for (int i = 0; i < 5; i++)
        lst2.push_back(0);

    lst.erase(lst2.begin(), lst2.end());

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;

    lst.reverse();

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;

}

void    sort_test()
{
    ft::list<int> lst;
    ft::list<int>::iterator c;

    // for (int i = 0; i < 20; i++)
    //     lst.push_back(i % 8);
    
    lst.push_back(25);
    lst.push_back(14);
    // lst.push_back(36);
    // lst.push_back(8);
    // lst.push_back(10);
    // lst.push_back(12);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;

    lst.sort(same_integral_part);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;

}

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

void    sort_test2()
{
  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void    merge_test()
{
    ft::list<int> lst, lst2, lst3;
    ft::list<int>::iterator c;

    for (int i = 0; i < 0; i++)
        lst.push_back(i * 2);
    
    lst2.push_back(3);
    for (int i = 0 ; i < 5; i++)
        lst2.push_back(i * 2 + 1);

    for (int i = 0; i < 20; i++)
        lst3.push_back(3);

    lst.erase(lst3.begin(), lst3.end());
    for (int i = 0; i < 10; i++)
        lst2.push_back(100 + i);
    // lst2.push_back(-20);
    // lst2.push_back(11);
    // lst2.push_back(33);
    // lst2.push_back(52);
    // lst2.push_back(6);
    // lst2.push_back(17);
    // lst2.push_back(8);

    lst.sort();
    lst2.sort();
    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;
    std::cout << std::endl;

   
    // lst2.sort();

    lst.merge(lst2);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

void    merge_test2()
{
  std::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();

  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void    testtest()
{
    ft::list<int> lst, lst2, lst3;
    ft::list<int>::iterator c;

    for (int i = 0; i < 8; i++)
        lst.push_back(i * 100);
    
    for (int i = 0 ; i < 8; i++)
        lst2.push_back(i * 10);

    for (int i = 0; i < 20; i++)
        lst3.push_back(3);
    
    //lst2.erase(lst3.begin(), lst3.end());

    ft::swap(lst, lst2);

    std::cout << "lst size = " << lst.size() << std::endl;
    for (c = lst.begin(); c != lst.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;
    std::cout << "lst2 size = " << lst2.size() << std::endl;
    for (c = lst2.begin(); c != lst2.end(); c++)
        std::cout << *c << " ";
    std::cout << std::endl;

    if (lst < lst2)
        std::cout << "lst < lst2\n";
    else if (lst == lst2)
        std::cout << "===\n";
    else if (lst > lst2)
        std::cout << "lst > lst2\n";
}

int main(void)
{
    
    // ft::list<int> ss;
    //insert_test();
    //push_front_test();
    //range_erase_test();
    //swap_test();

    //clear_test();
    // splice_test();
    // remove_test();
    //remove_if_test();
    // unique_test();
    //reverse_test();
    //sort_test();
    // sort_test2();
    // merge_test();
    // merge_test2();
    testtest();

    return (0);

    std::list<int> lst;
    std::list<int> lst2;
    std::list<int>::iterator a, b, c, d;

    for (int i = 0; i < 2; i++)
       lst.push_back(i + 1);


    for (int i = 0; i < 120; i++)
        lst2.push_back(1111);
    lst2.push_back(2222);
    lst2.push_back(3333);
    lst2.push_back(4444);
    lst2.push_back(5555);
    lst2.push_back(6666);
    lst2.push_back(7777);

    // c = lst.begin();
    // for (int i = 0; i < 1; i++)
    //     c++;


    
    //b = lst.erase(lst.begin(), c);
    // c = lst2.begin();
    // c++;
    // c++;
    //b = lst.erase(c, lst2.end());

    std::cout << "lst size = " << lst.size() << std::endl;

    // lst.erase(lst2.begin(), lst.end());
//    lst.pop_front();
//    lst.pop_front();
//    lst.pop_front();

    return (0);


    // for (int i = 0; i < 4; i++)
    //    ss.push_back(1.11 * (i + 1));

    //for(int i = 0; i < 4; i++)
    //      ss.push_back(i + 10);

    // ss.push_back(333);
    // ss.push_back(3333);
    // ss.push_back(33333);
    //ss.push_back(33333);
    //ss.pop_back();

    //std::cout << ss.front() << " " << ss.back() << std::endl;

    return (0);

    // ft::list<int>::reverse_iterator rr;
    // rr = ss.rbegin();
    // rr++;
    // rr++;
    // ft::list<int>::iterator base = rr.base();
    // ft::list<int>::const_reverse_iterator rrr(base);

    // rrr = rr;

    // if (rr == rrr)
    //     std::cout << "Ok1\n";
    // if (rrr == rr)
    //     std::cout << "Ok2\n";
    // if (rr != rrr)
    //     std::cout << "Ok3\n";
    // if (rrr != rr)
    //     std::cout << "Ok4\n";

    // // ss.print();

    // std::cout << "base = " << *base << std::endl;
    // std::cout << "rr = " << *rr << std::endl;
    // std::cout << "rrr = " << *rrr << std::endl;


    // //*rr = 22;
    // ss.push_back(33);

    // std::cout << *rr << std::endl;
    // rr++;
    // std::cout << *rr << std::endl;
    // std::cout << *++rr << std::endl;
    // rr--;
    // std::cout << *rr << std::endl;
    // std::cout << *--rr << std::endl;

    //std::cout << "size = " << ss.size() << std::endl;
    //ft::list<int>::iterator aa = ss.begin();

    //for (std::list<int>::iterator i = ss.begin(); i != ss.end(); i++)
    //    std::cout << *i << std::endl;

    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;

    // ss.print();
    //ss.pop_back();

    // std::cout << "\n";
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;
    // std::cout << *aa++ << std::endl;


//     ft::list<int> lst(4, 99);
//     ft::list<int> lst2(lst.begin(), ++lst.begin());

//     for (int i = 0; i < 4; i++)
//     {
//         lst2.push_back(i);
//     }
//    ft::list<int>::iterator it = lst2.begin();
//    ft::list<int>::const_iterator it2(it);

//     it2 = it;
//     std::cout << *it << " vs " << *it2 << std::endl;

//     std::list<test> ttt;
//     test date(111);

//     ttt.push_back(date);
//     std::list<test>::iterator ci = ttt.begin();

//     std::cout << "test " << ci->x << std::endl;

//    if (it == it2)
//        std::cout << "ok" << std::endl;


//     ft::list<int> lst3;

//     lst3 = lst;

    // lst.print();
    // lst2.print();
    // lst3.print();

    return (0);
}
