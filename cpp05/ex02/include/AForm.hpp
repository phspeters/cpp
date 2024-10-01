#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	//Constructors
	Form();
	Form(std::string const name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);

	//Assignation operator
	Form &operator=(Form const &other);

	//Destructor
	~Form();

	//Member functions
	std::string const getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	//Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &form);
void testForm(std::string const name, int gradeToSign, int gradeToExecute);

#endif