#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define IDEAS_SIZE 100

class Brain
{
private:
	std::string *ideas;
public:
	Brain();
	Brain(const std::string &Brain);
	Brain(const Brain &obj);
	Brain &operator=(const Brain &obj);
	~Brain();
};

#endif