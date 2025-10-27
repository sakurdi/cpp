#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
class Span
{
private:
	Span(/* args */);
	unsigned int max_n;
	std::vector<int> int_vec;
public:
	Span(const Span &obj);
	Span(unsigned int n);
	Span operator=(const Span &obj);
	~Span();
	void addNumber(int n);
	unsigned int longestSpan();
	unsigned int shortestSpan();
	void displayVec();
	void fillVector(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};




#endif