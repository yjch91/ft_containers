#include "ft_containers_test.hpp"

static void	constructor_test()
{
	std::cout << "\033[32m[		constructor_test		]\033[0m\n";
	std::vector<int> default_std;
	ft::vector<int> default_ft;

	for (int i = 0; i < 10; i++)
	{
		default_std.push_back((i + 1) * 11);
		default_ft.push_back((i + 1) * 11);
	}
	std::cout << "default std :";
	for (size_t i = 0; i < default_std.size(); i++)
		std::cout << " " << default_std[i];
	std::cout << "\n";

	std::cout << "default ft  :";
	for (size_t i = 0; i < default_ft.size(); i++)
		std::cout << " " << default_ft[i];
	std::cout << "\n\n";

	std::vector<int> fill_std1(5);
	std::vector<int> fill_std2(10, 42);
	ft::vector<int> fill_ft1(5);
	ft::vector<int> fill_ft2(10, 42);

	std::cout << "fill std1 :";
	for (size_t i = 0; i < fill_std1.size(); i++)
		std::cout << " " << fill_std1[i];
	std::cout << "\n";
	std::cout << "fill ft1  :";
	for (size_t i = 0; i < fill_ft1.size(); i++)
		std::cout << " " << fill_ft1[i];
	std::cout << "\n\n";
	std::cout << "fill std2 :";
	for (size_t i = 0; i < fill_std2.size(); i++)
		std::cout << " " << fill_std2[i];
	std::cout << "\n";
	std::cout << "fill ft2  :";
	for (size_t i = 0; i < fill_ft2.size(); i++)
		std::cout << " " << fill_ft2[i];
	std::cout << "\n\n";

	std::vector<int> range_std(default_std.begin() + 1, default_std.end() - 1);
	ft::vector<int> range_ft(default_ft.begin() + 1, default_ft.end() - 1);

	std::cout << "range std :";
	for (size_t i = 0; i < range_std.size(); i++)
		std::cout << " " << range_std[i];
	std::cout << "\n";
	std::cout << "range ft  :";
	for (size_t i = 0; i < range_ft.size(); i++)
		std::cout << " " << range_ft[i];
	std::cout << "\n\n";

	std::vector<int> copy_std(range_std);
	ft::vector<int> copy_ft(range_ft);

	std::cout << "copy std :";
	for (size_t i = 0; i < copy_std.size(); i++)
		std::cout << " " << copy_std[i];
	std::cout << "\n";
	std::cout << "copy ft  :";
	for (size_t i = 0; i < copy_ft.size(); i++)
		std::cout << " " << copy_ft[i];
	std::cout << "\n\n";

	default_std = copy_std;
	default_ft = copy_ft;
	std::cout << "assign(operator=) std :";
	for (size_t i = 0; i < default_std.size(); i++)
		std::cout << " " << default_std[i];
	std::cout << "\n";
	std::cout << "assign(operator=) ft  :";
	for (size_t i = 0; i < default_ft.size(); i++)
		std::cout << " " << default_ft[i];
	std::cout << "\n\n";

}

static void	iterators_test()
{
	std::cout << "\033[32m[		iterators_test			]\033[0m\n";
	std::vector<int> vec_std;
	ft::vector<int>	vec_ft;

	for (int i = 0; i < 20; i++)
	{
		vec_std.push_back((i + 1) * 11);
		vec_ft.push_back((i + 1) * 11);
	}

	// std test
	std::cout << "\033[32m[std test]\033[0m\n";
	std::cout << "vec_std :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n\n";

	std::vector<int>::iterator it_std;
	it_std = vec_std.begin();
	std::cout << "it_std : " << *it_std << std::endl;
	it_std += 3;
	std::cout << "it_std += 3 : " << *it_std << std::endl;
	std::cout << "++it_std : " << *(++it_std) << std::endl;
	std::cout << "it_std++ : " << *(it_std++) << std::endl;
	std::cout << "it_std-- : " << *(it_std--) << std::endl;
	std::cout << "--it_std : " << *(--it_std) << std::endl;
	it_std = it_std + 2;
	std::cout << "it_std = it_std + 2 : " << *it_std << std::endl;
	it_std = it_std - 1;
	std::cout << "it_std = it_std - 5 : " << *it_std << std::endl;
	
	std::cout << "\n";
	std::vector<int>::iterator copy_it_std(it_std);
	std::cout << "copy_it_std : " << *copy_it_std << std::endl;
	it_std -= 1;
	std::cout << "it_std -= 1 : " << *it_std << std::endl;
	std::cout << "copy_it_std - it_std : " << copy_it_std - it_std << std::endl;
	std::cout << "copy_it_std[0] : " << copy_it_std[0] << std::endl;
	std::cout << "copy_it_std[1] : " << copy_it_std[1] << std::endl;
	std::cout << "it_std[0] : " << it_std[0] << std::endl;
	std::cout << "it_std[0] : " << it_std[1] << std::endl;

	std::cout << "\n";
	if (copy_it_std == it_std)
		std::cout << "copy_it_std == it_std" << std::endl;
	if (copy_it_std != it_std)
		std::cout << "copy_it_std != it_std" << std::endl;
	if (copy_it_std < it_std)
		std::cout << "copy_it_std < it_std" << std::endl;
	if (copy_it_std <= it_std)
		std::cout << "copy_it_std <= it_std" << std::endl;
	if (copy_it_std > it_std)
		std::cout << "copy_it_std > it_std" << std::endl;
	if (copy_it_std >= it_std)
		std::cout << "copy_it_std >= it_std" << std::endl;

	std::vector<int>::const_iterator cit_std = vec_std.end();
	
	if (cit_std == it_std)
		std::cout << "cit_std == it_std" << std::endl;
	if (it_std != cit_std)
		std::cout << "it_std != cit_std" << std::endl;
	if (cit_std < it_std)
		std::cout << "cit_std < it_std" << std::endl;
	if (it_std >= cit_std)
		std::cout << "it_std >= cit_std" << std::endl;
	if (cit_std > it_std)
		std::cout << "cit_std > it_std" << std::endl;
	if (it_std <= cit_std)
		std::cout << "it_std <= cit_std" << std::endl;

	std::cout << "\nvec_std begin() -> end() test :";
	for (it_std = vec_std.begin(); it_std != cit_std; it_std++)
		std::cout << " " << *it_std;
	std::cout << "\n";

	std::vector<int>::reverse_iterator rit_std(vec_std.rbegin());
	std::vector<int>::const_reverse_iterator crit_std(vec_std.rend());

	std::cout << "vec_std rbegin() -> rend() test :";
	for (rit_std = vec_std.rbegin(); rit_std != crit_std; rit_std++)
		std::cout << " " << *rit_std;
	std::cout << "\n";

	rit_std = vec_std.rend();
	std::vector<int>::const_reverse_iterator crit_std2(vec_std.end());
	//crit_std = vec_std.end();
  	std::cout << "reverse_iterator base test :";
  	for (it_std = rit_std.base(); it_std != crit_std2.base(); ++it_std)
    	std::cout << " " << *it_std;
  	std::cout << "\n\n";


	// ft test
	std::cout << "\033[32m[ft test]\033[0m\n";
	std::cout << "vec_ft :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n\n";

	ft::vector<int>::iterator it_ft;
	it_ft = vec_ft.begin();
	std::cout << "it_ft : " << *it_ft << std::endl;
	it_ft += 3;
	std::cout << "it_ft += 3 : " << *it_ft << std::endl;
	std::cout << "++it_ft : " << *(++it_ft) << std::endl;
	std::cout << "it_ft++ : " << *(it_ft++) << std::endl;
	std::cout << "it_ft-- : " << *(it_ft--) << std::endl;
	std::cout << "--it_ft : " << *(--it_ft) << std::endl;
	it_ft = it_ft + 2;
	std::cout << "it_ft = it_ft + 2 : " << *it_ft << std::endl;
	it_ft = it_ft - 1;
	std::cout << "it_ft = it_ft - 5 : " << *it_ft << std::endl;
	
	std::cout << "\n";
	ft::vector<int>::iterator copy_it_ft(it_ft);
	std::cout << "copy_it_ft : " << *copy_it_ft << std::endl;
	it_ft -= 1;
	std::cout << "it_std -= 1 : " << *it_ft << std::endl;
	std::cout << "copy_it_ft - it_std : " << copy_it_ft - it_ft << std::endl;
	std::cout << "copy_it_ft[0] : " << copy_it_ft[0] << std::endl;
	std::cout << "copy_it_ft[1] : " << copy_it_ft[1] << std::endl;
	std::cout << "it_ft[0] : " << it_ft[0] << std::endl;
	std::cout << "it_ft[0] : " << it_ft[1] << std::endl;

	std::cout << "\n";
	if (copy_it_ft == it_ft)
		std::cout << "copy_it_ft == it_ft" << std::endl;
	if (copy_it_ft != it_ft)
		std::cout << "copy_it_ft != it_ft" << std::endl;
	if (copy_it_ft < it_ft)
		std::cout << "copy_it_ft < it_ft" << std::endl;
	if (copy_it_ft <= it_ft)
		std::cout << "copy_it_ft <= it_ft" << std::endl;
	if (copy_it_ft > it_ft)
		std::cout << "copy_it_ft > it_ft" << std::endl;
	if (copy_it_ft >= it_ft)
		std::cout << "copy_it_ft >= it_ft" << std::endl;

	ft::vector<int>::const_iterator cit_ft = vec_ft.end();
	
	if (cit_ft == it_ft)
		std::cout << "cit_ft == it_ft" << std::endl;
	if (it_ft != cit_ft)
		std::cout << "it_ft != cit_ft" << std::endl;
	if (cit_ft < it_ft)
		std::cout << "cit_ft < it_ft" << std::endl;
	if (it_ft >= cit_ft)
		std::cout << "it_ft >= cit_ft" << std::endl;
	if (cit_ft > it_ft)
		std::cout << "cit_ft > it_ft" << std::endl;
	if (it_ft <= cit_ft)
		std::cout << "it_ft <= cit_ft" << std::endl;

	std::cout << "\nvec_ft begin() -> end() test :";
	for (it_ft = vec_ft.begin(); it_ft != cit_ft; it_ft++)
		std::cout << " " << *it_ft;
	std::cout << "\n";

	ft::vector<int>::reverse_iterator rit_ft(vec_ft.rbegin());
	ft::vector<int>::const_reverse_iterator crit_ft(vec_ft.rend());

	std::cout << "vec_ft rbegin() -> rend() test :";
	for (rit_ft = vec_ft.rbegin(); rit_ft != crit_ft; rit_ft++)
		std::cout << " " << *rit_ft;
	std::cout << "\n";

	rit_ft = vec_ft.rend();
	ft::vector<int>::const_reverse_iterator crit_ft2(vec_ft.end());
  	std::cout << "reverse_iterator base test :";
  	for (it_ft = rit_ft.base(); it_ft != crit_ft2.base(); ++it_ft)
    	std::cout << " " << *it_ft;
  	std::cout << "\n\n";

	//operator-> test
	std::cout << "\033[32m[operator-> test]\033[0m\n";
	std::vector<test> test_std;
	ft::vector<test> test_ft;
	test t(42);

	test_std.push_back(t);
	test_ft.push_back(t);

	std::cout << "test_std : " << test_std.begin()->num << std::endl;
	std::cout << "test_ft  : " << test_ft.begin()->num << std::endl;
	std::cout << "\n";
}

static void	capacity_test()
{
	std::cout << "\033[32m[		capacity_test			]\033[0m\n";
	std::vector<int> vec_std;
	std::vector<std::string> vec_std2;
	ft::vector<int>	vec_ft;
	ft::vector<std::string> vec_ft2;

	if (vec_std.empty())
		std::cout << "vec_std is empty\n";
	if (vec_ft.empty())
		std::cout << "vec_ft  is empty\n";
	std::cout << "\n";
	for (int i = 0; i < 15; i++)
	{
		vec_std.push_back((i + 1) * 11);
		vec_ft.push_back((i + 1) * 11);
	}
	std::cout << "vec_std :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_std size() : " << vec_std.size() << std::endl;
	std::cout << "vec_ft  :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";
	std::cout << "vec_ft  size() : " << vec_ft.size() << std::endl;
	std::cout << "\n";
	std::cout << "vec_std max_size() : " << vec_std.max_size() << std::endl;
	std::cout << "vec_ft  max_size() : " << vec_ft.max_size() << std::endl;
	std::cout << "\n";
	std::cout << "vec_std2 max_size() : " << vec_std2.max_size() << std::endl;
	std::cout << "vec_ft2  max_size() : " << vec_ft2.max_size() << std::endl;
	std::cout << "\n";
	std::cout << "vec_std capacity() : " << vec_std.capacity() << std::endl;
	std::cout << "vec_ft  capacity() : " << vec_ft.capacity() << std::endl;
	std::cout << "\n";

	std::cout << "\033[32m[reserve test]\033[0m\n";
	std::cout << "reserve(-1)\n";
	try
	{
		vec_std.reserve(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		vec_ft.reserve(-1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "reserve(0)\n";
	vec_std.reserve(0);
	vec_ft.reserve(0);
	std::cout << "vec_std capacity() : " << vec_std.capacity() << std::endl;
	std::cout << "vec_ft  capacity() : " << vec_ft.capacity() << std::endl;
	std::cout << "reserve(10)\n";
	vec_std.reserve(10);
	vec_ft.reserve(10);
	std::cout << "vec_std capacity() : " << vec_std.capacity() << std::endl;
	std::cout << "vec_ft  capacity() : " << vec_ft.capacity() << std::endl;
	std::cout << "reserve(42)\n";
	vec_std.reserve(42);
	vec_ft.reserve(42);
	std::cout << "vec_std capacity() : " << vec_std.capacity() << std::endl;
	std::cout << "vec_ft  capacity() : " << vec_ft.capacity() << std::endl;
	std::cout << "\n";

	std::cout << "\033[32mresize test : resize(5), resize(8, 100), resize(10)\033[0m\n";
	std::cout << "vec_std before :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << std::endl;
	vec_std.resize(5);
	vec_std.resize(8, 100);
	vec_std.resize(10);
	std::cout << "vec_std after :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n\n";
	std::cout << "vec_ft before :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << std::endl;
	vec_ft.resize(5);
	vec_ft.resize(8, 100);
	vec_ft.resize(10);
	std::cout << "vec_ft after :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << std::endl;
	std::cout << "\n";
}

static void	element_access_test()
{
	std::cout << "\033[32m[		element_access_test		]\033[0m\n";
	std::vector<int>	vec_std;
	ft::vector<int>	vec_ft;

	for (int i = 0; i < 12; i++)
	{
		vec_std.push_back(i + 1);
		vec_ft.push_back(i + 1);
	}
	std::cout << "vec_std :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_ft  :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n\n";
	std::cout << "vec_std[7] = " << vec_std[7] << std::endl;
	std::cout << "vec_ft[7] = " << vec_ft[7] << std::endl;
	std::cout << "vec_std.at(7) = " << vec_std.at(7) << std::endl;
	std::cout << "vec_ft.at(7) = " << vec_ft.at(7) << std::endl;
	std::cout << "vec_std.front() = " << vec_std.front() << std::endl;
	std::cout << "vec_ft.front() = " <<  vec_ft.front() << std::endl;
	std::cout << "vec_std.back() = " << vec_std.back() << std::endl;
	std::cout << "vec_ft.back() = " <<  vec_ft.back() << std::endl;

	try
	{
		std::cout << "vec_std.at(100) = " << vec_std.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "vec_ft.at(100) = " << vec_ft.at(100) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';	// error message check!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	std::cout << "\n";
}

static void	modifiers_test()
{
	std::cout << "\033[32m[		modifiers_test			]\033[0m\n";
	std::vector<int> vec_std;
	ft::vector<int>	vec_ft;

	for (int i = 0; i < 12; i++)
	{
		vec_std.push_back(i + 1);
		vec_ft.push_back(i + 1);
	}
	std::cout << "vec_std :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_ft :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";
	for (int i = 0; i < 4; i++)
	{
		vec_std.pop_back();
		vec_ft.pop_back();
	}
	std::cout << "\n\033[32mpop_back test : vec.pop_back() x 4\033[0m\n";
	std::cout << "vec_std :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_ft :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";

	std::vector<int> vec_std2;
	ft::vector<int>	vec_ft2;
	
	vec_std2.assign(20, 42);
	vec_ft2.assign(20, 42);

	std::cout << "\n\033[32mfill assign test : vec2.assign(20, 42)\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";
	
	vec_std2.assign(vec_std2.begin(), vec_std2.begin() + 5);
	vec_ft2.assign(vec_ft2.begin(), vec_ft2.begin() + 5);

	std::cout << "\n\033[32mrange assign test : vec2.assign(vec2.begin(), vec2.begin + 5)\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.insert(vec_std2.begin() + 2, 7);
	vec_ft2.insert(vec_ft2.begin() + 2, 7);

	std::cout << "\n\033[32msingle element insert test : vec2.insert(vec2.begin() + 2, 7)\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.insert(vec_std2.end(), 4, 100);
	vec_ft2.insert(vec_ft2.end(), 4, 100);

	std::cout << "\n\033[32mfill insert test : vec2.insert(vec2.end(), 4, 100)\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.insert(vec_std2.begin(), vec_std.begin(), vec_std.end());
	vec_ft2.insert(vec_ft2.begin(), vec_ft.begin(), vec_ft.end());

	std::cout << "\n\033[32mrange insert test : vec2.insert(vec2.begin(), vec.begin(), vec.end())\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.erase(vec_std2.begin() + 3);
	vec_ft2.erase(vec_ft2.begin() + 3);

	std::cout << "\n\033[32mposition erase test : vec2.erase(vec2.begin() + 3))\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.erase(vec_std2.begin() + 3, vec_std2.end() - 5);
	vec_ft2.erase(vec_ft2.begin() + 3, vec_ft2.end() - 5);
	
	std::cout << "\n\033[32miterator erase test : vec2.erase(vec2.begin() + 3, vec2.end() - 5))\033[0m\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";

	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	vec_std2.swap(vec_std);
	vec_ft2.swap(vec_ft);
	
	std::cout << "\n\033[32mswap test : vec2.swap(vec)\033[0m\n";
	std::cout << "vec_std  :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";
	std::cout << "vec_ft   :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";
	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";

	std::cout << "\n\033[32mclear test : vec2.clear()\033[0m\n";
	vec_std2.clear();
	vec_ft2.clear();
	if (vec_std2.empty())
		std::cout << "vec_std2 is empty\n";
	if (vec_ft2.empty())
		std::cout << "vec_ft2  is empty\n";
	std::cout << "vec_std2 size : " << vec_std2.size() << std::endl;
	std::cout << "vec_ft2  size : " << vec_ft2.size() << std::endl;
	std::cout << "vec_std2 capacity : " << vec_std2.capacity() << std::endl;
	std::cout << "vec_ft2  capacity : " << vec_ft2.capacity() << std::endl;
	std::cout << "\n";
}

static void	other_test()
{
	std::cout << "\033[32m[		other_test			]\033[0m\n";
	std::vector<int>	vec_std, vec_std2, vec_std3;
	ft::vector<int>	vec_ft, vec_ft2, vec_ft3;

	for (int i = 0; i < 9; i++)
	{
		vec_std.push_back(i + 1);
		vec_std2.push_back(9 - i);
		vec_ft.push_back(i + 1);
		vec_ft2.push_back(9 - i);
	}
	vec_std3 = vec_std;
	vec_ft3 = vec_ft;

	std::cout << "vec_std  :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n";
	std::cout << "vec_std3 :";
	for (size_t i = 0; i < vec_std3.size(); i++)
		std::cout << " " << vec_std3[i];
	std::cout << "\n\n";
	std::cout << "vec_ft   :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";
	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n";
	std::cout << "vec_ft3  :";
	for (size_t i = 0; i < vec_ft3.size(); i++)
		std::cout << " " << vec_ft3[i];
	std::cout << "\n";

	std::swap(vec_std, vec_std2);
	ft::swap(vec_ft, vec_ft2);

	std::cout << "\n\033[32mswap test : swap(vec, vec2)\033[0m\n";
	std::cout << "vec_std  :";
	for (size_t i = 0; i < vec_std.size(); i++)
		std::cout << " " << vec_std[i];
	std::cout << "\n";
	std::cout << "vec_std2 :";
	for (size_t i = 0; i < vec_std2.size(); i++)
		std::cout << " " << vec_std2[i];
	std::cout << "\n\n";
	std::cout << "vec_ft   :";
	for (size_t i = 0; i < vec_ft.size(); i++)
		std::cout << " " << vec_ft[i];
	std::cout << "\n";
	std::cout << "vec_ft2  :";
	for (size_t i = 0; i < vec_ft2.size(); i++)
		std::cout << " " << vec_ft2[i];
	std::cout << "\n\n";

	if (vec_std == vec_std3)
		std::cout << "vec_std == vec_std3\n";
	else
		std::cout << "vec_std != vec_std3\n";

	if (vec_std2 != vec_std3)
		std::cout << "vec_std2 != vec_std3\n";
	else
		std::cout << "vec_std2 == vec_std3\n";

	std::cout << "\n";

	if (vec_std > vec_std3)
		std::cout << "vec_std > vec_std3\n";
	else if (vec_std3 >= vec_std)
		std::cout << "vec_std3 >= vec_std\n";

	if (vec_std2 < vec_std3)
		std::cout << "vec_std2 < vec_std3\n";
	else if (vec_std3 <= vec_std2)
		std::cout << "vec_std3 <= vec_std2\n";
}

void vector_test()
{
	std::cout << "\n\n\033[32m[		vector_test			]\033[0m\n\n\n";
	constructor_test();
	iterators_test();
	capacity_test();
	element_access_test();
	modifiers_test();
	other_test();
}
