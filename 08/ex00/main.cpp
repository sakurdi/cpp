#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> int_vec;
	std::list<int> list;
	for(size_t i = 0; i < 10; i++)
	{
		int_vec.push_back(i); 
		list.push_back(i);
	}
	try
	{
		//std::vector<int>::value_type ite_vec = easyfind(int_vec, 7);
		//std::vector<int>::value_type ite_vec = easyfind(int_vec, 11);
		std::vector<int>::value_type ite_vec = easyfind(int_vec, -1);
		std::vector<int>::value_type list_vec = easyfind(list, 4);
		std::cout << ite_vec << " found in vector" << std::endl;
		std::cout << list_vec << " found in list" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}