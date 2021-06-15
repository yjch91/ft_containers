#ifndef LIST_HPP

# define LIST_HPP

#include <iostream>
#include <limits>
#include "utils.hpp"

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
                    clear();
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
                (void)type;
                clear();
                while (first != last)
                    push_back(*first++);
            }

            // fill assign
            void assign (size_type n, const value_type &val){
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
                    throw PopException();
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
                    throw PopException();
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
                    throw EraseException();
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
                        throw EraseException();
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

#endif
