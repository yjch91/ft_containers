#include "iostream"
#include <limits>

#include <vector>


namespace ft{
	template <typename T>
	class VectorIterator{
		private:
			T *ptr;
		public:
			VectorIterator() { ptr = 0; }
			VectorIterator(T *p) : ptr(p) { }
			~VectorIterator() { }
			VectorIterator(const VectorIterator &i) : ptr(i.ptr) { }
			VectorIterator	&operator=(const VectorIterator &i){ 
				ptr = i.ptr;
				return (*this);
			}
			T &operator*() {return (*ptr); };
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
			bool	operator!=(const VectorIterator &p) { return (ptr != p.ptr); }
			//void	operator=(T *p) { ptr = p; };
	};

	template <typename T>
	class vector{
		private:
			T *ary;
			unsigned long vsize;
			unsigned long vcapacity;
		public:
			typedef VectorIterator<T> iterator;
			
			vector() { ary = 0; vsize = 0; vcapacity = 0; }
			~vector(){
				delete[] ary;
			}
			vector(const vector &v){
				if (v.vcapacity == 0)
					ary = 0;
				else
				{
					ary = new T[v.vcapacity];
					for (unsigned int i = 0; i < v.vsize; i++)
						ary[i] = v.ary[i];
				}
				vsize = v.vsize;
				vcapacity = v.vcapacity;
			}
			vector	&operator=(const vector &v){
				if (v.vcapacity == 0)
					ary = 0;
				else
				{
					if (ary != 0)
						delete[] ary;
					ary = new T[v.vcapacity];
					for (unsigned int i = 0; i < v.vsize; i++)
						ary[i] = v.ary[i];
				}
				vsize = v.vsize;
				vcapacity = v.vcapacity;
				return (*this);
			}
			T	&operator[](unsigned int n){
				return (ary[n]);
			}
			T const &operator[](unsigned int n) const{
				return (ary[n]);
			}
			void	push_back(T const &value){
				if (vcapacity == 0)
				{
					ary = new T[1];
					ary[vsize++] = value;
					vcapacity = 1;
				}
				else if (vcapacity <= vsize)
				{
					unsigned int c = vcapacity * 2;
					T	*temp = new T[c];
					for (unsigned int i = 0; i < vcapacity; i++)
						temp[i] = ary[i];
					temp[vsize++] = value;
					delete [] ary;
					ary = temp;
					vcapacity = c;
				}
				else
					ary[vsize++] = value;
			}
			unsigned long	size(void) const{
				return (vsize);
			}
			unsigned long	max_size(void) const{
				return (std::min( (unsigned long)std::numeric_limits<long>::max(),
							std::numeric_limits<unsigned long>::max() / sizeof(T)));
			}
			void	resize(unsigned long n, T val = T())
			{
				if (n > vcapacity)
					reserve(n);
				for (unsigned long i = vsize; i < n; i++)
					ary[i] = val;
				vsize = n;
			}
			unsigned long	capacity(void) const{
				return (vcapacity);
			}
			void	reserve(unsigned long n)
			{
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
				if (n > vcapacity)
				{
					T	*tmp = new T[n];
					for(unsigned long i = 0; i < vsize; i++)
						tmp[i] = ary[i];
					vcapacity = n;
					delete[] ary;
					ary = tmp;
				}
			}
			bool	empty(void) const { return (vsize == 0); }
			void	clear(void){
	//				vsize = 0;
	//			for (unsigned long i = 0; i < vsize; i++)
	//				this->ary[i].T::~T();
				vsize = 0;
	//			delete[] ary;
	//			ary = new T[vcapacity];
			}
			iterator	begin() { return (iterator(ary)); }
			iterator	end() { return (iterator(&ary[vsize])); }
			void	pop_back(void) { vsize--; }
			T	&front() { return (ary[0]); }
			T const	&front() const { return (ary[0]); }
			T	&back(){ return (ary[vsize - 1]); }
			T const &back() const{ return (ary[vsize - 1]); }
			T	&at(unsigned int n){
				if (n >= vsize)
					throw std::out_of_range("vector");
				return (ary[n]);
			}
			T const	&at(unsigned int n) const{
				if (n >= vsize)
					throw std::out_of_range("vector");
				return (ary[n]);
			}
	};
}

int main(void)
{
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

	return (0);
}
