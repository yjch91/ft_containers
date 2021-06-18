#include "ft_containers_test.hpp"

void queue_test()
{
    std::cout << "\n\n\033[34m[		queue_test			]\033[0m\n\n\n";
    std::queue<int> que_std, que_std2;
    ft::queue<int>  que_ft, que_ft2;

    // std test
    std::cout << "\033[32m[std test]\033[0m\n";
    for (int i = 0; i < 5; i++)
    {
        que_std.push(i);
        que_std2.push(i);
    }

	if (que_std == que_std2)
		std::cout << "que_std == que_std2\n";
	else
		std::cout << "que_std != que_std2\n";

    std::cout << "que_std (size = " << que_std.size() << ") :";
    while (!que_std.empty())
    {
        std::cout << " " << que_std.front();
        que_std.pop();
    }
    std::cout << "\n";

    std::cout << "que_std2(size = " << que_std2.size() << ") :";
    while (!que_std2.empty())
    {
        std::cout << " " << que_std2.front();
        que_std2.pop();
    }
    std::cout << "\n\n";

    que_std.push(7);
    for (int i = 0; i < 4; i++)
    {
        que_std.push(i);
        if (i != 3)
            que_std2.push(i);
    }
    que_std2.front() = 6;
    que_std.back() += 2;
    for (int i = 0; i < 3; i++)
        que_std2.push(9 - i);

    if (que_std == que_std2)
		std::cout << "que_std == que_std2\n";
	else
		std::cout << "que_std != que_std2\n";

    if (que_std < que_std2)
		std::cout << "que_std < que_std2\n";
	else if (que_std >= que_std2)
		std::cout << "que_std >= que_std2\n";

	std::cout << "que_std (size = " << que_std.size() << ") :";
    while (!que_std.empty())
    {
        std::cout << " " << que_std.front();
        que_std.pop();
    }
    std::cout << "\n";

    std::cout << "que_std2(size = " << que_std2.size() << ") :";
    while (!que_std2.empty())
    {
        std::cout << " " << que_std2.front();
        que_std2.pop();
    }
    std::cout << "\n\n";

    for (int i = 0; i < 4; i++)
    {
        que_std.push(i);
        que_std2.push(i);
    }

    // ft test
    std::cout << "\033[32m[ft test]\033[0m\n";
    for (int i = 0; i < 5; i++)
    {
        que_ft.push(i);
        que_ft2.push(i);
    }

	if (que_ft == que_ft2)
		std::cout << "que_ft == que_ft2\n";
	else
		std::cout << "que_ft != que_ft2\n";

    std::cout << "que_ft  (size = " << que_ft.size() << ") :";
    while (!que_ft.empty())
    {
        std::cout << " " << que_ft.front();
        que_ft.pop();
    }
    std::cout << "\n";

    std::cout << "que_ft2 (size = " << que_ft2.size() << ") :";
    while (!que_ft2.empty())
    {
        std::cout << " " << que_ft2.front();
        que_ft2.pop();
    }
    std::cout << "\n\n";

    que_ft.push(7);
    for (int i = 0; i < 4; i++)
    {
        que_ft.push(i);
        if (i != 3)
            que_ft2.push(i);
    }
    que_ft2.front() = 6;
    que_ft.back() += 2;
    for (int i = 0; i < 3; i++)
        que_ft2.push(9 - i);

    if (que_ft == que_ft2)
		std::cout << "que_ft == que_ft2\n";
	else
		std::cout << "que_ft != que_ft2\n";

    if (que_ft < que_ft2)
		std::cout << "que_ft < que_ft2\n";
	else if (que_std >= que_std2)
		std::cout << "que_ft >= que_ft2\n";

	std::cout << "que_ft  (size = " << que_ft.size() << ") :";
    while (!que_ft.empty())
    {
        std::cout << " " << que_ft.front();
        que_ft.pop();
    }
    std::cout << "\n";

    std::cout << "que_ft2 (size = " << que_ft2.size() << ") :";
    while (!que_ft2.empty())
    {
        std::cout << " " << que_ft2.front();
        que_ft2.pop();
    }
    std::cout << "\n";
}
