#ifndef FT_CONTAINERS_TEST_HPP

# define FT_CONTAINERS_TEST_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include "vector.hpp"
#include "list.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include <set>
#include "set.hpp"
#include "multiset.hpp"
#include "multimap.hpp"

// operator-> test class
class   test{
	public:
		int num;
		test(int n = 0) { num = n; }
		~test() { }
};

void vector_test();
void list_test();
void map_test();
void stack_test();
void queue_test();
void set_test();
void multiset_test();
void multimap_test();

#endif
