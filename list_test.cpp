#include "ft_containers_test.hpp"

static void constructor_test()
{
	std::cout << "\033[32m[		constructor_test		]\033[0m\n";
	std::list<int>  default_std;
	std::list<int>::iterator    i_std;
    ft::list<int>   default_ft;
    ft::list<int>::iterator i_ft;
    
	for (int i = 0; i < 10; i++)
	{
		default_std.push_back((i + 1) * 11);
		default_ft.push_back((i + 1) * 11);
	}
	std::cout << "default std :";
	for (i_std = default_std.begin(); i_std != default_std.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";

	std::cout << "default ft  :";
	for (i_ft = default_ft.begin(); i_ft != default_ft.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";

	std::list<int>  fill_std1(5);
	std::list<int>  fill_std2(10, 42);
	ft::list<int>   fill_ft1(5);
	ft::list<int>   fill_ft2(10, 42);

	std::cout << "fill std1 :";
	for (i_std = fill_std1.begin(); i_std != fill_std1.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";
	std::cout << "fill ft1  :";
	for (i_ft = fill_ft1.begin(); i_ft != fill_ft1.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";
	std::cout << "fill std2 :";
	for (i_std = fill_std2.begin(); i_std != fill_std2.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";
	std::cout << "fill ft2  :";
	for (i_ft = fill_ft2.begin(); i_ft != fill_ft2.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";

    std::list<int>::iterator    std_b, std_e;
    ft::list<int>::iterator ft_b, ft_e;

    std_b = default_std.begin();
    std_e = default_std.end();
    ft_b = default_ft.begin();
    ft_e = default_ft.end();

	std::list<int> range_std(++std_b, --std_e);
	ft::list<int> range_ft(++ft_b, --ft_e);

	std::cout << "range std :";
	for (i_std = range_std.begin(); i_std != range_std.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";
	std::cout << "range ft  :";
	for (i_ft = range_ft.begin(); i_ft != range_ft.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";

	std::list<int> copy_std(range_std);
	ft::list<int> copy_ft(range_ft);

	std::cout << "copy std :";
	for (i_std = copy_std.begin(); i_std != copy_std.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";
	std::cout << "copy ft  :";
	for (i_ft = copy_ft.begin(); i_ft != copy_ft.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";

	default_std = copy_std;
	default_ft = copy_ft;
	std::cout << "assign(operator=) std :";
	for (i_std = default_std.begin(); i_std != default_std.end(); i_std++)
		std::cout << " " << *i_std;
	std::cout << "\n";
	std::cout << "assign(operator=) ft  :";
	for (i_ft = default_ft.begin(); i_ft != default_ft.end(); i_ft++)
		std::cout << " " << *i_ft;
	std::cout << "\n\n";
}

static void iterators_test()
{
	std::cout << "\033[32m[		iterators_test			]\033[0m\n";
	std::list<int>  lst_std;
	ft::list<int>   lst_ft;

	for (int i = 0; i < 20; i++)
	{
		lst_std.push_back((i + 1) * 11);
		lst_ft.push_back((i + 1) * 11);
	}

	// std test
	std::cout << "\033[32m[std test]\033[0m\n";
	std::cout << "lst_std :";

	std::list<int>::iterator    it_std;

	for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
		std::cout << " " << *it_std;
	std::cout << "\n\n";

	it_std = lst_std.begin();
	std::cout << "it_std : " << *it_std << std::endl;
	std::cout << "++it_std : " << *(++it_std) << std::endl;
	std::cout << "it_std++ : " << *(it_std++) << std::endl;
	std::cout << "it_std-- : " << *(it_std--) << std::endl;
	std::cout << "--it_std : " << *(--it_std) << std::endl;
	std::cout << "\n";

	std::list<int>::iterator    copy_it_std(it_std);

	std::cout << "copy_it_std : " << *copy_it_std << std::endl;
	std::cout << "\n";

	if (copy_it_std == it_std)
		std::cout << "copy_it_std == it_std" << std::endl;
	if (copy_it_std != it_std)
		std::cout << "copy_it_std != it_std" << std::endl;

	std::list<int>::const_iterator  cit_std = lst_std.end();
	
	if (cit_std == it_std)
		std::cout << "cit_std == it_std" << std::endl;
	if (it_std != cit_std)
		std::cout << "it_std != cit_std" << std::endl;

	std::cout << "\nlst_std begin() -> end() test :";
	for (it_std = lst_std.begin(); it_std != cit_std; it_std++)
		std::cout << " " << *it_std;
	std::cout << "\n";

	std::list<int>::reverse_iterator    rit_std(lst_std.rbegin());
	std::list<int>::const_reverse_iterator  crit_std(lst_std.rend());

	std::cout << "lst_std rbegin() -> rend() test :";
	for (rit_std = lst_std.rbegin(); rit_std != crit_std; rit_std++)
		std::cout << " " << *rit_std;
	std::cout << "\n";

	rit_std = lst_std.rend();

	std::list<int>::const_reverse_iterator  crit_std2(lst_std.end());

  	std::cout << "reverse_iterator base test :";
  	for (it_std = rit_std.base(); it_std != crit_std2.base(); ++it_std)
    	std::cout << " " << *it_std;
  	std::cout << "\n\n";

	// ft test
	std::cout << "\033[32m[ft test]\033[0m\n";
	std::cout << "lst_ft :";

	ft::list<int>::iterator it_ft;

	for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
		std::cout << " " << *it_ft;
	std::cout << "\n\n";

	it_ft = lst_ft.begin();
	std::cout << "it_ft : " << *it_ft << std::endl;
	std::cout << "++it_ft : " << *(++it_ft) << std::endl;
	std::cout << "it_ft++ : " << *(it_ft++) << std::endl;
	std::cout << "it_ft-- : " << *(it_ft--) << std::endl;
	std::cout << "--it_ft : " << *(--it_ft) << std::endl;
	std::cout << "\n";

	ft::list<int>::iterator copy_it_ft(it_ft);

	std::cout << "copy_it_ft : " << *copy_it_ft << std::endl;
	std::cout << "\n";

	if (copy_it_ft == it_ft)
		std::cout << "copy_it_ft == it_ft" << std::endl;
	if (copy_it_ft != it_ft)
		std::cout << "copy_it_ft != it_ft" << std::endl;

	ft::list<int>::const_iterator   cit_ft = lst_ft.end();
	
	if (cit_ft == it_ft)
		std::cout << "cit_ft == it_ft" << std::endl;
	if (it_ft != cit_ft)
		std::cout << "it_ft != cit_ft" << std::endl;

	std::cout << "\nlst_ft begin() -> end() test :";
	for (it_ft = lst_ft.begin(); it_ft != cit_ft; it_ft++)
		std::cout << " " << *it_ft;
	std::cout << "\n";

	ft::list<int>::reverse_iterator rit_ft(lst_ft.rbegin());
	ft::list<int>::const_reverse_iterator   crit_ft(lst_ft.rend());

	std::cout << "lst_ft rbegin() -> rend() test :";
	for (rit_ft = lst_ft.rbegin(); rit_ft != crit_ft; rit_ft++)
		std::cout << " " << *rit_ft;
	std::cout << "\n";

	rit_ft = lst_ft.rend();

	ft::list<int>::const_reverse_iterator   crit_ft2(lst_ft.end());

  	std::cout << "reverse_iterator base test :";
  	for (it_ft = rit_ft.base(); it_ft != crit_ft2.base(); ++it_ft)
    	std::cout << " " << *it_ft;
  	std::cout << "\n\n";

	// operator-> test
	std::cout << "\033[32m[operator-> test]\033[0m\n";
	std::list<test> test_std;
	ft::list<test>  test_ft;
	test    t(42);

	test_std.push_back(t);
	test_ft.push_back(t);

	std::cout << "test_std : " << test_std.begin()->num << std::endl;
	std::cout << "test_ft  : " << test_ft.begin()->num << std::endl;
	std::cout << "\n";
}

static void capacity_test()
{
	std::cout << "\033[32m[		capacity_test			]\033[0m\n";
	std::list<int>  lst_std;
	std::list<std::string>  lst_std2;
	ft::list<int>   lst_ft;
	ft::list<std::string>   lst_ft2;

	if (lst_std.empty())
		std::cout << "lst_std is empty\n";
	if (lst_ft.empty())
		std::cout << "lst_ft  is empty\n";
	std::cout << "\n";
	for (int i = 0; i < 15; i++)
	{
		lst_std.push_back((i + 1) * 11);
		lst_ft.push_back((i + 1) * 11);
	}
	std::cout << "lst_std :";
	for (std::list<int>::iterator i = lst_std.begin(); i != lst_std.end(); i++)
		std::cout << " " << *i;
	std::cout << "\n";
	std::cout << "lst_std size() : " << lst_std.size() << std::endl;
	std::cout << "lst_ft  :";
	for (ft::list<int>::iterator i = lst_ft.begin(); i != lst_ft.end(); i++)
		std::cout << " " << *i;
	std::cout << "\n";
	std::cout << "lst_ft  size() : " << lst_ft.size() << std::endl;
	std::cout << "\n";
	std::cout << "lst_std max_size() : " << lst_std.max_size() << std::endl;
	std::cout << "lst_ft  max_size() : " << lst_ft.max_size() << std::endl;
	std::cout << "\n";
	std::cout << "lst_std2 max_size() : " << lst_std2.max_size() << std::endl;
	std::cout << "lst_ft2  max_size() : " << lst_ft2.max_size() << std::endl;
	std::cout << "\n";
}

static void	element_access_test()
{
	std::cout << "\033[32m[		element_access_test		]\033[0m\n";
	std::list<int>  lst_std;
	ft::list<int>   lst_ft;

	for (int i = 0; i < 12; i++)
	{
		lst_std.push_back(i + 1);
		lst_ft.push_back(i + 1);
	}
	std::cout << "lst_std :";
	for (std::list<int>::iterator i = lst_std.begin(); i != lst_std.end(); i++)
		std::cout << " " << *i;
	std::cout << "\n";
	std::cout << "lst_ft  :";
	for (ft::list<int>::iterator i = lst_ft.begin(); i != lst_ft.end(); i++)
		std::cout << " " << *i;
	std::cout << "\n\n";
	std::cout << "lst_std.front() = " << lst_std.front() << std::endl;
	std::cout << "lst_ft.front() = " <<  lst_ft.front() << std::endl;
	std::cout << "lst_std.back() = " << lst_std.back() << std::endl;
	std::cout << "lst_ft.back() = " <<  lst_ft.back() << std::endl;
    std::cout << "\n";
}

static void assign_test()
{
    std::cout << "\033[32m[	       	assign_test	        	]\033[0m\n";
    std::list<int>  first_std;
    std::list<int>  second_std;
    std::list<int>::iterator    it_std;
    ft::list<int>   first_ft;
    ft::list<int>   second_ft;
    ft::list<int>::iterator it_ft;

    first_ft.assign(7, 42);
    first_std.assign(7, 42);

    std::cout << "\033[32mfirst.assign(7, 42)\033[0m\n";
    std::cout << "first_std :";
    it_std = first_std.begin();
    while (it_std != first_std.end())
        std::cout << " " << *it_std++;
    std::cout << "      size = " << first_std.size() << "\n";
    std::cout << "first_ft  :";
    it_ft = first_ft.begin();
    while (it_ft != first_ft.end())
        std::cout << " " << *it_ft++;
    std::cout << "      size = " << first_ft.size() << "\n\n";

    second_std.assign(first_std.begin(),first_std.end());
    second_ft.assign(first_ft.begin(),first_ft.end());

    std::cout << "\033[32msecond.assign(first.begin(), first.end())\033[0m\n";
    std::cout << "second_std :";
    it_std = second_std.begin();
    while (it_std != second_std.end())
        std::cout << " " << *it_std++;
    std::cout << "      size = " << second_std.size() << "\n";
    std::cout << "second_ft  :";
    it_ft = second_ft.begin();
    while (it_ft != second_ft.end())
        std::cout << " " << *it_ft++;
    std::cout << "      size = " << second_ft.size() << "\n\n";

    int myints[] = {112, 114, 119};

    first_std.assign(myints, myints + 3);
    first_ft.assign(myints, myints + 3);

    std::cout << "\033[32mfirst.assign(myints, myints + 3)\033[0m\n";
    std::cout << "myints = {112, 114, 119}\n\n";
    std::cout << "first_std :";
    it_std = first_std.begin();
    while (it_std != first_std.end())
        std::cout << " " << *it_std++;
    std::cout << "      size = " << first_std.size() << "\n";
    std::cout << "first_ft  :";
    it_ft = first_ft.begin();
    while (it_ft != first_ft.end())
        std::cout << " " << *it_ft++;
    std::cout << "      size = " << first_ft.size() << "\n\n";
}

static void push_pop_test()
{
    std::cout << "\033[32m[	       	push_pop_test	        	]\033[0m\n";
    std::list<int>  lst_std;
    std::list<int>::iterator    it_std;
    ft::list<int>   lst_ft;
    ft::list<int>::iterator it_ft;

    for(int i = 0; i < 5; i++)
    {
        lst_std.push_back(i);
        lst_ft.push_back(i);
    }
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.push_front(7);
    lst_std.push_front(77);
    lst_std.push_front(777);
    lst_ft.push_front(7);
    lst_ft.push_front(77);
    lst_ft.push_front(777);

    std::cout << "\033[32mlst.push_front(7) lst.push_front(77) lst.push_front(777)\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.push_back(100);
    lst_std.push_back(200);
    lst_std.push_back(300);
    lst_ft.push_back(100);
    lst_ft.push_back(200);
    lst_ft.push_back(300);

    std::cout << "\033[32mlst.push_back(100) lst.push_back(200) lst.push_back(300)\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.pop_front();
    lst_std.pop_front();
    lst_ft.pop_front();
    lst_ft.pop_front();

    std::cout << "\033[32mlst.pop_front() lst.pop_front()\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";
    
    lst_std.pop_back();
    lst_std.pop_back();
    lst_std.pop_back();
    lst_ft.pop_back();
    lst_ft.pop_back();
    lst_ft.pop_back();

    std::cout << "\033[32mlst.pop_back() lst.pop_back() lst.pop_back()\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";
}

static void insert_erase_clear_test()
{
    std::cout << "\033[32m[             insert_erase_clear_test	   	]\033[0m\n";
    std::list<int>  lst_std;
    std::list<int>::iterator    it_std;
    ft::list<int>   lst_ft;
    ft::list<int>::iterator it_ft;

    lst_std.insert(lst_std.begin(), 42);
    lst_ft.insert(lst_ft.begin(), 42);

    std::cout << "\033[32mlst.insert(lst.begin(), 42)\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.insert(lst_std.begin(), 5, 7);
    lst_ft.insert(lst_ft.begin(), 5, 7);

    std::cout << "\033[32mlst.insert(lst.begin(), 5, 7)\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    it_std = lst_std.end();
    it_std--;
    it_ft = lst_ft.end();
    it_ft--;
    lst_std.erase(it_std);
    lst_ft.erase(it_ft);

    std::cout << "\033[32mlst.erase(lst.end() - 1)\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    std::list<int>  temp;
    for (int i = 1; i <= 10; i++)
        temp.push_front(i * -1);
    std::cout << "temp :";
    for (it_std = temp.begin(); it_std != temp.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";

    lst_std.insert(lst_std.end(), temp.begin(), temp.end());
    lst_ft.insert(lst_ft.end(), temp.begin(), temp.end());

    std::cout << "\033[32mlst.insert(lst.end(), temp.begin(), temp.end())\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    it_std = lst_std.begin();
    for (int i = 0; i < 6; i++)
        it_std++;
    it_ft = lst_ft.begin();
    for (int i = 0; i < 6; i++)
        it_ft++;
    lst_std.erase(it_std, lst_std.end());
    lst_ft.erase(it_ft, lst_ft.end());

    std::cout << "\033[32mlst.erase(lst.begin() + 6, lst.end())\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.clear();
    lst_ft.clear();

    std::cout << "\033[32mlst.clear()\033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";
}

static void swap_test()
{
    std::cout << "\033[32m[	       	swap_test	        	]\033[0m\n";
    std::list<int>  first_std(3, 42);
    std::list<int>  second_std(5, 99);
    std::list<int>::iterator    it_std;
    ft::list<int>   first_ft(3, 42);
    ft::list<int>   second_ft(5, 99);
    ft::list<int>::iterator it_ft;

    std::cout << "first_std  :";
    for (it_std = first_std.begin(); it_std != first_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << first_std.size() << "\n";

    std::cout << "second_std :";
    for (it_std = second_std.begin(); it_std != second_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << second_std.size() << "\n\n";

    std::cout << "first_ft   :";
    for (it_ft = first_ft.begin(); it_ft != first_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << first_ft.size() << "\n";

    std::cout << "second_ft  :";
    for (it_ft = second_ft.begin(); it_ft != second_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << second_ft.size() << "\n\n";

    first_std.swap(second_std);
    first_ft.swap(second_ft);

    std::cout << "\033[32mfirst.swap(second)\033[0m\n";
    std::cout << "first_std  :";
    for (it_std = first_std.begin(); it_std != first_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << first_std.size() << "\n";

    std::cout << "second_std :";
    for (it_std = second_std.begin(); it_std != second_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << second_std.size() << "\n\n";

    std::cout << "first_ft   :";
    for (it_ft = first_ft.begin(); it_ft != first_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << first_ft.size() << "\n";

    std::cout << "second_ft  :";
    for (it_ft = second_ft.begin(); it_ft != second_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << second_ft.size() << "\n\n";
}

static void resize_test()
{
    std::cout << "\033[32m[	       	resize_test	        	]\033[0m\n";
    std::list<int>  lst_std;
    std::list<int>::iterator    it_std;
    ft::list<int>   lst_ft;
    ft::list<int>::iterator it_ft;

    for (int i = 1; i < 10; ++i)
    {
        lst_std.push_back(i);
        lst_ft.push_back(i);
    }

    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.resize(5);
    lst_std.resize(8,100);
    lst_std.resize(12);

    lst_ft.resize(5);
    lst_ft.resize(8,100);
    lst_ft.resize(12);

    std::cout << "\033[32mlst.resize(5) lst.resize(8, 100) lst.resize(12) \033[0m\n";
    std::cout << "lst_std :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft  :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

}

static void splice_test()
{
    std::cout << "\033[32m[	       	splice_test	        	]\033[0m\n";
    std::list<int>  lst_std, lst_std2;
    std::list<int>::iterator    it_std, it_std2;
    ft::list<int>   lst_ft, lst_ft2;
    ft::list<int>::iterator it_ft, it_ft2;

    for (int i = 1; i <= 4; ++i)
    {
        lst_std.push_back(i);
        lst_ft.push_back(i);
    }

    for (int i = 1; i <= 3; ++i)
    {
        lst_std2.push_back(i * 10);
        lst_ft2.push_back(i * 10);
    }

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";

    it_std = lst_std.begin();
    it_std++;
    it_std2 = it_std;
    lst_std.splice(it_std, lst_std2);
    it_ft = lst_ft.begin();
    it_ft++;
    it_ft2 = it_ft;
    lst_ft.splice(it_ft, lst_ft2);

    std::cout << "\033[32mlst.splice(lst.begin() + 1, lst2)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";

    lst_std2.splice(lst_std2.begin(), lst_std, it_std2);
    lst_ft2.splice(lst_ft2.begin(), lst_ft, it_ft2);

    std::cout << "\033[32mlst2.splice(lst2.begin(), lst, it2)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";

    it_std = lst_std.begin();
    for (int i = 0; i < 3; i++)
        it_std++;
    it_ft = lst_ft.begin();
    for (int i = 0; i < 3; i++)
        it_ft++;

    lst_std.splice(lst_std.begin(), lst_std, it_std, lst_std.end());
    lst_ft.splice(lst_ft.begin(), lst_ft, it_ft, lst_ft.end());

    std::cout << "\033[32mlst.splice(lst.begin(), lst, lst.begin() + 3, lst.end())\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";
}

bool single_digit(const int &value) { return (value < 10); }

struct is_odd{
    bool operator()(const int &value) { return (value % 2) == 1; }
};

static void remove_test()
{
    std::cout << "\033[32m[	       	remove_test	        	]\033[0m\n";
    int myints[] = { 15, 42, 36, 7, 17, 20, 39, 4, 1 };
    std::list<int>  lst_std(myints, myints + 9);
    std::list<int>::iterator    it_std;
    ft::list<int>   lst_ft(myints, myints + 9);
    ft::list<int>::iterator it_ft;

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.remove(42);
    lst_ft.remove(42);

    std::cout << "\033[32mlst.remove(42)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.remove_if(single_digit);
    lst_ft.remove_if(single_digit);

    std::cout << "\033[32mlst.remove_if(single_digit)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.remove_if(is_odd());
    lst_ft.remove_if(is_odd());

    std::cout << "\033[32mlst.remove_if(is_odd())\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";
}

bool same_integral_part(double first, double second) { return (int(first) == int(second)); }

struct is_near{
    bool operator()(double first, double second) { return (fabs(first-second) < 5.0); }
};

static void unique_test()
{
    std::cout << "\033[32m[	       	unique_test	        	]\033[0m\n";
    double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
    std::list<double>  lst_std(mydoubles, mydoubles + 10);
    std::list<double>::iterator    it_std;
    ft::list<double>   lst_ft(mydoubles, mydoubles + 10);
    ft::list<double>::iterator it_ft;

    lst_std.sort();
    lst_ft.sort();

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.unique();
    lst_ft.unique();

    std::cout << "\033[32mlst.unique()\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.unique(same_integral_part);
    lst_ft.unique(same_integral_part);

    std::cout << "\033[32mlst.unique(same_integral_part)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";

    lst_std.unique(is_near());
    lst_ft.unique(is_near());

    std::cout << "\033[32mlst.unique(is_near())\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n\n";
}

bool mycomparison(double first, double second) { return (int(first) < int(second)); }

static void merge_test()
{
    std::cout << "\033[32m[	       	merge_test	        	]\033[0m\n";
    std::list<double>  lst_std, lst_std2;
    std::list<double>::iterator    it_std;
    ft::list<double>   lst_ft, lst_ft2;
    ft::list<double>::iterator it_ft;

    lst_std.push_back(2.2);
    lst_std.push_back(2.9);
    lst_std.push_back(3.1);

    lst_ft.push_back(2.2);
    lst_ft.push_back(2.9);
    lst_ft.push_back(3.1);

    lst_std2.push_back(1.4);
    lst_std2.push_back(3.7);
    lst_std2.push_back(7.1);

    lst_ft2.push_back(1.4);
    lst_ft2.push_back(3.7);
    lst_ft2.push_back(7.1);

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);

    std::cout << "\033[32mlst.merge(lst2)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";

    lst_std2.push_back(2.1);
    lst_std2.push_back(4.2);

    lst_ft2.push_back(2.1);
    lst_ft2.push_back(4.2);

    lst_std.merge(lst_std2, mycomparison);
    lst_ft.merge(lst_ft2, mycomparison);

    std::cout << "\033[32mlst2.push_back(2.1) lst2.push_back(4.2) lst.merge(lst2, mycomparison)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std.size() << "\n";
    std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "      size = " << lst_std2.size() << "\n\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft.size() << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "      size = " << lst_ft2.size() << "\n\n";
}

bool compare_nocase(const std::string &first, const std::string &second)
{
  unsigned int  i = 0;
  while ((i < first.length()) && (i < second.length()))
  {
    if (tolower(first[i]) < tolower(second[i]))
        return true;
    else if(tolower(first[i]) > tolower(second[i]))
        return false;
    ++i;
  }
  return (first.length() < second.length());
}

static void sort_test()
{
    std::cout << "\033[32m[	       	sort_test	        	]\033[0m\n";
    std::list<std::string>  lst_std;
    std::list<std::string>::iterator    it_std;
    ft::list<std::string>   lst_ft;
    ft::list<std::string>::iterator it_ft;

    lst_std.push_back("one");
    lst_std.push_back("two");
    lst_std.push_back("Three");

    lst_ft.push_back("one");
    lst_ft.push_back("two");
    lst_ft.push_back("Three");

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";

    lst_std.sort();
    lst_ft.sort();

    std::cout << "\033[32mlst.sort()\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";

    lst_std.sort(compare_nocase);
    lst_ft.sort(compare_nocase);

    std::cout << "\033[32mlst.sort(compare_nocase)\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";
}

static void reverse_test()
{
    std::cout << "\033[32m[	       	reverse_test	        	]\033[0m\n";
    std::list<int>  lst_std;
    std::list<int>::iterator    it_std;
    ft::list<int>   lst_ft;
    ft::list<int>::iterator it_ft;

    for (int i = 0; i < 9; i++)
    {
        lst_std.push_back(i + 1);
        lst_ft.push_back(i + 1);
    }

    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";

    lst_std.reverse();
    lst_ft.reverse();

    std::cout << "\033[32mlst.reverse()\033[0m\n";
    std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
    std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";
}

static void other_test()
{
	std::cout << "\033[32m[		other_test			]\033[0m\n";
	std::list<int>  lst_std, lst_std2, lst_std3;
    std::list<int>::iterator    it_std;
	ft::list<int>   lst_ft, lst_ft2, lst_ft3;
    ft::list<int>::iterator    it_ft;

	for (int i = 0; i < 9; i++)
	{
		lst_std.push_back(i + 1);
		lst_std2.push_back(9 - i);
		lst_ft.push_back(i + 1);
		lst_ft2.push_back(9 - i);
	}
	lst_std3 = lst_std;
	lst_ft3 = lst_ft;

	std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
	std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
	std::cout << "lst_std3 :";
    for (it_std = lst_std3.begin(); it_std != lst_std3.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n\n";
	std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n";
    std::cout << "lst_ft3  :";
    for (it_ft = lst_ft3.begin(); it_ft != lst_ft3.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n";
	
	std::swap(lst_std, lst_std2);
	ft::swap(lst_ft, lst_ft2);

	std::cout << "\n\033[32mswap test : swap(lst, lst2)\033[0m\n";
	std::cout << "lst_std  :";
    for (it_std = lst_std.begin(); it_std != lst_std.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n";
	std::cout << "lst_std2 :";
    for (it_std = lst_std2.begin(); it_std != lst_std2.end(); it_std++)
        std::cout << " " << *it_std;
    std::cout << "\n\n";
	std::cout << "lst_ft   :";
    for (it_ft = lst_ft.begin(); it_ft != lst_ft.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n";
    std::cout << "lst_ft2  :";
    for (it_ft = lst_ft2.begin(); it_ft != lst_ft2.end(); it_ft++)
        std::cout << " " << *it_ft;
    std::cout << "\n\n";

    std::cout << "\033[32mstd relational operators test\033[0m\n";
	if (lst_std == lst_std3)
		std::cout << "lst_std == lst_std3\n";
	else
		std::cout << "lst_std != lst_std3\n";

	if (lst_std2 != lst_std3)
		std::cout << "lst_std2 != lst_std3\n";
	else
		std::cout << "lst_std2 == lst_std3\n";

	std::cout << "\n";

	if (lst_std > lst_std3)
		std::cout << "lst_std > lst_std3\n";
	else if (lst_std3 >= lst_std)
		std::cout << "lst_std3 >= lst_std\n";

	if (lst_std2 < lst_std3)
		std::cout << "lst_std2 < lst_std3\n";
	else if (lst_std3 <= lst_std2)
		std::cout << "lst_std3 <= lst_std2\n";
    
    std::cout << "\n";

    std::cout << "\033[32mft relational operators test\033[0m\n";
    if (lst_ft == lst_ft3)
		std::cout << "lst_ft == lst_ft3\n";
	else
		std::cout << "lst_ft != lst_ft3\n";

	if (lst_ft2 != lst_ft3)
		std::cout << "lst_ft2 != lst_ft3\n";
	else
		std::cout << "lst_ft2 == lst_ft3\n";

	std::cout << "\n";

	if (lst_ft > lst_ft3)
		std::cout << "lst_ft > lst_ft3\n";
	else if (lst_ft3 >= lst_ft)
		std::cout << "lst_ft3 >= lst_ft\n";

	if (lst_ft2 < lst_ft3)
		std::cout << "lst_ft2 < lst_ft3\n";
	else if (lst_ft3 <= lst_ft2)
		std::cout << "lst_ft3 <= lst_ft2\n";
}

void list_test()
{
    std::cout << "\n\n\033[34m[		list_test			]\033[0m\n\n\n";
    constructor_test();
    iterators_test();
    capacity_test();
    element_access_test();
    assign_test();
    push_pop_test();
    insert_erase_clear_test();
    swap_test();
    resize_test();
    splice_test();
    remove_test();
    unique_test();
    merge_test();
    sort_test();
    reverse_test();
    other_test();
}
