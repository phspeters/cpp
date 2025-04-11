#include "Form.hpp"

int main() {
    std::cout << "--> TESTING FORM DEFAULT CONSTRUCTOR\n";
    Form defaultForm;
    std::cout << defaultForm << '\n';
    std::cout << '\n';

    std::cout << "--> TESTING FORM PARAMETERIZED CONSTRUCTOR\n";
    testForm("A24", 1, 1);
    testForm("B64", 150, 150);
    testForm("C42", 0, 99);
    testForm("D69", 99, 0);
    testForm("E2", 200, 100);
    testForm("F420", 99, 200);
    std::cout << '\n';

    std::cout << "--> TESTING FORM COPY CONSTRUCTOR\n";
    Form a("A24", 1, 1);
    Form b(a);
    std::cout << "... printing 'a'" << '\n';
    std::cout << a << '\n';
    std::cout << "... printing 'b'" << '\n';
    std::cout << b << '\n';
    std::cout << '\n';

    std::cout << "--> TESTING FORM SIGNING\n";
    Bureaucrat bureaucrat("Ananias", 2);
    std::cout << bureaucrat << '\n';
    std::cout << a << '\n';
    std::cout << "... Ananias is signing form\n";
    bureaucrat.signForm(a);
    std::cout << a << '\n';
    std::cout << "... incrementing Ananias grade\n";
    bureaucrat.incrementGrade();
    std::cout << bureaucrat << '\n';
    std::cout << "... Ananias is signing form again\n";
    bureaucrat.signForm(a);
    std::cout << a << '\n';
    std::cout << '\n';

    std::cout << "--> TESTING FORM ASSIGNMENT OPERATOR\n";
    Form c("C42", 99, 99);
    std::cout << "... printing 'a'" << '\n';
    std::cout << a << '\n';
    std::cout << "... printing 'c'" << '\n';
    std::cout << c << '\n';
    std::cout << "... assigning 'a' to 'c'" << '\n';
    c = a;
    std::cout << "... printing 'a'" << '\n';
    std::cout << a << '\n';
    std::cout << "... printing 'c'" << '\n';
    std::cout << c << '\n';
    std::cout << '\n';
}
