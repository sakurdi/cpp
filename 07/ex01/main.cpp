#include "Iter.hpp"

void echo(const int &n)
{
	std::cout << n << std::endl;
}

void increment(int &n)
{
	std::cout << (n += 10) << std::endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "------- ECHO -------" << std::endl;
	iter(arr, (size_t)5, echo);
	std::cout << "------- INCREMENT -------" << std::endl;
	iter(arr, (size_t)5, increment);
}