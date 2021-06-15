#include "ft_containers_test.hpp"

void stack_test()
{
    std::cout << "\n\n\033[32m[		stack_test			]\033[0m\n\n\n";
    std::stack<int> stk_std, stk_std2;
    ft::stack<int> stk_ft, stk_ft2;

    // std test
    std::cout << "\033[32m[std test]\033[0m\n";
    for (int i = 0; i < 5; i++)
    {
        stk_std.push(i);
        stk_std2.push(i);
    }

	if (stk_std == stk_std2)
		std::cout << "stk_std == stk_std2\n";
	else
		std::cout << "stk_std != stk_std2\n";

    std::cout << "print order        : top -> bottom\n";
    std::cout << "stk_std (size = " << stk_std.size() << ") :";
    while (!stk_std.empty())
    {
        std::cout << " " << stk_std.top();
        stk_std.pop();
    }
    std::cout << "\n";

    std::cout << "stk_std2(size = " << stk_std2.size() << ") :";
    while (!stk_std2.empty())
    {
        std::cout << " " << stk_std2.top();
        stk_std2.pop();
    }
    std::cout << "\n\n";

    stk_std2.push(10);
    stk_std2.top() -= 1;
    for (int i = 0; i < 4; i++)
    {
        stk_std.push(i);
        if (i != 3)
            stk_std2.push(i);
    }

    if (stk_std == stk_std2)
		std::cout << "stk_std == stk_std2\n";
	else
		std::cout << "stk_std != stk_std2\n";

    if (stk_std < stk_std2)
		std::cout << "stk_std < stk_std2\n";
	else if (stk_std >= stk_std2)
		std::cout << "stk_std >= stk_std2\n";

    std::cout << "print order        : top -> bottom\n";
	std::cout << "stk_std (size = " << stk_std.size() << ") :";
    while (!stk_std.empty())
    {
        std::cout << " " << stk_std.top();
        stk_std.pop();
    }
    std::cout << "\n";

    std::cout << "stk_std2(size = " << stk_std2.size() << ") :";
    while (!stk_std2.empty())
    {
        std::cout << " " << stk_std2.top();
        stk_std2.pop();
    }
    std::cout << "\n\n";

    for (int i = 0; i < 4; i++)
    {
        stk_std.push(i);
        stk_std2.push(i);
    }

    // ft test
    std::cout << "\033[32m[ft test]\033[0m\n";
    for (int i = 0; i < 5; i++)
    {
        stk_ft.push(i);
        stk_ft2.push(i);
    }

	if (stk_ft == stk_ft2)
		std::cout << "stk_ft == stk_ft2\n";
	else
		std::cout << "stk_ft != stk_ft2\n";

    std::cout << "print order        : top -> bottom\n";
    std::cout << "stk_ft  (size = " << stk_ft.size() << ") :";
    while (!stk_ft.empty())
    {
        std::cout << " " << stk_ft.top();
        stk_ft.pop();
    }
    std::cout << "\n";

    std::cout << "stk_ft2 (size = " << stk_ft2.size() << ") :";
    while (!stk_ft2.empty())
    {
        std::cout << " " << stk_ft2.top();
        stk_ft2.pop();
    }
    std::cout << "\n\n";

    stk_ft2.push(10);
    stk_ft2.top() -= 1;
    for (int i = 0; i < 4; i++)
    {
        stk_ft.push(i);
        if (i != 3)
            stk_ft2.push(i);
    }

    if (stk_ft == stk_ft2)
		std::cout << "stk_ft == stk_ft2\n";
	else
		std::cout << "stk_ft != stk_ft2\n";

    if (stk_ft < stk_ft2)
		std::cout << "stk_ft < stk_ft2\n";
	else if (stk_std >= stk_std2)
		std::cout << "stk_ft >= stk_ft2\n";

    std::cout << "print order        : top -> bottom\n";
	std::cout << "stk_ft  (size = " << stk_ft.size() << ") :";
    while (!stk_ft.empty())
    {
        std::cout << " " << stk_ft.top();
        stk_ft.pop();
    }
    std::cout << "\n";

    std::cout << "stk_ft2 (size = " << stk_ft2.size() << ") :";
    while (!stk_ft2.empty())
    {
        std::cout << " " << stk_ft2.top();
        stk_ft2.pop();
    }
    std::cout << "\n";
}
