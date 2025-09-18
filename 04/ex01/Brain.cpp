#include "Brain.hpp"

Brain::Brain()
{
	this->ideas = new std::string[IDEAS_SIZE];
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const std::string &BrainType)
{
	this->ideas = new std::string[IDEAS_SIZE];
	std::cout << "Brain name constructor called for value : " << BrainType << std::endl;
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		this->ideas[i] = BrainType;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[IDEAS_SIZE];
	for (size_t i = 0; i < IDEAS_SIZE; i++)
		this->ideas[i] = obj.ideas[i];
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &obj)
	{
		delete[] this->ideas;
		this->ideas = new std::string[IDEAS_SIZE];
		for (size_t i = 0; i < IDEAS_SIZE; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called, freeing up ideas array" << std::endl;
	delete[] this->ideas;
}
