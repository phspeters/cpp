#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--> TESTING BUREAUCRAT DEFAULT CONSTRUCTOR\n";
	Bureaucrat defaultBureaucrat;
	std::cout << defaultBureaucrat << '\n';
	std::cout << '\n';

	std::cout << "--> TESTING BUREAUCRAT PARAMETERIZED CONSTRUCTOR\n";
	testBureaucrat("Ananias", 1);
	testBureaucrat("Boris", 150);
	testBureaucrat("Charlinho", 0);
	testBureaucrat("Diogenes", 151);
	testBureaucrat("Eustaquio", -10);
	testBureaucrat("Felix", 99);
	std::cout << '\n';

	std::cout << "--> TESTING BUREAUCRAT COPY CONSTRUCTOR\n";
	Bureaucrat ananias("Ananias", 1);
	Bureaucrat boris(ananias);
	std::cout << ananias << '\n';
	std::cout << boris << '\n';
	std::cout << '\n';

	std::cout << "--> TESTING BUREAUCRAT ASSIGNMENT OPERATOR\n";
	Bureaucrat charlinho("Charlinho", 10);
	Bureaucrat diogenes("Diogenes", 100);
	std::cout << charlinho << '\n';
	std::cout << diogenes << '\n';
	std::cout << "...assigning Charlinho to Diogenes\n";
	diogenes = charlinho;
	std::cout << diogenes << '\n';
	std::cout << '\n';

	std::cout << "--> TESTING GRADE INCREMENT\n";
	Bureaucrat eustaquio("Eustaquio", 2);
	std::cout << eustaquio << '\n';
	std::cout << "...incrementing grade\n";
	eustaquio.incrementGrade();
	std::cout << eustaquio << '\n';
	std::cout << "...incrementing grade\n";
	eustaquio.incrementGrade();
	std::cout << eustaquio << '\n';
	std::cout << '\n';

	std::cout << "--> TESTING GRADE DECREMENT\n";
	Bureaucrat felix("Felix", 149);
	std::cout << felix << '\n';
	std::cout << "...decrementing grade\n";
	felix.decrementGrade();
	std::cout << felix << '\n';
	std::cout << "...decrementing grade\n";
	felix.decrementGrade();
	std::cout << felix << '\n';
	std::cout << '\n';
}
