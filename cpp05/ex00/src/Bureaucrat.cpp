#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name), _grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    try {
        if (_grade <= 1) {
            throw Bureaucrat::GradeTooHighException();
        }
        _grade--;
    } catch (const std::exception& exception) {
        std::cerr << "Error: can't increment bureaucrat " << this->getName()
                  << "'s grade: " << exception.what() << '\n';
        return;
    }
}

void Bureaucrat::decrementGrade() {
    try {
        if (_grade >= 150) {
            throw Bureaucrat::GradeTooLowException();
        }
        _grade++;
    } catch (const std::exception& exception) {
        std::cerr << "Error: can't decrement bureaucrat " << this->getName()
                  << "'s grade: " << exception.what() << '\n';
        return;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade();
    return out;
}

void testBureaucrat(const std::string name, int grade) {
    try {
        Bureaucrat bureaucrat(name, grade);
        std::cout << "Bureaucrat " << bureaucrat.getName();
        std::cout << " successfully constructed with grade ";
        std::cout << bureaucrat.getGrade() << '\n';
    } catch (const std::exception& exception) {
        std::cerr << "Error: can't create bureaucrat " << name
                  << " with grade ";
        std::cerr << grade << ": " << exception.what() << '\n';
        return;
    }
}
