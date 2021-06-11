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
    class ListIterator{
        public:
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            T *ptr;
        public:
            ListIterator() { ptr = 0; }

            ~ListIterator() { }

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
            typedef ListIterator<const T> const_iterator;
            // typedef ListReverseIterator<T> reverse_iterator;
            // typedef ListReverseIterator<const T> const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef size_t size_type;
        private:
            ft::Node<T> *node;
            ft::Node<T> *last_element_node;
            size_type _size;
        public:
            // default constructor
            explicit list(const allocator_type& alloc = allocator_type()){
                (void)alloc;
                node = 0;
                last_element_node = 0;
                _size = 0;
            }

            // destructor
            ~list(){
                ft::Node<T> *temp = node;

                while (node != 0)
                {
                    delete temp;
                    node = node->next;
                    temp = node;
                }
            }

            // fill constructor
            explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
                (void)alloc;
                node = 0;
                last_element_node = 0;
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
                node = 0;
                last_element_node = 0;
                _size = 0;
                while (first != last)
                    push_back(*first++);
            }

            // copy constructor
            list(const list& x){
                ft::Node<T> *temp = x.node;

                node = 0;
                last_element_node = 0;
                _size = 0;
                while (temp != 0)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
            }

            // Assign content
            list    &operator=(const list &x){
                ft::Node<T> *temp = 0;

                if (node != 0)
                {
                    temp = node;
                    while (node != 0)
                    {
                        delete temp;
                        node = node->next;
                        temp = node;
                    }
                }
                node = 0;
                last_element_node = 0;
                _size = 0;
                temp = x.node;
                while (temp != 0)
                {
                    push_back(temp->val);
                    temp = temp->next;
                }
                return (*this);
            }

            void    push_back(const value_type &val)
            {
                ft::Node<T> *new_node = new ft::Node<T>;

                new_node->val = val;
                new_node->prev = 0;
                new_node->next = 0;
                if (_size == 0)
                    node = new_node;
                else{
                    new_node->prev = last_element_node;
                    last_element_node->next = new_node;
                }
                _size++;
                last_element_node = new_node;
            }

            void    print()
            {
                Node<T> *temp = node;
                while (temp != 0)
                {
                    std::cout << temp->val << std::endl;
                    temp = temp->next;
                }
                std::cout << "last_element_node : " << last_element_node->val << std::endl;
            }
    };

}

int main(void)
{
    std::list<int> ss(3, 9);

    ft::list<int> lst(ss.begin(), ss.end());
    lst.push_back(11);
    lst.push_back(22);
    lst.push_back(33);

    ft::list<int> lst2(3, 9);
    lst2 = lst;
    lst2.print();
    return (0);
}