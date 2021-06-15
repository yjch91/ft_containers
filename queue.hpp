#ifndef QUEUE_HPP

# define QUEUE_HPP

#include <iostream>
#include "list.hpp"

namespace ft{

    template <typename T, typename Container = ft::list<T> >
    class queue{
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        protected:
            Container c;
        public:
            // constructor
            explicit queue(const container_type &ctnr = container_type()){
                c = ctnr;
            }

            // destructor
            ~queue() { }

            bool    empty() const{
                return (c.empty());
            }

            size_type   size() const{
                return (c.size());
            }

            value_type  &front(){
                return (c.front());
            }

            const value_type    &front() const{
                return (c.front());
            }

            value_type  &back(){
                return (c.back());
            }

            const value_type    &back() const{
                return (c.back());
            }

            void    push(const value_type &val){
                c.push_back(val);
            }

            void    pop(){
                c.pop_front();
            }

            template <typename FT, typename FContainer>
            friend bool operator==(const queue<FT, FContainer> &lhs, const queue<FT, FContainer> &rhs);

            template <typename FT, typename FContainer>
            friend bool operator<(const queue<FT, FContainer> &lhs, const queue<FT, FContainer> &rhs);
    };

    template <typename T, typename Container>
    bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs){ return (lhs.c == rhs.c); }

    template <typename T, typename Container>
    bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return (!(lhs == rhs)); }

    template <typename T, typename Container>
    bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return (lhs.c < rhs.c); }

    template <typename T, typename Container>
    bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return (!(rhs < lhs)); }

    template <typename T, typename Container>
    bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return (rhs < lhs); }

    template <typename T, typename Container>
    bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) { return (!(lhs < rhs)); }

}

#endif
