#include "ft_containers_test.hpp"

void multiset_test()
{
    std::cout << "\n\n\033[34m[		multiset_test			]\033[0m\n\n\n";
    std::multiset<int>   mset_std;
    std::multiset<int>::iterator it_std;
    std::multiset<int>::reverse_iterator rit_std;
    ft::multiset<int>    mset_ft;
    ft::multiset<int>::iterator  it_ft;
    ft::multiset<int>::reverse_iterator  rit_ft;

    std::vector<int>    vec;

    for (int i = 0; i < 10; i++)
    {
        mset_std.insert(i);
        mset_ft.insert(i);
        vec.push_back(10 + i);
    }

    for (int i = 0; i < 5; i++)
    {
        mset_std.insert(i);
        mset_ft.insert(i);
        vec.push_back(10 + i);
    }
    
    std::multiset<int>   mset_std2(++vec.begin(), --vec.end());
    ft::multiset<int>    mset_ft2(++vec.begin(), --vec.end());
    std::multiset<int>   mset_std3(mset_std2);
    ft::multiset<int>    mset_ft3(mset_ft2);

    mset_std2.clear();
    mset_ft2.clear();

    if (mset_std.empty())
		std::cout << "mset_std is empty\n";
	if (mset_ft.empty())
		std::cout << "mset_ft  is empty\n";

    mset_std2 = mset_std;
    mset_ft2 = mset_ft;

    std::cout << "mset_std  : ";
    for (it_std = mset_std.begin(); it_std != mset_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std.size() << "\n";
    std::cout << "mset_std2 : ";
    for (it_std = mset_std2.begin(); it_std != mset_std2.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std2.size() << "\n";
    std::cout << "mset_std3 : ";
    for (rit_std = mset_std3.rbegin(); rit_std != mset_std3.rend(); rit_std++)
        std::cout << *rit_std << " ";
    std::cout << "  size = " << mset_std3.size() << " reverse print\n";
    std::cout << "\n";
	std::cout << "mset_ft   : ";
    for (it_ft = mset_ft.begin(); it_ft != mset_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft.size() << "\n";
    std::cout << "mset_ft2  : ";
    for (it_ft = mset_ft2.begin(); it_ft != mset_ft2.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft2.size() << "\n";
    std::cout << "mset_ft3  : ";
    for (rit_ft = mset_ft3.rbegin(); rit_ft != mset_ft3.rend(); rit_ft++)
        std::cout << *rit_ft << " ";
    std::cout << "  size = " << mset_ft3.size() << " reverse print\n";
    std::cout << "\n";

    mset_std.insert(777);
    mset_std.insert(777);
    mset_std.insert(++mset_std.begin(), 42);
    mset_std.insert(++mset_std.begin(), 42);
    it_std = mset_std3.begin();
    it_std++;
    it_std++;
    it_std++;
    mset_std.insert(mset_std3.begin(), it_std);

    mset_ft.insert(777);
    mset_ft.insert(777);
    mset_ft.insert(++mset_ft.begin(), 42);
    mset_ft.insert(++mset_ft.begin(), 42);
    it_ft = mset_ft3.begin();
    it_ft++;
    it_ft++;
    it_ft++;
    mset_ft.insert(mset_ft3.begin(), it_ft);

    std::cout << "\033[32mmset.insert(777) x 2 mset.insert(++mset.begin(), 42) x 2 mset.insert(mset3.begin(), mset3.begin() + 3)\033[0m\n";
    std::cout << "mset_std  : ";
    for (it_std = mset_std.begin(); it_std != mset_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std.size() << "\n";
	std::cout << "mset_ft   : ";
    for (it_ft = mset_ft.begin(); it_ft != mset_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft.size() << "\n";
    std::cout << "\n";

    it_std = mset_std.begin();
    it_std++;
    it_std++;
    mset_std.erase(it_std);
    mset_std.erase(42);
    mset_std.erase(++mset_std.begin(), --mset_std.end());

    it_ft = mset_ft.begin();
    it_ft++;
    it_ft++;
    mset_ft.erase(it_ft);
    mset_ft.erase(42);
    mset_ft.erase(++mset_ft.begin(), --mset_ft.end());

    std::cout << "\033[32mmset.erase(mset.begin() + 2) mset.erase(42) mset.erase(++mset.begin(), --mset.end())\033[0m\n";
    std::cout << "mset_std  : ";
    for (it_std = mset_std.begin(); it_std != mset_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std.size() << "\n";
	std::cout << "mset_ft   : ";
    for (it_ft = mset_ft.begin(); it_ft != mset_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft.size() << "\n";
    std::cout << "\n";

    mset_std.swap(mset_std2);
    mset_ft.swap(mset_ft2);

    std::cout << "\033[32mmset.swap(mset2)\033[0m\n";
    std::cout << "mset_std  : ";
    for (it_std = mset_std.begin(); it_std != mset_std.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std.size() << "\n";
    std::cout << "mset_std2 : ";
    for (it_std = mset_std2.begin(); it_std != mset_std2.end(); it_std++)
        std::cout << *it_std << " ";
    std::cout << "      size = " << mset_std2.size() << "\n";
    std::cout << "\n";
	std::cout << "mset_ft   : ";
    for (it_ft = mset_ft.begin(); it_ft != mset_ft.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft.size() << "\n";
    std::cout << "mset_ft2  : ";
    for (it_ft = mset_ft2.begin(); it_ft != mset_ft2.end(); it_ft++)
        std::cout << *it_ft << " ";
    std::cout << "      size = " << mset_ft2.size() << "\n";
}
