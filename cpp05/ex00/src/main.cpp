#include "Bureaucrat.hpp"

int	main() {
	std::cout << "--> TESTING BUREAUCRAT DEFAULT CONSTRUCTOR\n";
	Bureaucrat defaultBureaucrat;
	std::cout << defaultBureaucrat << '\n';
	std::cout << '\n';

	std::cout << "--> TESTING BUREAUCRAT PARAMETERIZED CONSTRUCTOR\n";
	std::cout << "A) ";
	testBureaucrat("Ananias", 1);
	std::cout << "B) ";
	testBureaucrat("Boris", 150);
	std::cout << "C) ";
	testBureaucrat("Charlinho", 0);
	std::cout << "D) ";
	testBureaucrat("Diogenes", 151);
	std::cout << "E) ";
	testBureaucrat("Eustaquio", -10);
	std::cout << "F) ";
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
