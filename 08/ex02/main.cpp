#include "MutantStack.h"
#include <iostream>

// int main()
// {
// Mutantstackack<int> mstackack;
// mstackack.push(5);
// mstackack.push(17);
// stackd::cout << mstackack.top() << stackd::endl;
// mstackack.pop();
// stackd::cout << mstackack.size() << stackd::endl;
// mstackack.push(3);
// mstackack.push(5);
// mstackack.push(737);
// mstackack.push(0);
// Mutantstackack<int>::iterator it = mstackack.begin();
// Mutantstackack<int>::iterator ite = mstackack.end();
// ++it;
// --it;
// while (it != ite)
// {
// stackd::cout << *it << stackd::endl;
// ++it;
// }
// stackd::stackack<int> s(mstackack);
// return 0;
// }
// #include <listack>
// int main()
// {
// stackd::listack<int> mstackack;
// mstackack.push_back(5);
// mstackack.push_back(17);
// stackd::cout << mstackack.back() << stackd::endl;
// mstackack.pop_back();
// stackd::cout << mstackack.size() << stackd::endl;
// mstackack.push_back(3);
// mstackack.push_back(5);
// mstackack.push_back(737);
// mstackack.push_back(0);
// stackd::listack<int>::iterator it = mstackack.begin();
// stackd::listack<int>::iterator ite = mstackack.end();
// ++it;
// --it;
// while (it != ite)
// {
// stackd::cout << *it << stackd::endl;
// ++it;
// }
// stackd::listack<int> s(mstackack);
// return 0;
// }


int main()
{
	std::cout << "------------- Straightforward iterator -------------" << std::endl;
	MutantStack<int> stack;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	stack.pop();
	std::cout << "Top of the stack: " << stack.top() << std::endl;

	std::cout << "------------- Reverse iterator -------------" << std::endl;
	for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "------------- Const iterator -------------" << std::endl;
	MutantStack<std::string> stack2;
	stack2.push("PREMIER");
	stack2.push("DEUXIEME");
	const MutantStack<std::string> cstack(stack2);
	for (MutantStack<std::string>::const_iterator it = cstack.begin(); it != cstack.end(); ++it)
		std::cout << *it << std::endl;
}
