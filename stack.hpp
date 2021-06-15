#ifndef STACK_HPP

# define STACK_HPP

#include <iostream>
#include "list.hpp"

namespace ft{

    template <typename T, typename Container = ft::list<T> >
    class stack{
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        protected:
            Container c;
        public:
            // constructor
            explicit stack(const container_type &ctnr = container_type()){
                c = ctnr;
            }

            // destructor
            ~stack() { }

            bool    empty() const{
                return (c.empty());
            }

            size_type   size() const{
                return (c.size());
            }

            value_type  &top(){
                return (c.back());
            }

            const value_type    &top() const{
                return (c.back());
            }

            void    push(const value_type &val){
                c.push_back(val);
            }

            void    pop(){
                c.pop_back();
            }

            template <typename FT, typename FContainer>
            friend bool operator==(const stack<FT, FContainer> &lhs, const stack<FT, FContainer> &rhs);

            template <typename FT, typename FContainer>
            friend bool operator<(const stack<FT, FContainer> &lhs, const stack<FT, FContainer> &rhs);
    };

    template <typename T, typename Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs){ return (lhs.c == rhs.c); }

    template <typename T, typename Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (!(lhs == rhs)); }

    template <typename T, typename Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (lhs.c < rhs.c); }

    template <typename T, typename Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (!(rhs < lhs)); }

    template <typename T, typename Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (rhs < lhs); }

    template <typename T, typename Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return (!(lhs < rhs)); }

}

#endif
