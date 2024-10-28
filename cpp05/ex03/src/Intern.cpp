#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	int formIndex = -1;
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			formIndex = i;
			break;
		}
	}

	if (formIndex == -1) {
		std::cout << "Intern doesn't know how create "<< formName <<" form\n";
		return (NULL);
	}

	std::cout << "Intern creates " << formName << " form\n";
	switch(formIndex) {
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Form not found\n";
			return (NULL);
	}

}
