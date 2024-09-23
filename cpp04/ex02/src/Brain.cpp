#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor\n";
}

Brain::Brain(const Brain &copy)
{
	*this = copy;

	std::cout << "Brain copy constructor\n";
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for(int i = 0; i < MAX_IDEAS; i++)
		{
			_ideas[i] = copy._ideas[i];
		}
	}
	
	std::cout << "Brain assignment operator\n";

	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor\n";
}

std::string Brain::getIdea(int index) const
{
	return (_ideas[index]);
}

void Brain::setIdea(int index, std::string newIdea)
{
	_ideas[index] = newIdea;
}
