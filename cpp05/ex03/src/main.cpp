#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	std::cout << "CREATING INTERN...\n";
	Intern randomIntern;
	std::cout << '\n';

	std::cout << "CREATING FORMS...\n";
	AForm *forms[5];
	forms[0] = randomIntern.makeForm("shrubbery creation", "home");
	forms[1] = randomIntern.makeForm("robotomy request", "Marvin");
	forms[2] = randomIntern.makeForm("presidential pardon", "Ford Prefect");
	forms[3] = randomIntern.makeForm("intergalatic export permit", "Betelgeuse");
	forms[4] = randomIntern.makeForm("complaint for misplaced planets", "Magrathea");
	std::cout << '\n';

	std::cout << "FORMS STATUS\n";
	for (int i = 0; i < 5; i++)	{
		if (forms[i]) {
			std::cout << *forms[i] << '\n';
		}
		else {
			std::cout << "Form not found\n";
		}
	}
	std::cout << '\n';

	std::cout << "DELETING FORMS...\n";
	for (int i = 0; i < 5; i++)	{
		if (forms[i]) {
			delete forms[i];
		}
	}

	std::cout << "CALLING DESTRUCTORS...\n";
	return (0);
}
