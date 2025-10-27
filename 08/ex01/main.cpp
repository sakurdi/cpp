#include "Span.hpp"
#include <cstdlib>
#include <ctime>
int main()
{
	std::srand(std::time(0));
	std::cout << "------ Basic addNumber with exception ------" << std::endl;
	try
	{
		Span s(3);
		s.addNumber(10);
		s.addNumber(5);
		s.addNumber(20);
		//s.addNumber(4);
		int res = s.longestSpan();
		int s_res = s.shortestSpan();
		std::cout << "Longest span: " << res << std::endl << "Shortest span: " << s_res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------ Basic span range tests ------" << std::endl;
	try
	{
		Span s(100);
		for(size_t i = 0; i < 100; i++)
			s.addNumber(std::rand() % 1000);
		int res = s.longestSpan();
		int s_res = s.shortestSpan();
		std::cout << "Longest span: " << res << std::endl << "Shortest span: " << s_res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------ Basic fillVector overflow ------" << std::endl;
	try
	{
		Span s(5);
		std::vector<int> nums;
		for(int i = 0; i < 15; i++)
			nums.push_back(i);
		s.fillVector(nums.begin(), nums.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------ Basic working fillVector ------" << std::endl;
	try
	{
		Span s(20);
		std::vector<int> nums;
		for(int i = 0; i < 15; i++)
			nums.push_back(i);
		s.fillVector(nums.begin(), nums.end());
		s.displayVec();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}