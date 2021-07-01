#include "ft_containers_test.hpp"

void multimap_test()
{
    std::cout << "\n\n\033[34m[		multimap_test			]\033[0m\n\n\n";
    std::multimap<int, int>   mmap_std;
    std::multimap<int, int>::iterator it_std;
    std::multimap<int, int>::reverse_iterator rit_std;
    ft::multimap<int, int>    mmap_ft;
    ft::multimap<int, int>::iterator  it_ft;
    ft::multimap<int, int>::reverse_iterator  rit_ft;

    for (int i = 0; i < 6; i++)
    {
        mmap_std.insert(std::pair<int, int>(i, i));
        mmap_ft.insert(ft::pair<int, int>(i, i));
    }

    for (int i = 0; i < 3; i++)
    {
        mmap_std.insert(std::pair<int, int>(i, i * 10));
        mmap_ft.insert(ft::pair<int, int>(i, i * 10));
    }
    
    std::multimap<int, int>   mmap_std2(++mmap_std.begin(), --mmap_std.end());
    ft::multimap<int, int>    mmap_ft2(++mmap_ft.begin(), --mmap_ft.end());
    std::multimap<int, int>   mmap_std3(mmap_std2);
    ft::multimap<int, int>    mmap_ft3(mmap_ft2);

    mmap_std2.clear();
    mmap_ft2.clear();

    if (mmap_std.empty())
		std::cout << "mmmap_std is empty\n";
	if (mmap_ft.empty())
		std::cout << "mmap_ft  is empty\n";

    mmap_std2 = mmap_std;
    mmap_ft2 = mmap_ft;

    std::cout << "mmap_std\n";
    std::cout << "size() : " << mmap_std.size() << "\n";
    for (it_std = mmap_std.begin(); it_std != mmap_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "mmap_std2\n";
    std::cout << "size() : " << mmap_std2.size() << "\n";
    for (it_std = mmap_std2.begin(); it_std != mmap_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "mmap_std3\n";
    std::cout << "size() : " << mmap_std3.size() << "\n";
    for (rit_std = mmap_std3.rbegin(); rit_std != mmap_std3.rend(); rit_std++)
        std::cout << "key : " << rit_std->first << " value : " << rit_std->second << std::endl;
    std::cout << "\n";
	std::cout << "mmap_ft\n";
    std::cout << "size() : " << mmap_ft.size() << "\n";
    for (it_ft = mmap_ft.begin(); it_ft != mmap_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "mmap_ft2\n";
    std::cout << "size() : " << mmap_ft2.size() << "\n";
    for (it_ft = mmap_ft2.begin(); it_ft != mmap_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "mmap_ft3\n";
    std::cout << "size() : " << mmap_ft3.size() << "\n";
    for (rit_ft = mmap_ft3.rbegin(); rit_ft != mmap_ft3.rend(); rit_ft++)
        std::cout << "key : " << rit_ft->first << " value : " << rit_ft->second << std::endl;
    std::cout << "\n";

    mmap_std.insert(std::pair<int, int>(777, 77));
    mmap_std.insert(std::pair<int, int>(777, 7777));
    mmap_std.insert(++mmap_std.begin(), std::pair<int, int>(42, 42));
    it_std = mmap_std3.begin();
    it_std++;
    it_std++;
    it_std++;
    mmap_std.insert(mmap_std3.begin(), it_std);

    mmap_ft.insert(ft::pair<int, int>(777, 77));
    mmap_ft.insert(ft::pair<int, int>(777, 7777));
    mmap_ft.insert(++mmap_ft.begin(), ft::pair<int, int>(42, 42));
    it_ft = mmap_ft3.begin();
    it_ft++;
    it_ft++;
    it_ft++;
    mmap_ft.insert(mmap_ft3.begin(), it_ft);

    std::cout << "\033[32mmmap.insert(777, 77) mmap.insert(777, 7777) mmap.insert(++mmap.begin(), (42, 42) " << std::endl;
    std::cout << "mmap.insert(mmap3.begin(), mmap3.begin() + 3)\033[0m\n";
    std::cout << "mmap_std\n";
    std::cout << "size() : " << mmap_std.size() << "\n";
    for (it_std = mmap_std.begin(); it_std != mmap_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
	std::cout << "mmap_ft\n";
    std::cout << "size() : " << mmap_ft.size() << "\n";
    for (it_ft = mmap_ft.begin(); it_ft != mmap_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    it_std = mmap_std.begin();
    it_std++;
    it_std++;
    mmap_std.erase(it_std);
    mmap_std.erase(42);
    mmap_std.erase(++mmap_std.begin(), --mmap_std.end());

    it_ft = mmap_ft.begin();
    it_ft++;
    it_ft++;
    mmap_ft.erase(it_ft);
    mmap_ft.erase(42);
    mmap_ft.erase(++mmap_ft.begin(), --mmap_ft.end());

    std::cout << "\033[32mmmap.erase(mmap.begin() + 2) mmap.erase(42) mmap.erase(++mmap.begin(), --mmap.end())\033[0m\n";
    std::cout << "mmap_std\n";
    std::cout << "size() : " << mmap_std.size() << "\n";
    for (it_std = mmap_std.begin(); it_std != mmap_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
	std::cout << "mmap_ft\n";
    std::cout << "size() : " << mmap_ft.size() << "\n";
    for (it_ft = mmap_ft.begin(); it_ft != mmap_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "\n";

    mmap_std.swap(mmap_std2);
    mmap_ft.swap(mmap_ft2);

    std::cout << "\033[32mmmap.swap(mmap2)\033[0m\n";
    std::cout << "mmap_std\n";
    std::cout << "size() : " << mmap_std.size() << "\n";
    for (it_std = mmap_std.begin(); it_std != mmap_std.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "mmap_std2\n";
    std::cout << "size() : " << mmap_std2.size() << "\n";
    for (it_std = mmap_std2.begin(); it_std != mmap_std2.end(); it_std++)
        std::cout << "key : " << it_std->first << " value : " << it_std->second << std::endl;
    std::cout << "\n";
	std::cout << "mmap_ft\n";
    std::cout << "size() : " << mmap_ft.size() << "\n";
    for (it_ft = mmap_ft.begin(); it_ft != mmap_ft.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
    std::cout << "mmap_ft2\n";
    std::cout << "size() : " << mmap_ft2.size() << "\n";
    for (it_ft = mmap_ft2.begin(); it_ft != mmap_ft2.end(); it_ft++)
        std::cout << "key : " << it_ft->first << " value : " << it_ft->second << std::endl;
}
