#ifndef FT_CONTAINERS_TEST_HPP

# define FT_CONTAINERS_TEST_HPP

#include <iostream>
#include <cmath>
#include <vector> 
#include <list>
#include <stack>
#include <queue>
#include "vector.hpp"
#include "list.hpp"
#include "stack.hpp"
#include "queue.hpp"

// operator-> test class
class   test{
	public:
		int num;
		test(int n = 0) { num = n; }
		~test() { }
};

void vector_test();
void list_test();
void stack_test();
void queue_test();

#endif
