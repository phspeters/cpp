#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	//Constructors
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &other);

	//Assignment operator
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	//Destructor
	~PresidentialPardonForm();

	//Member functions
	void beExecuted() const;
};

#endif