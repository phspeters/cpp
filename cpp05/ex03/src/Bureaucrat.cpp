#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		_grade = other._grade;
	}

	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementGrade() {
	try {
		if (_grade <= 1) {
			throw Bureaucrat::GradeTooHighException();
		}
		_grade--;
	}
	catch (const std::exception &exception) {
		std::cerr << "Can't increment bureaucrat " << this->getName() << "'s grade: " << exception.what() << '\n';
		return ;
	}
}

void Bureaucrat::decrementGrade() {
	try	{
		if (_grade >= 150) {
			throw Bureaucrat::GradeTooLowException();
		}
		_grade++;
	}
	catch (const std::exception &exception)	{
		std::cerr << "Can't decrement bureaucrat " << this->getName() << "'s grade: " << exception.what() << '\n';
		return ;
	}
}

void Bureaucrat::signForm(AForm &form) {
	try	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << '\n';
	}
	catch (const std::exception &exception)	{
		std::cerr << this->getName() << " can't sign form " << form.getName() << ": ";
		std::cerr  << exception.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << '\n';
	}
	catch (const std::exception &exception)	{
		std::cerr << this->getName() << " can't execute form " << form.getName() << ": ";
		std::cerr << exception.what() << '\n';
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

void testBureaucrat(std::string const name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << "Bureaucrat "<< bureaucrat.getName();
		std::cout << " successfully constructed with grade ";
		std::cout << bureaucrat.getGrade() << '\n';
	}
	catch (const std::exception &exception)	{
		std::cerr << "Can't create bureaucrat with grade ";
		std::cerr << grade << ": " << exception.what() << '\n';
		return ;
	}
}
