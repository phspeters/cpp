#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;

	std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	
	std::cout << "Brain assignment operator" << std::endl;

	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	return (ideas[index]);
}

void Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}
