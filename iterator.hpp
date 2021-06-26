#ifndef ITERATOR_HPP

# define ITERATOR_HPP

#include "utils.hpp"

namespace ft{
    template <typename T>
    class ConstIterator;

    // class iterator
    template <typename T>
    class Iterator{
        private:
            ft::tree<T> *ptr;
            ft::tree<T> *root;
            ft::tree<T> *leaf;
        public:
            Iterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~Iterator() { }

            Iterator(const Iterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            Iterator &operator=(const Iterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            explicit Iterator(ft::tree<T> *p, ft::tree<T> *r = 0, ft::tree<T> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<T> *getPtr() const { return (ptr); }

            ft::tree<T> *getRoot() const { return (root); }

            ft::tree<T> *getLeaf() const { return (leaf); }

            void setRoot(ft::tree<T> *r) { root = r; }

            bool operator==(const Iterator &src) const { return (ptr == src.ptr); }
            bool operator==(const ConstIterator<T> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const Iterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const ConstIterator<T> &src) const { return (ptr != src.getPtr()); }

            T &operator*() const { return (ptr->val); }

            T *operator->() const { return (&ptr->val); }

            Iterator operator++(int){	// i++;
                Iterator<T>    temp = *this;

                if (ptr == leaf)
                    ptr = root->front();
                else if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
                return (temp);
            }

            Iterator &operator++(){		// ++i;
                if (ptr == leaf)
                    ptr = root->front();
                else if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
				return (*this);
			}

			Iterator operator--(int){	// i--;
				Iterator<T>    temp = *this;

                if (ptr == root->front())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (temp);
			}

			Iterator &operator--(){		// --i;
                if (ptr == root->front())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (*this);
			}
    };

    // class const_iterator
    template <typename T>
    class ConstIterator{
        private:
            ft::tree<T> *ptr;
            ft::tree<T> *root;
            ft::tree<T> *leaf;
        public:
            ConstIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~ConstIterator() { }

            ConstIterator(const ConstIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            ConstIterator(const Iterator<T> &src) : ptr(src.getPtr()), root(src.getRoot()), leaf(src.getLeaf()) { }  

            ConstIterator &operator=(const ConstIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            ConstIterator &operator=(const Iterator<T> &src){
                ptr = src.getPtr();
                root = src.getRoot();
                leaf = src.getLeaf();
                return (*this);
            }

            explicit ConstIterator(ft::tree<T> *p, ft::tree<T> *r = 0, ft::tree<T> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<T> *getPtr() const { return (ptr); }

            ft::tree<T> *getRoot() const { return (root); }

            ft::tree<T> *getLeaf() const { return (leaf); }

            void setRoot(ft::tree<T> *r) { root = r; }

            bool operator==(const ConstIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const Iterator<T> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const ConstIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const Iterator<T> &src) const { return (ptr != src.getPtr()); }

            const T &operator*() const { return (ptr->val); }

            const T *operator->() const { return (&ptr->val); }

            ConstIterator operator++(int){	// i++;
                ConstIterator<T>   temp = *this;

                if (ptr == leaf)
                    ptr = root->front();
                else if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
                return (temp);
            }

            ConstIterator &operator++(){		// ++i;
                if (ptr == leaf)
                    ptr = root->front();
                else if (ptr == root->back())
                    ptr = leaf;
                else
                    ptr = ptr->next();
				return (*this);
			}

			ConstIterator operator--(int){	// i--;
				ConstIterator<T>   temp = *this;

                if (ptr == root->front())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (temp);
			}

			ConstIterator &operator--(){		// --i;
                if (ptr == root->front())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
				return (*this);
			}
    };

    template <typename T>
    class ConstReverseIterator;

    // class reverse_iterator
    template <typename T>
    class ReverseIterator{
        private:
            ft::tree<T> *ptr;
            ft::tree<T> *root;
            ft::tree<T> *leaf;
        public:
            ReverseIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~ReverseIterator() { }

            explicit ReverseIterator(Iterator<T> it){
                ptr = it.getPtr();
                root = it.getRoot();
                leaf = it.getLeaf();
                if (root == 0)
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
                if (ptr == 0)
                    ptr = leaf;
            }

            ReverseIterator(const ReverseIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            ReverseIterator &operator=(const ReverseIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            explicit ReverseIterator(ft::tree<T> *p, ft::tree<T> *r = 0, ft::tree<T> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<T> *getPtr() const { return (ptr); }

            ft::tree<T> *getRoot() const { return (root); }

            ft::tree<T> *getLeaf() const { return (leaf); }

            void setRoot(ft::tree<T> *r) { root = r; }

            Iterator<T> base(){
                ft::tree<T> *temp = ptr;

                if (temp == leaf)
                    temp = root->front();
                else
                    temp = ptr->next();
                return (Iterator<T>(temp));
            }

            bool operator==(const ReverseIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const ConstReverseIterator<T> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const ReverseIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const ConstReverseIterator<T> &src) const { return (ptr != src.getPtr()); }

            T &operator*() const { return (ptr->val); }

            T *operator->() const { return (&ptr->val); }

            ReverseIterator operator++(int){     // i++;
                ReverseIterator<T>    temp = *this;
                
                if (ptr == leaf)
                    ptr = root->back();
                else if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
                return (temp);
            }

            ReverseIterator &operator++(){		// ++i;
                if (ptr == leaf)
                    ptr = root->back();
                else if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
				return (*this);
			}

			ReverseIterator operator--(int){	    // i--;
				ReverseIterator<T>    temp = *this;

                if (ptr == root->back())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (temp);
			}

			ReverseIterator &operator--(){		// --i;
                if (ptr == root->back())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (*this);
			}
    };

    // class reverse_const_iterator
    template <typename T>
    class ConstReverseIterator{
        private:
            ft::tree<T> *ptr;
            ft::tree<T> *root;
            ft::tree<T> *leaf;
        public:
            ConstReverseIterator(){
                ptr = 0;
                root = 0;
                leaf = 0;
            }

            ~ConstReverseIterator() { }

            explicit ConstReverseIterator(ConstIterator<T> it){
                ptr = it.getPtr();
                root = it.getRoot();
                leaf = it.getLeaf();
                if (root == 0)
                    ptr = leaf;
                if (ptr == leaf)
                    ptr = root->back();
                else
                    ptr = ptr->prev();
                if (ptr == 0)
                    ptr = leaf;
            }

            ConstReverseIterator(const ConstReverseIterator &src) : ptr(src.ptr), root(src.root), leaf(src.leaf) { }

            ConstReverseIterator(const ReverseIterator<T> &src) : ptr(src.getPtr()), root(src.getRoot()), leaf(src.getLeaf()) { }

            ConstReverseIterator &operator=(const ConstReverseIterator &src){
                ptr = src.ptr;
                root = src.root;
                leaf = src.leaf;
                return (*this);
            }

            ConstReverseIterator &operator=(const ReverseIterator<T> &src){
                ptr = src.getPtr();
                root = src.getRoot();
                leaf = src.getLeaf();
                return (*this);
            }

            explicit ConstReverseIterator(ft::tree<T> *p, ft::tree<T> *r = 0, ft::tree<T> *l = 0) : ptr(p), root(r), leaf(l) { }

            ft::tree<T> *getPtr() const { return (ptr); }

            ft::tree<T> *getRoot() const { return (root); }

            ft::tree<T> *getLeaf() const { return (leaf); }

            void setRoot(ft::tree<T> *r) { root = r; }

            ConstIterator<T> base(){
                ft::tree<T> *temp = ptr;

                if (temp == leaf)
                    temp = root->front();
                else
                    temp = ptr->next();
                return (ConstIterator<T>(temp));
            }

            bool operator==(const ConstReverseIterator &src) const { return (ptr == src.ptr); }
            bool operator==(const ReverseIterator<T> &src) const { return (ptr == src.getPtr()); }

            bool operator!=(const ConstReverseIterator &src) const { return (ptr != src.ptr); }
            bool operator!=(const ReverseIterator<T> &src) const { return (ptr != src.getPtr()); }

            const T &operator*() const { return (ptr->val); }

            const T *operator->() const { return (&ptr->val); }

            ConstReverseIterator operator++(int){    // i++;
                ConstReverseIterator<T>    temp = *this;

                if (ptr == leaf)
                    ptr = root->back();
                else if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
                return (temp);
            }

            ConstReverseIterator &operator++(){		// ++i;
                if (ptr == leaf)
                    ptr = root->back();
                else if (ptr == root->front())
                    ptr = leaf;
                else
                    ptr = ptr->prev();
				return (*this);
			}

			ConstReverseIterator operator--(int){    // i--;
				ConstReverseIterator<T>    temp = *this;

                if (ptr == root->back())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (temp);
			}

			ConstReverseIterator &operator--(){      // --i;
                if (ptr == root->back())
                    ptr = leaf;
                else if (ptr == leaf)
                    ptr = root->front();
                else
                    ptr = ptr->next();
				return (*this);
			}
    };
}

#endif
