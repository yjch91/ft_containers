#include "ft_containers_test.hpp"

void set_test()
{
    std::cout << "\n\n\033[34m[		set_test			]\033[0m\n\n\n";
    std::set<int>   set_std;
    std::set<int>::iterator it_std;
    std::set<int>::reverse_iterator rit_std;
    ft::set<int>    set_ft;
    ft::set<int>::iterator  it_ft;
    ft::set<int>::reverse_iterator  rit_ft;

    std::vector<int>    vec;

    for (int i = 0; i < 10; i++)
    {
        set_std.insert(i);
        set_ft.insert(i);
        vec.push_back(10 + i);
    }
    
    std::set<int>   set_std2(++vec.begin(), --vec.end());
    ft::set<int>    set_ft2(++vec.begin(), --vec.end());
    std::set<int>   set_std3(set_std2);
    ft::set<int>    set_ft3(set_ft2);

    set_std2.clear();
    set_ft2.clear();

    if (set_std.empty())
		std::cout << "set_std is empty\n";
	if (set_ft.empty())
		std::cout << "set_ft  is empty\n";

    set_std2 = set_std;
    set_ft2 = set_ft;

    std::cout << "set_std  : ";
    for (it_std = set_std.begin(); it_std != set_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std.size() << "\n";
    std::cout << "set_std2 : ";
    for (it_std = set_std2.begin(); it_std != set_std2.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std2.size() << "\n";
    std::cout << "set_std3 : ";
    for (rit_std = set_std3.rbegin(); rit_std != set_std3.rend(); rit_std++)
        std::cout << *rit_std << " ";
    std::cout << "  size = " << set_std3.size() << " reverse print\n";
    std::cout << "\n";
	std::cout << "set_ft   : ";
    for (it_ft = set_ft.begin(); it_ft != set_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft.size() << "\n";
    std::cout << "set_ft2  : ";
    for (it_ft = set_ft2.begin(); it_ft != set_ft2.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft2.size() << "\n";
    std::cout << "set_ft3  : ";
    for (rit_ft = set_ft3.rbegin(); rit_ft != set_ft3.rend(); rit_ft++)
        std::cout << *rit_ft << " ";
    std::cout << "  size = " << set_ft3.size() << " reverse print\n";
    std::cout << "\n";

    set_std.insert(777);
    set_std.insert(++set_std.begin(), 42);
    it_std = set_std3.begin();
    it_std++;
    it_std++;
    it_std++;
    set_std.insert(set_std3.begin(), it_std);

    set_ft.insert(777);
    set_ft.insert(++set_ft.begin(), 42);
    it_ft = set_ft3.begin();
    it_ft++;
    it_ft++;
    it_ft++;
    set_ft.insert(set_ft3.begin(), it_ft);

    std::cout << "\033[32mset.insert(777) set.insert(set.begin(), 42) set.insert(set3.begin(), set3.begin() + 3)\033[0m\n";
    std::cout << "set_std  : ";
    for (it_std = set_std.begin(); it_std != set_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std.size() << "\n";
	std::cout << "set_ft   : ";
    for (it_ft = set_ft.begin(); it_ft != set_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft.size() << "\n";
    std::cout << "\n";

    it_std = set_std.begin();
    it_std++;
    it_std++;
    set_std.erase(it_std);
    set_std.erase(13);
    set_std.erase(++set_std.begin(), --set_std.end());

    it_ft = set_ft.begin();
    it_ft++;
    it_ft++;
    set_ft.erase(it_ft);
    set_ft.erase(13);
    set_ft.erase(++set_ft.begin(), --set_ft.end());

    std::cout << "\033[32mset.erase(set.begin() + 2) set.erase(13), set.erase(++set.begin() --set.end())\033[0m\n";
    std::cout << "set_std  : ";
    for (it_std = set_std.begin(); it_std != set_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std.size() << "\n";
	std::cout << "set_ft   : ";
    for (it_ft = set_ft.begin(); it_ft != set_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft.size() << "\n";
    std::cout << "\n";

    set_std.swap(set_std2);
    set_ft.swap(set_ft2);

    std::cout << "\033[32mset.swap(set2)\033[0m\n";
    std::cout << "set_std  : ";
    for (it_std = set_std.begin(); it_std != set_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std.size() << "\n";
    std::cout << "set_std2 : ";
    for (it_std = set_std2.begin(); it_std != set_std2.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << set_std2.size() << "\n";
    std::cout << "\n";
	std::cout << "set_ft   : ";
    for (it_ft = set_ft.begin(); it_ft != set_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft.size() << "\n";
    std::cout << "set_ft2  : ";
    for (it_ft = set_ft2.begin(); it_ft != set_ft2.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << set_ft2.size() << "\n";
}
