#include "Span.hpp"

Span::Span(unsigned int n) : max_n(n)
{
	if(n <= 1)
		throw std::out_of_range("Constructor value not large enough (min 2)");

}

void Span::addNumber(int n)
{
	if (this->int_vec.size() == max_n)
		throw std::out_of_range("Span vector already full");
	this->int_vec.push_back(n);
}

unsigned int Span::longestSpan()
{
	if(int_vec.size() < 2)
		throw std::runtime_error("Not enough vector elements");
	std::vector<int> sorted_vec = int_vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());

	int res = sorted_vec.back() - sorted_vec.front();
	return res;
}

unsigned int Span::shortestSpan()
{
	if(int_vec.size() < 2)
		throw std::runtime_error("Not enough vector elements");
	
	std::vector<int> sorted_vec = int_vec;
	std::sort(sorted_vec.begin(), sorted_vec.end());

	int res = sorted_vec[1] - sorted_vec[0];
	for (size_t i = 1; i < sorted_vec.size(); i++)
	{
		int span = sorted_vec[i] - sorted_vec[i - 1];
		if (span < res)
			res = span;
	}
	return res;
}

void Span::fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t d_sum = std::distance(begin, end);
	if (int_vec.size() + d_sum > max_n)
		throw std::out_of_range("Not enough space available");
	int_vec.insert(int_vec.end(), begin, end);
}

Span::~Span()
{
}

void Span::displayVec()
{
	for(size_t i = 0; i < int_vec.size(); i++)
	{
		std::cout << i;
		if(i < int_vec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}