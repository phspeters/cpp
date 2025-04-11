#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "CREATING BUREAUCRATS...\n";
    Bureaucrat highLevelBureaucrat("Prostetnic Vogon Jeltz", 1);
    Bureaucrat lowLevelBureaucrat("Kwaltz", 150);
    std::cout << '\n';

    std::cout << "CREATING FORMS...\n";
    ShrubberyCreationForm shrubberyCreationForm("home");
    RobotomyRequestForm robotomyRequestForm("Marvin");
    PresidentialPardonForm presidentialPardonForm("Ford Prefect");
    std::cout << '\n';

    std::cout << "BUREAUCRATS STATUS:\n";
    std::cout << highLevelBureaucrat << '\n';
    std::cout << lowLevelBureaucrat << '\n';
    std::cout << '\n';

    std::cout << "FORMS STATUS\n";
    std::cout << shrubberyCreationForm << '\n';
    std::cout << robotomyRequestForm << '\n';
    std::cout << presidentialPardonForm << '\n';
    std::cout << '\n';

    std::cout << "LOW LEVEL BUREAUCRAT ATTEMPTS TO SIGN FORMS\n";
    lowLevelBureaucrat.signForm(shrubberyCreationForm);
    lowLevelBureaucrat.signForm(robotomyRequestForm);
    lowLevelBureaucrat.signForm(presidentialPardonForm);
    std::cout << '\n';

    std::cout << "FORMS STATUS\n";
    std::cout << shrubberyCreationForm << '\n';
    std::cout << robotomyRequestForm << '\n';
    std::cout << presidentialPardonForm << '\n';
    std::cout << '\n';

    std::cout << "LOW LEVEL BUREAUCRAT ATTEMPTS TO EXECUTE FORMS\n";
    lowLevelBureaucrat.executeForm(shrubberyCreationForm);
    lowLevelBureaucrat.executeForm(robotomyRequestForm);
    lowLevelBureaucrat.executeForm(presidentialPardonForm);
    std::cout << '\n';

    std::cout << "HIGH LEVEL BUREAUCRAT ATTEMPTS TO SIGN FORMS\n";
    highLevelBureaucrat.signForm(shrubberyCreationForm);
    highLevelBureaucrat.signForm(robotomyRequestForm);
    highLevelBureaucrat.signForm(presidentialPardonForm);
    std::cout << '\n';

    std::cout << "FORMS STATUS\n";
    std::cout << shrubberyCreationForm << '\n';
    std::cout << robotomyRequestForm << '\n';
    std::cout << presidentialPardonForm << '\n';
    std::cout << '\n';

    std::cout << "LOW LEVEL BUREAUCRAT ATTEMPTS TO EXECUTE FORMS\n";
    lowLevelBureaucrat.executeForm(shrubberyCreationForm);
    lowLevelBureaucrat.executeForm(robotomyRequestForm);
    lowLevelBureaucrat.executeForm(presidentialPardonForm);
    std::cout << '\n';

    std::cout << "HIGH LEVEL BUREAUCRAT ATTEMPTS TO EXECUTE FORMS\n";
    highLevelBureaucrat.executeForm(shrubberyCreationForm);
    highLevelBureaucrat.executeForm(robotomyRequestForm);
    highLevelBureaucrat.executeForm(presidentialPardonForm);
    std::cout << '\n';

    std::cout << "CALLING DESTRUCTORS...\n";
    return 0;
}
