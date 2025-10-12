#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	int rd = rand() % 3;

	if (rd == 0)
		return new A();
	else if (rd == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...)
	{
	}
}

int main()
{
	for (size_t i = 0; i < 6; i++)
	{
		Base *p = generate();
		std::cout << "------ Generate + identify------" << std::endl;
		identify(p);
		delete p;
	}

	A a;
	B b;
	C c;

	std::cout << "A ptr instance: ";
	identify(&a);
	std::cout << "B ptr instance: ";
	identify(&b);
	std::cout << "C ptr instance: ";
	identify(&c);

	A &ref_a = a;
	B &ref_b = b;
	C &ref_c = c;
	std::cout << "ref_a reference instance: ";
	identify(ref_a);
	std::cout << "ref_b reference instance: ";
	identify(ref_b);
	std::cout << "ref_c reference instance: ";
	identify(ref_c);
}