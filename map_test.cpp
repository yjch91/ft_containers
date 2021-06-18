#ifndef MAP_HPP

# define MAP_HPP

#include <iostream>
#include <limits>
#include "utils.hpp"

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
        pair(){
            first = first_type();
            second = second_type();
        }

        // copy
        template <typename U, typename V>
        pair(const pair<U, V> &pr){
            first = pr.first;
            second = pr.second;
        }

        // initialization
        pair(const first_type &a, const second_type &b){
            first = a;
            second = b;
        }

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

    // class map
    template <typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T>> >
    class map{
        public:
            map() { }
            ~map() { }
    };
}

#endif

int main(void)
{
    ft::map<int, int> a;

    return (0);
}
