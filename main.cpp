#include "iostream"
#include <limits>
#include <vector>


namespace ft{
	template <typename T>
	class VectorIterator;
	
	template <typename T>
	class VectorConstIterator;

	template <bool Cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <typename T>
        struct is_iterator { static const bool value = false; };

	template <typename T>
    	struct is_iterator<VectorConstIterator<T>> { static const bool value = true; };

	template <typename T>
        struct is_iterator<VectorIterator<T>> { static const bool value = true; };

	template <typename T>
	class VectorIterator{
		public:
                        typedef T value_type;
                        typedef T& reference;
                        typedef const T& const_reference;
                        typedef T* pointer;
                        typedef const T* const_pointer;
                        typedef VectorIterator<T> iterator;
                        typedef VectorConstIterator<T> const_iterator;
//                      typedef reverse_iterator;
//                      typedef const_reverse_iterator;
                        typedef ptrdiff_t difference_type;
                        typedef size_t size_type;
		private:
			T *ptr;
		public:
			VectorIterator() { ptr = 0; }
			VectorIterator(T *p) : ptr(p) { }
			~VectorIterator() { }

			VectorIterator(const VectorIterator &i) : ptr(i.ptr) { }
			VectorIterator(const VectorConstIterator<T> &i) : ptr(i.getPtr()) { }
			VectorIterator	&operator=(const VectorIterator &i){
                                ptr = i.ptr;
                                return (*this);
			}

			T 	&operator*() const { return (*ptr); }

			T	*operator++(int){ // i++;
				T	*tmp = ptr;
				ptr++;
				return (tmp);
			}
			T	*operator++(){ // ++i;
				ptr++;
				return (ptr);
			}
			T	*operator--(int){ // i--;
				T	*tmp = ptr;
				ptr--;
				return (tmp);
			}
			T	*operator--(){ // --i
				ptr--;
				return (ptr);
			}

			difference_type	operator-(const VectorIterator &i)
			{
				return (ptr - i.ptr);
			}

			T	*getPtr() const { return (ptr); }
			bool	operator!=(const VectorIterator &p) { return (ptr != p.ptr); }
			//void	operator=(T *p) { ptr = p; };
	};
	
	template <typename T>
	class VectorConstIterator{
		private:
			T *ptr;
		public:
			VectorConstIterator() { ptr = 0; }
			VectorConstIterator(T *p) : ptr(p) { }
			~VectorConstIterator() { }

			VectorConstIterator(const VectorConstIterator &i) : ptr(i.ptr) { }
			VectorConstIterator(const VectorIterator<T> &i) : ptr(i.getPtr()) { }
			VectorConstIterator	&operator=(const VectorConstIterator &i){ 
				ptr = i.ptr;
				return (*this);
			}
			VectorConstIterator	&operator=(const VectorIterator<T> &i){
				ptr = i.getPtr();
				return (*this);
			}

			T const	&operator*() const { return (*ptr); };
			T	*operator++(int){ // i++;
				T	*tmp = ptr;
				ptr++;
				return (tmp);
			}
			T	*operator++(){ // ++i;
				ptr++;
				return (ptr);
			}
			T	*operator--(int){ // i--;
				T	*tmp = ptr;
				ptr--;
				return (tmp);
			}
			T	*operator--(){ // --i
				ptr--;
				return (ptr);
			}
			T       *getPtr() const { return (ptr); }
			bool	operator!=(const VectorConstIterator &p) { return (ptr != p.ptr); }
			//void	operator=(T *p) { ptr = p; };
	};

	template <typename T>
	class vector{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef VectorIterator<T> iterator;
			typedef VectorConstIterator<T> const_iterator;
//			typedef reverse_iterator;
//			typedef	const_reverse_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			// error message check plz !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			class	LengthErrorException : public std::exception{
			public:
				virtual const char	*what() const throw()
				{
					return ("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				}
			};
			class   OutOfRangeException : public std::exception{
                        public:
                                virtual const char      *what() const throw()
                                {
                                        return ("vector::_M_range_check");
                                }
                        };
		private:
			T *ary;
			size_type _size;
			size_type _capacity;
		public:
			// default constructor
			vector() { ary = 0; _size = 0; _capacity = 0; }
			
			// destructor
			~vector(){
				delete[] ary;
			}
			// fill constructor
			vector(size_type n, const value_type &val = value_type()){
				_capacity = n;
				_size = n;
				ary = new T[_capacity];
				for (size_type i = 0; i < _size; i++)
					ary[i] = val;	
			}
			// range constructor
			template <typename InputIterator>
			vector(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, InputIterator>::type tmp = 0){
				size_type n = last - first;
				_capacity = n;
				_size = n;
				ary = new T[_capacity];
				for (size_type i = 0; i < _size; i++)
                         		ary[i] = *first++;
			}
			// copy constructor
			vector(const vector &v){
				if (v._capacity == 0)
					ary = 0;
				else
				{
					ary = new T[v._capacity];
					for (size_type i = 0; i < v._size; i++)
						ary[i] = v.ary[i];
				}
				_size = v._size;
				_capacity = v._capacity;
			}
			// Assign content
			vector	&operator=(const vector &v){
				if (v._capacity == 0)
					ary = 0;
				else
				{
					if (ary != 0)
						delete[] ary;
					ary = new T[v._capacity];
					for (size_type i = 0; i < v._size; i++)
						ary[i] = v.ary[i];
				}
				_size = v._size;
				_capacity = v._capacity;
				return (*this);
			}
			
			// Iterators
			iterator        begin() { return (iterator(ary)); }
                        const_iterator  begin() const { return (const_iterator(ary)); }
                        iterator        end() { return (iterator(&ary[_size])); }
			const_iterator	end() const { return (const_iterator(&ary[_size])); }			
			// rbegin & rend !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


			// Capacity
			size_type       size() const{
                                return (_size);
                        }
                        size_type       max_size() const{
                                return (std::min( (size_type)std::numeric_limits<difference_type>::max(),
                                                        std::numeric_limits<size_type>::max() / sizeof(value_type)));
                        }
                        void    resize(size_type n, value_type val = value_type())
                        {
                                if (n > _capacity)
					reserve(n);
                                for (size_type i = _size; i < n; i++)
                                        ary[i] = val;
                                _size = n;
                        }
                        size_type       capacity() const{
                                return (_capacity);
                        }
			bool    empty() const { return (_size == 0); }
                        void    reserve(size_type n)
                        {
                                if (n > max_size())
					throw LengthErrorException();
                                if (n > _capacity)
                                {
                                        T       *tmp = new T[n];
                                        for(size_type i = 0; i < _size; i++)
                                                tmp[i] = ary[i];
                                        _capacity = n;
                                        delete[] ary;
                                        ary = tmp;
                                }
                        }	
			
			// Element access
			T	&operator[](size_type n){
				return (ary[n]);
			}
			T const &operator[](size_type n) const{
				return (ary[n]);
			}
			reference       at(size_type n){
                                if (n >= _size)
					throw OutOfRangeException();
                                return (ary[n]);
                        }
                        const_reference at(size_type n) const{
                                if (n >= _size)
					throw OutOfRangeException();
                                return (ary[n]);
                        }
			reference       front() { return (ary[0]); }
                        const_reference front() const { return (ary[0]); }
                        reference       back(){ return (ary[_size - 1]); }
                        const_reference back() const{ return (ary[_size - 1]); }

			// Modifiers
			// range assign
			template <typename InputIterator>
			void	assign(InputIterator first, InputIterator last, typename ft::enable_if<ft::is_iterator<InputIterator>::value, InputIterator>::type tmp = 0){
				size_type n = last - first;
				if (_capacity >= n)
					clear();
				else
				{
					delete[] ary;
					ary = new T[n];
					_capacity = n;
				}
				for (size_type i = 0; i < n; i++)
					ary[i] = *first++;
                                _size = n;
			}
			// fill assign
			void	assign(size_type n, const value_type &val){
                                if (_capacity >= n)
                                        clear();
                                else
                                {
                                        delete[] ary;
                                        ary = new T[n];
                                        _capacity = n;
                                }
                                for (size_type i = 0; i < n; i++)
                                        ary[i] = val;
                                _size = n;
			}
			void	push_back(const value_type &val){
				if (_capacity == 0)
				{
					ary = new T[1];
					ary[_size++] = val;
					_capacity = 1;
				}
				else if (_capacity <= _size)
				{
					size_type c = _capacity * 2;
					T	*temp = new T[c];
					for (size_type i = 0; i < _capacity; i++)
						temp[i] = ary[i];
					temp[_size++] = val;
					delete [] ary;
					ary = temp;
					_capacity = c;
				}
				else
					ary[_size++] = val;
			}
			void	pop_back(){
				this->ary[--_size].value_type::~value_type();
			}
			// single elemaent insert
			iterator	insert(iterator position, const value_type &val)
			{
				iterator i = this->begin();
				value_type	temp = val;
				size_type 	j = 0;

				while (i != position)
				{
					i++;
					j++;
				}
				if (_capacity <= _size)
					reserve(_capacity * 2);
				position  = &ary[j];
				if (j != _size)
					temp = ary[j];
				ary[j++] = val;
				for (; j < _size; j++)
				{
					value_type n = ary[j];
					ary[j] = temp;
					temp = n;
				}
				ary[j] = temp;
				_size++;
				return (position);
			}
			// fill insert
			void	insert(iterator position, size_type n, const value_type &val)
			{
				
			}
			// range insert
			template<typename InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				
			}
			void	swap(vector &v)
			{
				size_type c = _capacity;
				size_type s = _size;
				T	*tmp = ary;

				_capacity = v._capacity;
				_size = v._size;
				ary = v.ary;

				v._capacity = c;
				v._size = s;
				v.ary = tmp;
			}
			void    clear(){
                                for (size_type i = 0; i < _size; i++)
                                        this->ary[i].value_type::~value_type();
                                _size = 0;
                        }
	};
}

int main(void)
{
	main_test();
	return (0);


	ft::vector<int> intV;
	ft::vector<int> intV2;
	ft::vector<int>::iterator it(intV.begin());
	ft::vector<int>::iterator it2;
	ft::vector<int>::iterator it3;

	std::vector<int> vec;
	std::vector<int> vec2;
	std::vector<int>::iterator vit(vec.begin());
	std::vector<int>::iterator vit2;
	std::vector<int>::iterator vit3;

	for (int i = 0; i < 16; i++)
	{
		vec.push_back(i + 10);
		intV.push_back(i + 10);
	}
	vit = vec.begin();
	it = intV.begin();
	vit--;
	vit++;
	it--;
	it++;
	std::cout << "capa = " << vec.capacity() << std::endl;
	std::cout << "vit = " << *vit << std::endl;
	vit2 = vec.insert(vit, 200);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
	std::cout << "it = " << *vit2 << std::endl;
	std::cout << "capa = " << vec.capacity() << std::endl;

	std::cout << "\n\n" << std::endl;

	std::cout << "capa = " << intV.capacity() << std::endl;
        std::cout << "vit = " << *it << std::endl;
        it2 = intV.insert(it, 200);
	for (int i = 0; i < intV.size(); i++)
                std::cout << intV[i] << std::endl;
        std::cout << "it = " << *it2 << std::endl;
        std::cout << "capa = " << intV.capacity() << std::endl;
	return (0);

	std::vector<int> d(5, 12);
	std::vector<int> a(d.begin(), d.end());

//	std::cout << a.capacity() << std::endl;
//	std::cout << a.size() << std::endl;
//	for(std::vector<int>::iterator i = a.begin(); i != a.end(); i++)
//		std::cout << *i << std::endl;
//	std::cout << "\n\n" << std::endl;
	
	std::vector<int> xy;
	

	for (int i = 0; i < 10; i++)
		xy.push_back(i + 19);
	xy.assign(1, 12);
	for(int i = 0; i < xy.size(); i++)
		std::cout << xy[i] << std::endl;
	std::cout << xy.capacity() << std::endl;
	std::cout << xy.size() << std::endl;

	ft::vector<int> c(17, 12);
	
	ft::vector<int> yz;
	for (int i = 0; i < 10; i++)
		yz.push_back(i + 19);
	yz.assign(1, 12);
	for(int i = 0; i < yz.size(); i++)
                std::cout << yz[i] << std::endl;
        std::cout << yz.capacity() << std::endl;
	std::cout << yz.size() << std::endl;
	return (0);
	

	ft::vector<int> b(c.begin(), c.end());
	
	std::cout << b.capacity() << std::endl;
        std::cout << b.size() << std::endl;
	for(int i = 0; i < c.size(); i++)
	{
		std::cout << c[i] << " " <<  b[i] << std::endl;
	}

        std::cout << b.capacity() << std::endl;
     	std::cout << b.size() << std::endl;
     	for(ft::vector<int>::iterator i = b.begin(); i != b.end(); i++)
                std::cout << *i << std::endl;
	
	ft::vector<int>::const_iterator p = b.begin();
	ft::vector<int>::iterator q = b.begin();
	std::cout << "q = " << *q << std::endl;
	std::cout << *p << std::endl;
	std::cout << *p << std::endl;

/*	
//	*a = 100;

//	return (0);
	for (int i = 0; i < 3; i++)
		vec.push_back(i + 10);
	vec2 = vec;
	for(int i = 0; i < 14; i++)
		vec.push_back(i);
	std::cout << "no clear " << vec[10] << std::endl;
	vec.clear();
	std::cout << "clear " << *vec.end() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		vec.push_back(i);
		std::cout << vec.capacity() << std::endl;
	}
//	std::cout << vec[0] << " vs " << vec2[0] << std::endl;
//	std::cout << "size = " << vec2.size() << std::endl;

	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << std::endl;


	vit = vec.begin();
	vit2 = vit;
	vit3 = vit2 = vit;

	std::cout << "capa = " << vec.capacity() << std::endl;
	std::cout << vec.size() << std::endl;

	std::vector<char> aa;
	ft::vector<char> bb;
	std::cout << aa.max_size() << " max_size " << bb.max_size() << std::endl;

	std::cout << "back = " << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec[39] << std::endl;
	std::cout << "back = " << vec.back() << std::endl;
	for(int i = 0; i < 3; i++)
		vec.pop_back();
	std::cout << "capa = " << vec.capacity() << std::endl;

	for (int i = 0; i < 3; i++)
		intV.push_back(i);
	intV2 = intV;
	it = intV.begin();
	vit = vec.begin();

	vit2 = vit++;
	vit3 = ++vit;
	it2 = it++;
	it3 = ++it;

	std::cout << "i++ " << *vit2 << " ++i " << *vit3 << std::endl;
	std::cout << "i++ " << *it2 << " ++i " << *it3 << std::endl;

	it2 = it--;
	vit2 = vit--;

	std::cout << "-- test " << *it2 << " " << *vit2 << std::endl;

	*it = 111;
	it = intV2.begin();
	*it = 1234;
	std::cout << *intV.begin() << " vs " << *intV2.begin() << std::endl;
	for (int i = 0; i < 14; i++)
		intV.push_back(i);
	intV2.push_back(3);

	it = intV.begin();
	it++;
	it++;
	std::cout << *it << std::endl;
	intV.clear();
	std::cout << "ada" << std::endl;
	it = intV.begin();
	it++;
	it++;
	std::cout << *intV.end() << std::endl;
	for(int i = 0; i < 4; i++)
	{
		intV.push_back(i);
		std::cout << intV.capacity() << std::endl;
	}
	for (ft::vector<int>::iterator i = intV.begin(); i != intV.end(); i++)
		std::cout << "aa" << *i << std::endl;

	// pop_back
	vec.clear();
	intV.clear();
	for(int i = 0; i < 10; i++)
	{
		vec.push_back(i + 10);
		intV.push_back(i + 10);
	}
	for (int i = 0; i < 5; i++)
	{
		vec.pop_back();
		intV.pop_back();
	}
	std::cout << vec.size() << " vs " << intV.size() << std::endl;

	std::cout << vec[21] << std::endl;
	std::cout << intV[21] << std::endl;

	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	const ft::vector<int> x = v;
//	x[0] = 100; // const fail
	std::cout << "const " << x[0] << std::endl;
//	x.front() = 10; // const fail

	std::vector<int> p;
	ft::vector<int> q;

	if (p.empty())
		std::cout << "p empty" << std::endl;
	if (q.empty())
		std::cout << "q empty" << std::endl;

	for(int i = 0; i < 30; i++)
	{
		p.push_back(i + 11);
		q.push_back(i + 11);
	}
	p.resize(3);
	q.resize(3);
	for (int i = 0; i < (int)p.size(); i++)
		std::cout << p[i] << " vs " << q[i] << std::endl;
	std::cout << p[18] << " " << q[18] << std::endl;	
	p.reserve(200);
	q.reserve(200);
	p.resize(112);
	q.resize(112);
	std::cout << "resize test------\n";
	std::cout << "p capa = " << p.capacity() << std::endl;
	std::cout << "p size = " << p.size() << std::endl;
	std::cout << "q capa = " << q.capacity() << std::endl;
	std::cout << "q size = " << q.size() << std::endl;

	if (!p.empty())
		std::cout << "p no empty" << std::endl;
	if (!q.empty())
		std::cout << "q no empty" << std::endl;
	p.at(1) = 1010;
	q.at(1) = 1010;
	try {
		q.at(5) = 10;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << p.at(1) << " at(1) " << q.at(1) << std::endl;
	std::cout << p.front() << " front " << q.front() << std::endl;
	std::cout << p.back() << " back " << q.back() << std::endl;
	for(int i = 0; i < 3; i++)
	{
//		p.pop_back();
//		q.pop_back();
	}
	std::cout << p.size() << " size " << q.size() << std::endl;
	std::cout << p.front() << " front " << q.front() << std::endl;
	std::cout << p.back() << " back " << q.back() << std::endl;

	std::cout << "ok" << std::endl;
//	p.clear();
//	q.clear();
	std::cout << p.size() << std::endl;
	std::cout << q.size() << std::endl;
*/
	return (0);
}
