#ifndef UTILS_HPP

# define UTILS_HPP

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
        pair() : first(first_type()), second(second_type()) { }

        // copy
        template <typename U, typename V>
        pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) { }

        // initialization
        pair(const first_type &a, const second_type &b) : first(a), second(b) { }

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

    // function template make_pair
    template <typename T1, typename T2>
    ft::pair<T1, T2> make_pair(T1 x, T2 y) { return (ft::pair<T1, T2>(x, y)); }

    // struct tree
    template<typename T>
    struct tree{
        T val;
        tree *parent;
        tree *left;
        tree *right;
        int h;

        tree(T value) : val(value), parent(0), left(0), right(0), h(0) { }

        ft::tree<T> *front(){
            ft::tree<T>   *temp = this;

            while (temp != 0 && temp->left != 0)
                temp = temp->left;
            return (temp);
        }

        ft::tree<T> *back(){
            ft::tree<T>   *temp = this;

            while (temp != 0 && temp->right != 0)
                temp = temp->right;
            return (temp);
        }

        ft::tree<T> *prev(){
            ft::tree<T>   *ptr = this;

            if (ptr->left != 0)
            {
                ptr = ptr->left;
                if (ptr->right == 0)
                    return (ptr);
                while (1)
                {
                    if (ptr->right != 0)
                        ptr = ptr->right;
                    else
                        break ;
                }
            }
            else
            {
                ft::tree<T>    *temp;

                while (1)
                {
                    temp = ptr;
                    ptr = ptr->parent;
                    if (ptr == 0)
                        break ;
                    else if (ptr->right == temp)
                        break ;
                }     
            }
            return (ptr);
        }

        ft::tree<T> *next(){
            ft::tree<T>   *ptr = this;

            if (ptr->right != 0) 
            {
                ptr = ptr->right;
                if (ptr->left == 0)
                    return (ptr);
                while (1)
                {
                    if (ptr->left != 0)
                        ptr = ptr->left;
                    else
                        break ;
                }
            }
            else
            {
                ft::tree<T>    *temp;

                while (1)
                {
                    temp = ptr;
                    ptr = ptr->parent;
                    if (ptr == 0)
                        break ;
                    else if (ptr->left == temp)
                        break ;
                }
            }
            return (ptr);
        }

        int getBalanceFactor(){
            int lh = -1;
            int rh = -1;

            if (left != 0)
                lh = left->h;
            if (right != 0)
                rh = right->h;
            return (lh - rh);
        }

        void checkHeight(){
            ft::tree<T>   *temp = this;

            while (temp != 0)
            {
                int lh = -1;
                int rh = -1;

                if (temp->left != 0)
                    lh = temp->left->h;
                if (temp->right != 0)
                    rh = temp->right->h;
                temp->h = std::max(lh, rh) + 1;
                temp = temp->parent;
            }
        }

        void LLrotation(){
            ft::tree<T>   *temp = this;
            ft::tree<T>   *pnode = temp->parent;
            ft::tree<T>   *cnode = temp->left;
                         
            temp->left = temp->left->right;
            if (temp->left != 0)
                temp->left->parent = temp;
            cnode->right = temp;
            temp->parent = cnode;
            cnode->parent = pnode;
            if (pnode != 0)
            {
                if (pnode->left == temp)
                    pnode->left = cnode;
                else if (pnode->right == temp)
                    pnode->right = cnode;
            }
        }

        void RRrotation(){
            ft::tree<T>   *temp = this;
            ft::tree<T>   *pnode = temp->parent;
            ft::tree<T>   *cnode = temp->right;

            temp->right = temp->right->left;
            if (temp->right != 0)
                temp->right->parent = temp;
            cnode->left = temp;
            temp->parent = cnode;
            cnode->parent = pnode;
            if (pnode != 0)
            {
                if (pnode->left == temp)
                    pnode->left = cnode;
                else if (pnode->right == temp)
                    pnode->right = cnode;
            }
        }

        void rebalance(){
            ft::tree<T>   *temp = this;

            temp->checkHeight();
            while (temp != 0)   // bf check
            {
                int bf = temp->getBalanceFactor();

                if (bf < -1 || bf > 1)
                    break ;
                temp = temp->parent;
            }
            if (temp != 0)
            {
                int h1 = temp->getBalanceFactor();
                int h2 = 0;

                if (h1 > 1)
                    h2 = temp->left->getBalanceFactor();
                else if (h1 < -1)
                    h2 = temp->right->getBalanceFactor();

                if (h1 > 1 && h2 >= 0) // LLrotation(3, 2, 1)
                {
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 <= 0) // RRrotation(1, 2, 3)
                {
                    temp->RRrotation();
                }
                else if (h1 > 1 && h2 < 0) // LRrotation(3, 1, 2)
                {
                    temp->left->RRrotation();
                    temp->left->left->checkHeight(); // before : temp->left - RRrotation - after : temp->left->left
                    temp->LLrotation();
                }
                else if (h1 < -1 && h2 > 0) // RLrotation(1, 3, 2)
                {
                    temp->right->LLrotation();
                    temp->right->right->checkHeight();
                    temp->RRrotation();
                }
                temp->checkHeight();
            }
        }
    };

	template <bool Cond, typename T = void>
	struct enable_if {};

	template <>
	struct enable_if<true>{
		typedef bool type;
	};

	template <typename T>
    struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };
	template <>
	struct is_integral<signed char> { static const bool value = true; };
	template <>
	struct is_integral<short int> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long int> { static const bool value = true; };
	template <>
	struct is_integral<long long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned char> { static const bool value = true; };
	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };
}

#endif
