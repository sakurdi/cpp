#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> no_args;
	Array<int> simple(10);
	std:: cout << " ------------ OUT OF RANGE TEST ------------" << std::endl;
	std::cout << "no_args SIZE "<< no_args.size() << std::endl;
	try
	{
		no_args[2];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	for(size_t i = 0; i < 10; i++)
		simple[i] = i + 10;
	Array<int> copy(simple);
	std:: cout << " ------------ COPY ADDR DIFF TEST ------------" << std::endl;
	for(size_t i = 0; i < 10; i++)
	{
		std::cout << "[simple] " << std::hex << &simple[i] << " [copy] " << std::hex << &copy[i] << std::endl;
	}

	Array<int> assign = simple;	
	std:: cout << " ------------ ASSIGN ADDR DIFF TEST ------------" << std::endl;
	for(size_t i = 0; i < 10; i++)
	{
		std::cout << "[simple] " << std::hex << &simple[i] << " [copy] " << std::hex << &copy[i] << " [assign] " << std::hex << &assign[i] 
		<< std::endl;
	}

	std:: cout << " ------------ STRING ARRAY TEST ------------" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Salut";
	strings[1] = "Bonsoir";
	strings[2] = "très drole";
	for (size_t i = 0; i < strings.size(); i++)
		std::cout << "STRINGS[" << i << "] "<< strings[i] << " " << std::endl;
}