#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
	//Constructors
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &other);

	//Assignment operator
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	//Destructor
	~RobotomyRequestForm();

	//Member functions
	void beExecuted() const;
};

#endif