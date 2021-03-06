#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <limits>
#include "utils.hpp"

namespace ft{
    // class vector_iterator
    template <typename T>
	class VectorIterator{
        public:
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
		private:
			T *ptr;
		public:
			VectorIterator() { ptr = 0; }
			
			~VectorIterator() { }

			VectorIterator(const VectorIterator &src) : ptr(src.ptr) { }

			template<typename diffT>
			VectorIterator(const VectorIterator<diffT> &src) : ptr(src.getPtr()) { }

			VectorIterator &operator=(const VectorIterator &src){
                ptr = src.ptr;
                return (*this);
			}

			explicit VectorIterator(T *p) : ptr(p) { }	// explicit ex) int p = 10; vector.erase(&p);

			T	*getPtr() const { return (ptr); }
						
			bool operator==(const VectorIterator &src) const { return (ptr == src.ptr); }
			template<typename diffT>
			bool operator==(const VectorIterator<diffT> &src) const { return (ptr == const_cast<T*>(src.getPtr())); }

			bool operator!=(const VectorIterator &src) const { return (ptr != src.ptr); }
			template<typename diffT>
			bool operator!=(const VectorIterator<diffT> &src) const { return (ptr != const_cast<T*>(src.getPtr())); }

			T &operator*() const { return (*ptr); }

			T *operator->() const { return (ptr); }

			VectorIterator operator++(int){		// i++;
				VectorIterator<T>	temp = *this;
				ptr++;
				return (temp);
			}
			VectorIterator &operator++(){		// ++i;
				ptr++;
				return (*this);
			}
			VectorIterator operator--(int){		// i--;
				VectorIterator<T>	temp = *this;
				ptr--;
				return (temp);
			}
			VectorIterator &operator--(){		// --i;
				ptr--;
				return (*this);
			}
			
			VectorIterator operator+(difference_type n) const{
				VectorIterator<T>	temp(ptr + n);
				return (temp);
			}

			VectorIterator operator-(difference_type n) const{
				VectorIterator<T>	temp(ptr - n);
                return (temp);
            }

			difference_type operator-(const VectorIterator &src) const { return (ptr - src.ptr); }
			template<typename diffT>
			difference_type operator-(const VectorIterator<diffT> &src) const { return (ptr - const_cast<T*>(src.getPtr())); }

			VectorIterator &operator+=(difference_type n){
				ptr += n;
				return (*this);
			}

			VectorIterator &operator-=(difference_type n){
                ptr -= n;
                return (*this);
            }
			
			bool operator<(const VectorIterator &src) const { return (ptr < src.ptr); }
			template<typename diffT>
			bool operator<(const VectorIterator<diffT> &src) const { return (ptr < const_cast<T*>(src.getPtr())); }

			bool operator<=(const VectorIterator &src) const { return (ptr <= src.ptr); }
			template<typename diffT>
			bool operator<=(const VectorIterator<diffT> &src) const { return (ptr <= const_cast<T*>(src.getPtr())); }

			bool operator>(const VectorIterator &src) const { return (ptr > src.ptr); }
			template<typename diffT>
			bool operator>(const VectorIterator<diffT> &src) const { return (ptr > const_cast<T*>(src.getPtr())); }

			bool operator>=(const VectorIterator &src) const { return (ptr >= src.ptr); }
			template<typename diffT>
			bool operator>=(const VectorIterator<diffT> &src) const { return (ptr >= const_cast<T*>(src.getPtr())); }

			T &operator[](size_type n) const { return (ptr[n]); }
	};

	template <typename T>
	VectorIterator<T> operator+(int n, const VectorIterator<T> &rhs){ return (rhs + n); }

    // class vector_reverse_iterator
	template <typename T>
	class VectorReverseIterator{
		public:
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;
		private:
			T *ptr;
		public:
			VectorReverseIterator() { ptr = 0; }
			
			~VectorReverseIterator() { }

			explicit VectorReverseIterator(VectorIterator<T> it){
				ptr = it.getPtr();
				ptr--;
			}

			VectorReverseIterator(const VectorReverseIterator &src) : ptr(src.ptr) { }
			
			template<typename diffT>
			VectorReverseIterator(const VectorReverseIterator<diffT> &src) : ptr(src.getPtr()) { }

			VectorReverseIterator &operator=(const VectorReverseIterator &src){
				ptr = src.ptr;
				return (*this);
			}

			explicit VectorReverseIterator(T *p) { ptr = p; }

			T *getPtr() const { return (ptr); }; 

			VectorIterator<T> base() { return (VectorIterator<T>(ptr + 1)); }

			bool operator==(const VectorReverseIterator &src) const { return (ptr == src.ptr); }
			template<typename diffT>
			bool operator==(const VectorReverseIterator<diffT> &src) const { return (ptr == const_cast<T*>(src.getPtr())); }

			bool operator!=(const VectorReverseIterator &src) const { return (ptr != src.ptr); }
			template<typename diffT>
			bool operator!=(const VectorReverseIterator<diffT> &src) const { return (ptr != const_cast<T*>(src.getPtr())); }

			T &operator*() const { return (*ptr); }

			T *operator->() const { return (ptr); }

			VectorReverseIterator operator++(int){	// i++;
				VectorReverseIterator<T>	temp = *this;
				ptr--;
				return (temp);
			}
			VectorReverseIterator &operator++(){	// ++i;
				ptr--;
				return (*this);
			}
			VectorReverseIterator operator--(int){	// i--;
				VectorReverseIterator<T>	temp = *this;
				ptr++;
				return (temp);
			}
			VectorReverseIterator &operator--(){	// --i
				ptr++;
				return (*this);
			}

			VectorReverseIterator operator+(difference_type n) const{
				VectorReverseIterator<T>	temp(ptr - n);
				return (temp);
			}

			VectorReverseIterator operator-(difference_type n) const{
				VectorReverseIterator<T>	temp(ptr + n);
				return (temp);
			}

			difference_type operator-(const VectorReverseIterator &src) const { return (src.ptr - ptr); }
			template<typename diffT>
			difference_type operator-(const VectorReverseIterator<diffT> &src) const { return (const_cast<T*>(src.getPtr()) - ptr); }

			VectorReverseIterator &operator+=(difference_type n){
				ptr -= n;
				return (*this);
			}

			VectorReverseIterator &operator-=(difference_type n){
				ptr += n;
				return (*this);
			}

			bool operator<(const VectorReverseIterator &src) const { return (src.ptr < ptr); }
			template<typename diffT>
			bool operator<(const VectorReverseIterator<diffT> &src) const { return (const_cast<T*>(src.getPtr()) < ptr); }

			bool operator<=(const VectorReverseIterator &src) const { return (src.ptr <= ptr); }
			template<typename diffT>
			bool operator<=(const VectorReverseIterator<diffT> &src) const { return (const_cast<T*>(src.getPtr()) <= ptr); }

			bool operator>(const VectorReverseIterator &src) const { return (src.ptr > ptr); }
			template<typename diffT>
			bool operator>(const VectorReverseIterator<diffT> &src) const { return (const_cast<T*>(src.getPtr()) > ptr); }
			
			bool operator>=(const VectorReverseIterator &src) const { return (src.ptr >= ptr); }
			template<typename diffT>
			bool operator>=(const VectorReverseIterator<diffT> &src) const { return (const_cast<T*>(src.getPtr()) >= ptr); }

			T &operator[](size_type n) const { return (*(ptr - n)); }
	};

	template <typename T>
	VectorReverseIterator<T> operator+(int n, const VectorReverseIterator<T> &rhs){ return (rhs + n); }

	// T* allocate(size_t) 			:	??????????????? ?????? ????????? ????????? ???????????? ??? ?????? ????????? ????????????.
	// 									??????????????? ????????? ????????? ?????? ????????? T ????????? ????????????.
	// void deallocate(T*, size_t)	:	????????? ????????? ????????????.(allocate??? ????????? ????????? ???????????? ??????)
	//									????????? ???????????? ????????? ????????? ???????????? allocate??? ???????????? ???????????? ?????? ????????? ???????????? ?????????, ????????? allocate??? ???????????? ?????? ????????????.
	// void construct(T*, const T&) :	??????????????? ?????? ????????? ????????? ????????????.
	//									T?????? ???????????? ????????? ??????????????? ????????? ???????????? ???????????? ????????? ????????? ????????????.
	// void destory(T*)				:	????????? ???????????????.
	//									????????? ????????? ???????????? ???????????? ????????? ???????????? ????????????. 

    // class vector
	template <typename T, typename Alloc = std::allocator<T> >
	class vector{
		public:
			typedef	T value_type;
			typedef	std::allocator<T> allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef VectorIterator<T> iterator;
			typedef VectorIterator<const T> const_iterator;
			typedef VectorReverseIterator<T> reverse_iterator;
			typedef	VectorReverseIterator<const T> const_reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef size_t size_type;

			class LengthErrorException : public std::exception{
				public:
					virtual const char *what() const throw(){
						return ("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
					}
			};

            class OutOfRangeException : public std::exception{
                public:
                    virtual const char *what() const throw(){
                        return ("vector");
                    }
            };

		private:
			T *ary;
			size_type _size;
			size_type _capacity;
		public:
			// default constructor
			explicit vector(const allocator_type &alloc = allocator_type()){
				(void)alloc;
				ary = 0;
				_size = 0;
				_capacity = 0;
			}
			
			// destructor
			~vector(){
				allocator_type	alloc;

				for (size_type i = 0; i < _size; i++)
					alloc.destroy(ary + i);
				alloc.deallocate(ary, _capacity);
			}

			// fill constructor
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()){
				allocator_type	_alloc = alloc;

                _size = n;
                _capacity = n;
                ary = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
					_alloc.construct(ary + i, val);
			}

			// range constructor
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
				allocator_type	_alloc = alloc;
				InputIterator	it = first;

				(void)type;
				_size = 0;
				while (it != last)
				{
					it++;
					_size++;
				}
				_capacity = _size;
				ary = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(ary + i, *first++);
			}

			// copy constructor
			vector(const vector &x){
				if (x._capacity == 0)
					ary = 0;
				else
				{
					allocator_type alloc;

					ary = alloc.allocate(x._capacity);
					for (size_type i = 0; i < x._size; i++)
						alloc.construct(ary + i, x.ary[i]);
				}
				_size = x._size;
				_capacity = x._capacity;
			}

			// assign content
			vector &operator=(const vector &x){
				allocator_type	alloc;

				if (_capacity != 0)
				{
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
				}
				if (_capacity >= x._size)
				{
					for (size_type i = 0; i < x._size; i++)
						alloc.construct(ary + i, x.ary[i]);
				}
				else
				{
					if (_capacity != 0)
						alloc.deallocate(ary, _capacity);
					ary = alloc.allocate(x._size);
					for (size_type i = 0; i < x._size; i++)
						alloc.construct(ary + i, x.ary[i]);
					_capacity = x._size;
				}
				_size = x._size;
				return (*this);
			}
			
			// [Iterators]
			iterator begin() { return (iterator(ary)); }
			const_iterator begin() const { return (const_iterator(ary)); } 

			iterator end() { return (iterator(&ary[_size])); }
			const_iterator end() const { return (const_iterator(&ary[_size])); }

			reverse_iterator rbegin() { return (reverse_iterator(&ary[_size - 1])); }
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(&ary[_size - 1])); }

			reverse_iterator rend() { return (reverse_iterator(ary - 1)); }
			const_reverse_iterator rend() const { return (const_reverse_iterator(ary - 1)); }

			// [Capacity]
			size_type size() const { return (_size); }

            size_type max_size() const{
                return (std::min((size_type)std::numeric_limits<difference_type>::max(),
                            std::numeric_limits<size_type>::max() / sizeof(value_type)));
            }

            void resize(size_type n, value_type val = value_type()){
                if (n > _capacity)
				{
					if (_capacity * 2 >= n)
						reserve(_capacity * 2);
					else
						reserve(n);
				}
                for (size_type i = _size; i < n; i++)
                    ary[i] = val;
                _size = n;
            }

            size_type capacity() const { return (_capacity); }

			bool empty() const { return (_size == 0); }

            void reserve(size_type n){
                if (n > max_size())
					throw LengthErrorException();
                if (n > _capacity)
                {
					allocator_type alloc;
                    T       *temp = alloc.allocate(n);

                    for(size_type i = 0; i < _size; i++)
						alloc.construct(temp + i, ary[i]);
                    for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
					alloc.deallocate(ary, _capacity);
					_capacity = n;
					ary = temp;
                }
            }	
			
			// [Element access]
			T &operator[](size_type n) { return (ary[n]); }
			T const &operator[](size_type n) const { return (ary[n]); }

			reference at(size_type n){
                if (n >= _size)
					throw OutOfRangeException();
                return (ary[n]);
            }

            const_reference at(size_type n) const{
                if (n >= _size)
					throw OutOfRangeException();
                return (ary[n]);
            }

			reference front() { return (ary[0]); }
            const_reference front() const { return (ary[0]); }

            reference back() { return (ary[_size - 1]); }
            const_reference back() const { return (ary[_size - 1]); }

			// [Modifiers]
			// range assign
			template <typename InputIterator>
			void assign(InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){				
				allocator_type	alloc; 
				InputIterator	it = first;
				size_type	n = 0;

				(void)type;
				while (it != last)
				{
					it++;
					n++;
				}
				if (_capacity >= n)
				{
					for (size_type i = n; i < _size; i++)
						alloc.destroy(ary + i);
				}
				else
				{
					reserve(n);
				}
				for (size_type i = 0; i < n; i++)
					alloc.construct(ary + i, *first++);
                _size = n;
			}

			// fill assign
			void assign(size_type n, const value_type &val){
                allocator_type	alloc;

				if (_capacity >= n){
					for (size_type i = n; i < _size; i++)
						alloc.destroy(ary + i);
				}
                else
                {
					reserve(n);
                }
                for (size_type i = 0; i < n; i++)
					alloc.construct(ary + i, val);
                _size = n;
			}

			void push_back(const value_type &val){
				allocator_type	alloc;

				if (_capacity == 0)
				{
					ary = alloc.allocate(1);
					alloc.construct(ary + _size, val);
					_size += 1;
					_capacity = 1;
				}
				else if (_capacity <= _size)
				{
					size_type c = _capacity * 2;
					T	*temp = alloc.allocate(c);

					for (size_type i = 0; i < _capacity; i++)
						alloc.construct(temp + i, ary[i]);
					alloc.construct(temp + _size, val);
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
					alloc.deallocate(ary, _capacity);
					ary = temp;
					_size += 1;
					_capacity = c;
				}
				else
					ary[_size++] = val;
			}

			void pop_back(){
				allocator_type	alloc;
				
				alloc.destroy(ary + --_size);
			}

			// single element insert
			iterator insert(iterator position, const value_type &val){
				allocator_type	alloc;
				iterator	i;
				size_type	j = position - begin();
				size_type	count = 0;
				size_type	c = _capacity;
				
				if (_capacity >= _size + 1)
				{
					count = _size;
					for (c = 0; c < _size - j; c++)
					{
						alloc.construct(ary + count, ary[count - 1]);
						count--;
					}
					alloc.construct(ary + count, val);
				}
				else if (_capacity < _size + 1)
				{
					_capacity *= 2;
					if (_capacity == 0)
						_capacity = 1;
					T	*temp = alloc.allocate(_capacity);
					for (i = begin(); i != position; i++)
						alloc.construct(temp + count++, *i);
					alloc.construct(temp + count++, val);
					for (i = position; i != end(); i++)
						alloc.construct(temp + count++, *i);
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
					alloc.deallocate(ary, c);
					ary = temp;
				}
				_size += 1;
				return (iterator(&ary[j]));
			}

			// fill insert
			void insert(iterator position, size_type n, const value_type &val){
				allocator_type	alloc;
				iterator	i;
				size_type	j = position - begin();
				size_type	count = 0;
				size_type	c = _capacity;

				if (n == 0)
					return ;
				if (_capacity >= _size + n)
				{
					count = _size - 1 + n;
					for (c = 0; c < _size - j; c++)
					{
						alloc.construct(ary + count, ary[count - n]);
						count--;
					}
					c = n;
					while (c--)
						alloc.construct(ary + count--, val);
				}
				else if (_capacity < _size + n)
				{
					if (_capacity * 2 >= _size + n)
						_capacity = _capacity * 2;
					else
						_capacity = _size + n;
					T	*temp = alloc.allocate(_capacity);
					for (i = begin(); i != position; i++)
						alloc.construct(temp + count++, *i);
					for (size_type p = 0; p < n; p++)
						alloc.construct(temp + count++, val);
					for (i = position; i != end(); i++)
						alloc.construct(temp + count++, *i);
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
					alloc.deallocate(ary, c);
					ary = temp;
				}
				_size += n;
			}

			// range insert
			template<typename InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
				allocator_type	alloc;
				iterator	i;
				size_type	j = position - begin();
				size_type	count = 0;
				size_type	c = _capacity;
				size_type	n = 0;
				InputIterator	it = first;

				(void)type;
				while (it != last)
				{
					it++;
					n++;
				}
				if (n == 0)
					return ;
				if (_capacity >= _size + n)
				{
					count = _size - 1 + n;
					for (c = 0; c < _size - j; c++)
					{
						alloc.construct(ary + count, ary[count - n]);
						count--;
					}
					while (1)
					{
						last--;
						alloc.construct(ary + count--, *last);
						if (last == first)
							break ;
					}
				}
				else if (_capacity < _size + n)
				{
					if (_capacity * 2 >= _size + n)
						_capacity = _capacity * 2;
					else
						_capacity = _size + n;
					T	*temp = alloc.allocate(_capacity);
					for (i = begin(); i != position; i++)
						alloc.construct(temp + count++, *i);
					for (; first != last; first++)
						alloc.construct(temp + count++, *first);
					for (i = position; i != end(); i++)
						alloc.construct(temp + count++, *i);
					for (size_type i = 0; i < _size; i++)
						alloc.destroy(ary + i);
					alloc.deallocate(ary, c);
					ary = temp;
				}
				_size += n;
			}

			iterator erase(iterator position){
				allocator_type	alloc;
				iterator	i;
				iterator	j;

				i = position;
				j = i + 1;
				while (j != end())
				{
					*i++ = *j++;
				}
				alloc.destroy(ary + --_size);
				return (position);
			}

			iterator erase(iterator first, iterator last){
				allocator_type	alloc;
				iterator	i;
				iterator	j;
				size_type	n = 0;
				size_type	m;

				i = first;
				while (i != last)
				{
					i++;
					n++;
				}
				i = first;
				j = i + n;
				while (j != end())
				{
					*i++ = *j++;
				}
				m = n;
				while (n)
					alloc.destroy(ary + _size - n--);
				_size -= m;
				return (first);
			}

			void swap(vector &x){
				T	*temp = ary;
				size_type	s = _size;
				size_type	c = _capacity;

				ary = x.ary;
				_size = x._size;
				_capacity = x._capacity;

				x.ary = temp;
				x._size = s;
				x._capacity = c;
			}

			void clear(){
				allocator_type	alloc;
				
				for (size_type i = 0; i < _size; i++)
					alloc.destroy(ary + i);
				_size = 0;
			}
	};
	
	// [Non-member function overloads]
	template <typename T, typename Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		size_t	n = lhs.size();
		
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < n; i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}
	
	template <typename T, typename Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(lhs == rhs)); }
	
	template <typename T, typename Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		size_t	n = std::min(lhs.size(), rhs.size());

		for (size_t i = 0; i < n; i++)
		{
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);
		}
		if (rhs.size() > n)
			return (true);
		return (false);
	}
	
	template <typename T, typename Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(rhs < lhs)); }

	template <typename T, typename Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (rhs < lhs); }

	template <typename T, typename Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) { return (!(lhs < rhs)); }	

	template <typename T, typename Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) { x.swap(y); }
}

#endif
