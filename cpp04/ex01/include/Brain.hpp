#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public:
	//constructors
	Brain();
	Brain(const Brain &copy);

	//assignation operator
	Brain &operator=(const Brain &copy);

	//destructor
	~Brain();

	//member functions
	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);

protected:
	std::string ideas[100];
};

#endif