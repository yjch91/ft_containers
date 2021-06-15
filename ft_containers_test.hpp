#ifndef FT_CONTAINERS_TEST_HPP

# define FT_CONTAINERS_TEST_HPP

#include <iostream>
#include <cmath>
#include <vector> 
#include "vector.hpp"
#include <list>
#include "list.hpp"

// operator-> test class
class   test{
	public:
		int num;
		test(int n = 0) { num = n; }
		~test() { }
};

void vector_test();
void list_test();

#endif
