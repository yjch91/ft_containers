#include "ft_containers_test.hpp"

static void constructor_test()
{
	std::cout << "\033[32m[		constructor_test		]\033[0m\n";
	std::map<int, int>  default_std;
	std::map<int, int>::iterator    i_std;
    ft::map<int, int>   default_ft;
    ft::map<int, int>::iterator i_ft;
    
	for (int i = 0; i < 6; i++)
	{
		default_std.insert(std::pair<int, int>((i + 1) * 11, (i + 1) * 11));
		default_ft.insert(ft::pair<int, int>((i + 1) * 11, (i + 1) * 11));
	}

	std::cout << "default std\n";
	for (i_std = default_std.begin(); i_std != default_std.end(); i_std++)
		std::cout << "key : " << i_std->first << " value : " << i_std->second << std::endl;
	std::cout << "default ft\n";
	for (i_ft = default_ft.begin(); i_ft != default_ft.end(); i_ft++)
		std::cout << "key : " << i_ft->first << " value : " << i_ft->second << std::endl;
	std::cout << "\n";

    std::map<int, int>::iterator    std_b, std_e;
    ft::map<int, int>::iterator ft_b, ft_e;

    std_b = default_std.begin();
    std_e = default_std.end();
    ft_b = default_ft.begin();
    ft_e = default_ft.end();

	std::map<int, int> range_std(++std_b, --std_e);
	ft::map<int, int> range_ft(++ft_b, --ft_e);

	std::cout << "range std\n";
	for (i_std = range_std.begin(); i_std != range_std.end(); i_std++)
		std::cout << "key : " << i_std->first << " value : " << i_std->second << std::endl;
	std::cout << "range ft\n";
	for (i_ft = range_ft.begin(); i_ft != range_ft.end(); i_ft++)
		std::cout << "key : " << i_ft->first << " value : " << i_ft->second << std::endl;
	std::cout << "\n";

	std::map<int, int> copy_std(range_std);
	ft::map<int, int> copy_ft(range_ft);

	std::cout << "copy std\n";
	for (i_std = copy_std.begin(); i_std != copy_std.end(); i_std++)
		std::cout << "key : " << i_std->first << " value : " << i_std->second << std::endl;
	std::cout << "copy ft\n";
	for (i_ft = copy_ft.begin(); i_ft != copy_ft.end(); i_ft++)
		std::cout << "key : " << i_ft->first << " value : " << i_ft->second << std::endl;
	std::cout << "\n";

	default_std = copy_std;
	default_ft = copy_ft;
	std::cout << "assign(operator=) std\n";
	for (i_std = default_std.begin(); i_std != default_std.end(); i_std++)
		std::cout << "key : " << i_std->first << " value : " << i_std->second << std::endl;
	std::cout << "assign(operator=) ft\n";
	for (i_ft = default_ft.begin(); i_ft != default_ft.end(); i_ft++)
		std::cout << "key : " << i_ft->first << " value : " << i_ft->second << std::endl;
	std::cout << "\n";
}

static void iterators_test()
{
	std::cout << "\033[32m[		iterators_test			]\033[0m\n";
	std::map<int, int>  map_std;
	ft::map<int, int>   map_ft;

	for (int i = 0; i < 10; i++)
	{
		map_std.insert(std::pair<int, int>((i + 1) * 11, (i + 1) * 11));
		map_ft.insert(ft::pair<int, int>((i + 1) * 11, (i + 1) * 11));
	}

	// std test
	std::cout << "\033[32m[std test]\033[0m\n";
	std::cout << "map_std\n";

	std::map<int, int>::iterator    it_std;

	for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
		std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
	std::cout << "\n";

	it_std = map_std.begin();
	std::cout << "it_std : " << "key : " << it_std->first << std::endl;
	std::cout << "++it_std : " << "key : " << (++it_std)->first << std::endl;
	std::cout << "it_std++ : " << "key : " << (it_std++)->first << std::endl;
	std::cout << "it_std-- : " << "key : " << (it_std--)->first << std::endl;
	std::cout << "--it_std : " << "key : " << (--it_std)->first << std::endl;
	std::cout << "\n";

	std::map<int, int>::iterator    copy_it_std(it_std);

	std::cout << "copy_it_std : " << "key : " << copy_it_std->first << " value : " << copy_it_std->second << std::endl;
	std::cout << "\n";

	if (copy_it_std == it_std)
		std::cout << "copy_it_std == it_std" << std::endl;
	if (copy_it_std != it_std)
		std::cout << "copy_it_std != it_std" << std::endl;

	std::map<int, int>::const_iterator  cit_std = map_std.end();
	
	if (cit_std == it_std)
		std::cout << "cit_std == it_std" << std::endl;
	if (it_std != cit_std)
		std::cout << "it_std != cit_std" << std::endl;

	std::cout << "\nmap_std begin() -> end() test\n";
	for (it_std = map_std.begin(); it_std != cit_std; it_std++)
		std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";

	std::map<int, int>::reverse_iterator    rit_std(map_std.rbegin());
	std::map<int, int>::const_reverse_iterator  crit_std(map_std.rend());

	std::cout << "map_std rbegin() -> rend() test\n";
	for (rit_std = map_std.rbegin(); rit_std != crit_std; rit_std++)
		std::cout << "key : " << rit_std->first << " value : " << rit_std->second << std::endl;
    std::cout << "\n";

	rit_std = map_std.rend();

	std::map<int, int>::const_reverse_iterator  crit_std2(map_std.end());

  	std::cout << "reverse_iterator base test\n";
  	for (it_std = rit_std.base(); it_std != crit_std2.base(); ++it_std)
    	std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
  	std::cout << "\n";

	// ft test
	std::cout << "\033[32m[ft test]\033[0m\n";
	std::cout << "map_ft\n";

	ft::map<int, int>::iterator it_ft;

	for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
		std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
	std::cout << "\n";

	it_ft = map_ft.begin();
	std::cout << "it_ft : " << "key : " << it_ft->first << std::endl;
	std::cout << "++it_ft : " << "key : " << (++it_ft)->first << std::endl;
	std::cout << "it_ft++ : " << "key : " << (it_ft++)->first << std::endl;
	std::cout << "it_ft-- : " << "key : " << (it_ft--)->first << std::endl;
	std::cout << "--it_ft : " << "key : " << (--it_ft)->first << std::endl;
	std::cout << "\n";

	ft::map<int, int>::iterator copy_it_ft(it_ft);

	std::cout << "copy_it_ft : " << "key : " << copy_it_ft->first << " value : " << copy_it_ft->second << std::endl;
	std::cout << "\n";

	if (copy_it_ft == it_ft)
		std::cout << "copy_it_ft == it_ft" << std::endl;
	if (copy_it_ft != it_ft)
		std::cout << "copy_it_ft != it_ft" << std::endl;

	ft::map<int, int>::const_iterator   cit_ft = map_ft.end();
	
	if (cit_ft == it_ft)
		std::cout << "cit_ft == it_ft" << std::endl;
	if (it_ft != cit_ft)
		std::cout << "it_ft != cit_ft" << std::endl;

	std::cout << "\nmap_ft begin() -> end() test\n";
	for (it_ft = map_ft.begin(); it_ft != cit_ft; it_ft++)
		std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
	std::cout << "\n";

	ft::map<int, int>::reverse_iterator rit_ft(map_ft.rbegin());
	ft::map<int, int>::const_reverse_iterator   crit_ft(map_ft.rend());

	std::cout << "map_ft rbegin() -> rend() test\n";
	for (rit_ft = map_ft.rbegin(); rit_ft != crit_ft; rit_ft++)
		std::cout << "key : " << rit_ft->first << " value : " << rit_ft->second << std::endl;
	std::cout << "\n";

	rit_ft = map_ft.rend();

	ft::map<int, int>::const_reverse_iterator   crit_ft2(map_ft.end());

    std::cout << "reverse_iterator base test\n";
    for (it_ft = rit_ft.base(); it_ft != crit_ft2.base(); ++it_ft)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
}

static void capacity_test()
{
	std::cout << "\033[32m[		capacity_test			]\033[0m\n";
	std::map<int, int>  map_std;
	std::map<std::string, std::string>  map_std2;
	ft::map<int, int>   map_ft;
	ft::map<std::string, std::string>   map_ft2;

	if (map_std.empty())
		std::cout << "map_std is empty\n";
	if (map_ft.empty())
		std::cout << "map_ft  is empty\n";
	std::cout << "\n";

	for (int i = 0; i < 15; i++)
	{
		map_std.insert(std::pair<int, int>((i + 1) * 11, (i + 1) * 11));
		map_ft.insert(ft::pair<int, int>((i + 1) * 11, (i + 1) * 11));
	}

	std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
	for (std::map<int, int>::iterator i = map_std.begin(); i != map_std.end(); i++)
		std::cout << "key : " << i->first << " value : " << i->second << std::endl;
	std::cout << "\n";
	std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
	for (ft::map<int, int>::iterator i = map_ft.begin(); i != map_ft.end(); i++)
		std::cout << "key : " << i->first << " value : " << i->second << std::endl;
	std::cout << "\n";

	std::cout << "map_std max_size() : " << map_std.max_size() << std::endl;
	std::cout << "map_ft  max_size() : " << map_ft.max_size() << std::endl;
	std::cout << "\n";
	std::cout << "map_std2 max_size() : " << map_std2.max_size() << std::endl;
	std::cout << "map_ft2  max_size() : " << map_ft2.max_size() << std::endl;
	std::cout << "\n";
}

static void element_access_test()
{
	std::cout << "\033[32m[		element_access_test		]\033[0m\n";
	std::map<char, std::string> map_std;
	ft::map<char, std::string>  map_ft;

	map_std['a'] = "an element";
    map_std['b'] = "another element";
    map_std['c'] = map_std['b'];

    map_ft['a'] = "an element";
    map_ft['b'] = "another element";
    map_ft['c'] = map_ft['b'];

    std::cout << "\033[32moperator[]\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    std::cout << "map_std['a'] is [" << map_std['a'] << "]" << std::endl;
    std::cout << "map_std['b'] is [" << map_std['b'] << "]" << std::endl;
    std::cout << "map_std['c'] is [" << map_std['c'] << "]" << std::endl;
    std::cout << "map_std['d'] is [" << map_std['d'] << "]" << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    std::cout << "map_ft['a'] is [" << map_ft['a'] << "]" << std::endl;
    std::cout << "map_ft['b'] is [" << map_ft['b'] << "]" << std::endl;
    std::cout << "map_ft['c'] is [" << map_ft['c'] << "]" << std::endl;
    std::cout << "map_ft['d'] is [" << map_ft['d'] << "]" << std::endl;
}

static void insert_test()
{
    std::cout << "\033[32m[	    	insert_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator   it_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;

    map_std.insert(std::pair<char, int>('a', 100));
    map_std.insert(std::pair<char, int>('z', 200));

    map_ft.insert(ft::pair<char, int>('a', 100));
    map_ft.insert(ft::pair<char, int>('z', 200));

    std::cout << "\033[32mmap.insert(('a', 100)) map.insert(('z', 200))\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    std::pair<std::map<char, int>::iterator, bool>  ret_std;
    ft::pair<ft::map<char, int>::iterator, bool>   ret_ft;

    ret_std = map_std.insert(std::pair<char, int>('z', 500));
    if (ret_std.second == false)
    {
        std::cout << "map_std : element 'z' already existed ";
        std::cout << "with a value of " << ret_std.first->second << std::endl;
    }
    ret_ft = map_ft.insert(ft::pair<char, int>('z', 500));
    if (ret_ft.second == false)
    {
        std::cout << "map_ft  : element 'z' already existed ";
        std::cout << "with a value of " << ret_ft.first->second << std::endl;
    }
    std::cout << "\n";

    it_std = map_std.begin();
    it_ft = map_ft.begin();

    map_std.insert(it_std, std::pair<char, int>('b', 300));
    map_std.insert(it_std, std::pair<char, int>('c', 400));

    map_ft.insert(it_ft, ft::pair<char, int>('b', 300));
    map_ft.insert(it_ft, ft::pair<char, int>('c', 400));

    std::map<char,int>  map_std2;
    ft::map<char,int>   map_ft2;

    map_std2.insert(map_std.begin(), map_std.find('c'));
    map_ft2.insert(map_ft.begin(), map_ft.find('c'));

    std::cout << "\033[32mmap.insert(it, ('b', 300)) map.insert(it, ('c', 400)) map2.insert(map.begin(), find('c'))\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std2\n";
    std::cout << "size() : " << map_std2.size() << std::endl;
    for (it_std = map_std2.begin(); it_std != map_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft2\n";
    std::cout << "size() : " << map_ft2.size() << std::endl;
    for (it_ft = map_ft2.begin(); it_ft != map_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
}

static void erase_clear_test()
{
    std::cout << "\033[32m[	    	erase_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator    it_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;

    map_std['a'] = 10;
    map_std['b'] = 20;
    map_std['c'] = 30;
    map_std['d'] = 40;
    map_std['e'] = 50;
    map_std['f'] = 60;

    map_ft['a'] = 10;
    map_ft['b'] = 20;
    map_ft['c'] = 30;
    map_ft['d'] = 40;
    map_ft['e'] = 50;
    map_ft['f'] = 60;

    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    it_std = map_std.find('b');
    map_std.erase(it_std);
    map_std.erase('c');
    it_ft = map_ft.find('b');
    map_ft.erase(it_ft);
    map_ft.erase('c');

    it_std = map_std.find('e');
    map_std.erase(it_std, map_std.end());
    it_ft = map_ft.find('e');
    map_ft.erase(it_ft, map_ft.end());

    std::cout << "\033[32mmap.erase(find('b')) map.erase('c') map.erase(find('e'), map.end())\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    map_std.clear();
    map_ft.clear();

    std::cout << "\033[32mmap.clear()\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
}

static void swap_test()
{
    std::cout << "\033[32m[	    	swap_test	         	]\033[0m\n";
    std::map<char, int> map_std, map_std2;
    std::map<char, int>::iterator    it_std;
    ft::map<char, int>  map_ft, map_ft2;
    ft::map<char, int>::iterator    it_ft;

    map_std['x'] = 100;
    map_std['y'] = 200;
    map_std2['a'] = 11;
    map_std2['b'] = 22;
    map_std2['c'] = 33;

    map_ft['x'] = 100;
    map_ft['y'] = 200;
    map_ft2['a'] = 11;
    map_ft2['b'] = 22;
    map_ft2['c'] = 33;

    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std2\n";
    std::cout << "size() : " << map_std2.size() << std::endl;
    for (it_std = map_std2.begin(); it_std != map_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft2\n";
    std::cout << "size() : " << map_ft2.size() << std::endl;
    for (it_ft = map_ft2.begin(); it_ft != map_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    map_std.swap(map_std2);
    map_ft.swap(map_ft2);

    std::cout << "\033[32mmap.swap(map2)\033[0m\n";
    std::cout << "map_std\n";
    std::cout << "size() : " << map_std.size() << std::endl;
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std2\n";
    std::cout << "size() : " << map_std2.size() << std::endl;
    for (it_std = map_std2.begin(); it_std != map_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "size() : " << map_ft.size() << std::endl;
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft2\n";
    std::cout << "size() : " << map_ft2.size() << std::endl;
    for (it_ft = map_ft2.begin(); it_ft != map_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
}

static void comp_test()
{
    std::cout << "\033[32m[	    	comp_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator    it_std;
    std::map<char, int>::key_compare    comp_std = map_std.key_comp();
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;
    ft::map<char, int>::key_compare comp_ft = map_ft.key_comp();
    char    highest;
    

    map_std['a'] = 100;
    map_std['b'] = 200;
    map_std['c'] = 300;

    map_ft['a'] = 100;
    map_ft['b'] = 200;
    map_ft['c'] = 300;

    std::cout << "\033[32mkey_comp\033[0m\n";
    highest = map_std.rbegin()->first;
    it_std = map_std.begin();
    std::cout << "map_std\n";
    do {
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    } while (comp_std((*it_std++).first, highest));
    std::cout << "\n";
    highest = map_ft.rbegin()->first;
    it_ft = map_ft.begin();
    std::cout << "map_ft\n";
    do {
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    } while (comp_ft((*it_ft++).first, highest));
    std::cout << "\n";

    std::pair<char, int>    highest_std = *map_std.rbegin();

    std::cout << "\033[32mvalue_comp\033[0m\n";
    it_std = map_std.begin();
    std::cout << "map_std\n";
    do {
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    } while (map_std.value_comp()(*it_std++, highest_std));
    std::cout << "\n";

    ft::pair<char, int> highest_ft = *map_ft.rbegin();

    it_ft = map_ft.begin();
    std::cout << "map_ft\n";
    do {
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    } while (map_ft.value_comp()(*it_ft++, highest_ft));
    std::cout << "\n";
}

static void find_test()
{
    std::cout << "\033[32m[	    	find_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator    it_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;
    
    map_std['a'] = 50;
    map_std['b'] = 100;
    map_std['c'] = 150;
    map_std['d'] = 200;

    map_ft['a'] = 50;
    map_ft['b'] = 100;
    map_ft['c'] = 150;
    map_ft['d'] = 200;

    it_std = map_std.find('b');
    if (it_std != map_std.end())
        map_std.erase(it_std);
    it_ft = map_ft.find('b');
    if (it_ft != map_ft.end())
        map_ft.erase(it_ft);

    std::cout << "map_std\n";
    std::cout << "key : a value : " << map_std.find('a')->second << std::endl;
    std::cout << "key : c value : " << map_std.find('c')->second << std::endl;
    std::cout << "key : d value : " << map_std.find('d')->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "key : a value : " << map_ft.find('a')->second << std::endl;
    std::cout << "key : c value : " << map_ft.find('c')->second << std::endl;
    std::cout << "key : d value : " << map_ft.find('d')->second << std::endl;
    std::cout << "\n";
}

static void count_test()
{
    std::cout << "\033[32m[	    	count_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator   it_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;
    char c;

    map_std['a'] = 101;
    map_std['c'] = 202;
    map_std['f'] = 303;

    map_ft['a'] = 101;
    map_ft['c'] = 202;
    map_ft['f'] = 303;

    std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    std::cout << "map_std\n";
    for (c = 'a'; c < 'h'; c++)
    {
        std::cout << c;
        if (map_std.count(c) > 0)
            std::cout << " is an element of map_std\n";
        else 
            std::cout << " is not an element of map_std\n";
    }
    std::cout << "\n";
    std::cout << "map_ft\n";
    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (map_ft.count(c) > 0)
            std::cout << " is an element of map_ft\n";
        else 
            std::cout << " is not an element of map_ft\n";
    }
    std::cout << "\n";
}

static void bound_test()
{
    std::cout << "\033[32m[	    	bound_test	         	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator   it_std, itlow_std, itup_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft, itlow_ft, itup_ft;

    map_std['a'] = 20;
    map_std['b'] = 40;
    map_std['c'] = 60;
    map_std['d'] = 80;
    map_std['e'] = 100;

    map_ft['a'] = 20;
    map_ft['b'] = 40;
    map_ft['c'] = 60;
    map_ft['d'] = 80;
    map_ft['e'] = 100;

    std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    itlow_std = map_std.lower_bound('b');
    itup_std = map_std.upper_bound('d');
    itlow_ft = map_ft.lower_bound('b');
    itup_ft = map_ft.upper_bound('d'); 

    map_std.erase(itlow_std, itup_std);
    map_ft.erase(itlow_ft, itup_ft);

    std::cout << "\033[32mmap.erase(map.lower_bound('b'), map.upper_bound('d'))\033[0m\n";
    std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
}

static void equal_range_test()
{
    std::cout << "\033[32m[	    	equal_range_test	       	]\033[0m\n";
    std::map<char, int> map_std;
    std::map<char, int>::iterator   it_std;
    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret_std;
    ft::map<char, int>  map_ft;
    ft::map<char, int>::iterator    it_ft;
    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>    ret_ft;

    map_std['a'] = 10;
    map_std['b'] = 20;
    map_std['c'] = 30;

    map_ft['a'] = 10;
    map_ft['b'] = 20;
    map_ft['c'] = 30;

    std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
    std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    ret_std = map_std.equal_range('b');
    ret_ft = map_ft.equal_range('b');

    std::cout << "\033[32mmap.equal_range('b')\033[0m\n";

    std::cout << "map_std\n";
    std::cout << "lower bound points ";
    std::cout << "key : " << ret_std.first->first << " value : " << ret_std.first->second << '\n';
    std::cout << "upper bound points ";
    std::cout << "key : " << ret_std.second->first << " value : " << ret_std.second->second << '\n';
    std::cout << "\n";
    std::cout << "map_ft\n";
    std::cout << "lower bound points ";
    std::cout << "key : " << ret_ft.first->first << " value : " << ret_ft.first->second << '\n';
    std::cout << "upper bound points ";
    std::cout << "key : " << ret_ft.second->first << " value : " << ret_ft.second->second << '\n';
    std::cout << "\n";
}

static void other_test()
{
	std::cout << "\033[32m[		other_test			]\033[0m\n";
	std::map<int, int>  map_std, map_std2, map_std3;
    std::map<int, int>::iterator    it_std;
	ft::map<int, int>   map_ft, map_ft2, map_ft3;
    ft::map<int, int>::iterator    it_ft;

	for (int i = 0; i < 5; i++)
	{
        map_std.insert(std::pair<int, int>(i + 1, i + 1));
        map_std2.insert(std::pair<int, int>(9 - i, 9 - i));
		map_ft.insert(ft::pair<int, int>(i + 1, i + 1));
        map_ft2.insert(ft::pair<int, int>(9 - i, 9 - i));
	}
	map_std3 = map_std;
	map_ft3 = map_ft;

	std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std2\n";
    for (it_std = map_std2.begin(); it_std != map_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std3\n";
    for (it_std = map_std3.begin(); it_std != map_std3.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
	std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft2\n";
    for (it_ft = map_ft2.begin(); it_ft != map_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft3\n";
    for (it_ft = map_ft3.begin(); it_ft != map_ft3.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";
	
	std::swap(map_std, map_std2);
	ft::swap(map_ft, map_ft2);

	std::cout << "\033[32mswap test : swap(map, map2)\033[0m\n";
	std::cout << "map_std\n";
    for (it_std = map_std.begin(); it_std != map_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "map_std2\n";
    for (it_std = map_std2.begin(); it_std != map_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
	std::cout << "map_ft\n";
    for (it_ft = map_ft.begin(); it_ft != map_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "map_ft2\n";
    for (it_ft = map_ft2.begin(); it_ft != map_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    std::cout << "\033[32mstd relational operators test\033[0m\n";
	if (map_std == map_std3)
		std::cout << "map_std == map_std3\n";
	else
		std::cout << "map_std != map_std3\n";

	if (map_std2 != map_std3)
		std::cout << "map_std2 != map_std3\n";
	else
		std::cout << "map_std2 == map_std3\n";
	std::cout << "\n";

	if (map_std > map_std3)
		std::cout << "map_std > map_std3\n";
	else if (map_std3 >= map_std)
		std::cout << "map_std3 >= map_std\n";

	if (map_std2 < map_std3)
		std::cout << "map_std2 < map_std3\n";
	else if (map_std3 <= map_std2)
		std::cout << "map_std3 <= map_std2\n";
    std::cout << "\n";

    std::cout << "\033[32mft relational operators test\033[0m\n";
    if (map_ft == map_ft3)
		std::cout << "map_ft == map_ft3\n";
	else
	    std::cout << "map_ft != map_ft3\n";

	if (map_ft2 != map_ft3)
		std::cout << "map_ft2 != map_ft3\n";
	else
		std::cout << "map_ft2 == map_ft3\n";
	std::cout << "\n";

	if (map_ft > map_ft3)
		std::cout << "map_ft > map_ft3\n";
	else if (map_ft3 >= map_ft)
		std::cout << "map_ft3 >= map_ft\n";

	if (map_ft2 < map_ft3)
		std::cout << "map_ft2 < map_ft3\n";
	else if (map_ft3 <= map_ft2)
		std::cout << "map_ft3 <= map_ft2\n";
}

void map_test()
{
    std::cout << "\n\n\033[34m[		map_test			]\033[0m\n\n\n";
    constructor_test();
    iterators_test();
    capacity_test();
    element_access_test();
    insert_test();
    erase_clear_test();
    swap_test();
    comp_test();
    find_test();
    count_test();
    bound_test();
    equal_range_test();
    other_test();
}
