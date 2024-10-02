#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	//Constructors
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);

	//Assignment operator
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

	//Destructor
	~ShrubberyCreationForm();

	//Member functions
	void execute() const;
};

#endif