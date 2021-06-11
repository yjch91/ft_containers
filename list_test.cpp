#include <iostream>
#include <limits>
#include <list>
#include "utils.hpp"

namespace ft{

    template <typename T>
    struct Node
    {
        T   val;
        Node    *prev;
        Node    *next;
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
        private:
            ft::Node<T> *node;
            ft::Node<T> *end_node;
            size_type _size;
        public:
            // default constructor
            explicit list(const allocator_type& alloc = allocator_type()){
                (void)alloc;
                node = new ft::Node<T>;
                node->val = value_type();
                node->prev = node;
                node->next = node;
                end_node = node;
                _size = 0;
            }

            // destructor
            ~list(){
                ft::Node<T> *temp = node;

                while (node != end_node)
                {
                    delete temp;
                    node = node->next;
                    temp = node;
                }
                delete end_node;
            }

            // fill constructor
            explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                (void)alloc;
                node = new ft::Node<T>;
                node->val = value_type();
                node->prev = node;
                node->next = node;
                end_node = node;
                _size = 0;
                for (size_type i = 0; i < n; i++)
                    push_back(val);
            }

            // range constructor
            template <class InputIterator>
            list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type type = 0){
                (void)alloc;
                (void)type;
                node = new ft::Node<T>;
                node->val = value_type();
                node->prev = node;
                node->next = node;
                end_node = node;
                _size = 0;
                while (first != last)
                    push_back(*first++);
            }

            // copy constructor
            list(const list& x){
                ft::Node<T> *temp = 0;

                node = new ft::Node<T>;
                node->val = value_type();
                node->prev = node;
                node->next = node;
                end_node = node;
                _size = 0;
                temp = x.node;
                while (temp != x.end_node)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
            }

            // Assign content
            list    &operator=(const list &x){
                ft::Node<T> *temp = 0;

                if (node != end_node)
                {
                    temp = node;
                    while (node != end_node)
                    {
                        delete temp;
                        node = node->next;
                        temp = node;
                    }
                    node = end_node;
                    node->prev = node;
                    node->next = node;
                    _size = 0;
                }
                temp = x.node;
                while (temp != x.end_node)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
                return (*this);
            }

            // [Iterators]
            iterator    begin() { return (iterator(node)); }
            const_iterator  begin() const { return (const_iterator(node)); }

            iterator    end() { return (iterator(end_node)); }
            const_iterator  end() const { return (const_iterator(end_node)); }

            reverse_iterator rbegin() { return (reverse_iterator(end_node->prev)); }
            const_reverse_iterator rbegin() const { return (const_reverse_iterator(end_node->prev)); }

            reverse_iterator rend() { return (reverse_iterator(node->prev)); }
            const_reverse_iterator rend() const { return (const_reverse_iterator(node->prev)); }

            // [Capacity]
            bool    empty() const { return (_size == 0); }

            size_type   size() const { return (_size); }

            size_type	max_size() const{
                return (std::min((size_type)std::numeric_limits<difference_type>::max(),
                            std::numeric_limits<size_type>::max() / sizeof(ft::Node<T>)));
            }

            // [Element access]
            reference   front() { return (node->val); }
            const_reference front() const { return (node->val); }

            reference back() { return (end_node->prev->val); }
            const_reference back() const { return (end_node->prev->val); }

            // [Modifiers]
            void    push_back(const value_type &val)
            {
                ft::Node<T> *new_node = new ft::Node<T>;

                new_node->val = val;
                end_node->prev->next = new_node;
                new_node->prev = end_node->prev;
                new_node->next = end_node;
                end_node->prev = new_node;
                if (node == end_node)
                    node = new_node;
                _size++;
            }

            void    print()
            {
                Node<T> *temp = node;
                
                while (temp != end_node)
                {
                    std::cout << "val = " << temp->val << std::endl;
                    temp = temp->next;
                }
                std::cout << "end_node : " << end_node->val << std::endl;
            }
    };

}

class	test{
	public:
		int x;
		test(int a = 0) { x = a; }
		~test() { }
};

#include "vector.hpp"
#include <vector>

int main(void)
{
    ft::list<int> ss;

    // for (int i = 0; i < 4; i++)
    //    ss.push_back(1.11 * (i + 1));

    // for(int i = 0; i < 4; i++)
    //      ss.push_back(i + 10);

    // ss.push_back(333);
    // ss.push_back(3333);
    // ss.push_back(33333);
    //ss.push_back(33333);
    //ss.pop_back();

    std::cout << ss.front() << " " << ss.back() << std::endl;

    return (0);

    ft::list<int>::reverse_iterator rr;
    rr = ss.rbegin();
    rr++;
    rr++;
    ft::list<int>::iterator base = rr.base();
    ft::list<int>::const_reverse_iterator rrr(base);

    rrr = rr;

    if (rr == rrr)
        std::cout << "Ok1\n";
    if (rrr == rr)
        std::cout << "Ok2\n";
    if (rr != rrr)
        std::cout << "Ok3\n";
    if (rrr != rr)
        std::cout << "Ok4\n";

    // ss.print();

    std::cout << "base = " << *base << std::endl;
    std::cout << "rr = " << *rr << std::endl;
    std::cout << "rrr = " << *rrr << std::endl;


    //*rr = 22;
    ss.push_back(33);

    std::cout << *rr << std::endl;
    rr++;
    std::cout << *rr << std::endl;
    std::cout << *++rr << std::endl;
    rr--;
    std::cout << *rr << std::endl;
    std::cout << *--rr << std::endl;

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


    ft::list<int> lst(4, 99);
    ft::list<int> lst2(lst.begin(), ++lst.begin());

    for (int i = 0; i < 4; i++)
    {
        lst2.push_back(i);
    }
//    ft::list<int>::iterator it = lst2.begin();
//    ft::list<int>::const_iterator it2(it);

//     it2 = it;
//     std::cout << *it << " vs " << *it2 << std::endl;

    // std::list<test> ttt;
    // test date(111);

    // ttt.push_back(date);
    // std::list<test>::iterator ci = ttt.begin();

    // std::cout << "test " << ci->x << std::endl;

//    if (it == it2)
//        std::cout << "ok" << std::endl;


    ft::list<int> lst3;

    lst3 = lst;

    // lst.print();
    // lst2.print();
    // lst3.print();

    return (0);
}