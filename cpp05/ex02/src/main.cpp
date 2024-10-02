#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	bureaucrat("Arthur Dent", 42);
	ShrubberyCreationForm	shrubberyCreationForm("home");
	RobotomyRequestForm		robotomyRequestForm("Marvin");
	PresidentialPardonForm	presidentialPardonForm("Ford Prefect");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << robotomyRequestForm << std::endl;
	std::cout << presidentialPardonForm << std::endl;

	bureaucrat.signForm(shrubberyCreationForm);
	bureaucrat.signForm(robotomyRequestForm);
	bureaucrat.signForm(presidentialPardonForm);

	bureaucrat.executeForm(shrubberyCreationForm);
	bureaucrat.executeForm(robotomyRequestForm);
	bureaucrat.executeForm(presidentialPardonForm);

	return (0);
}
