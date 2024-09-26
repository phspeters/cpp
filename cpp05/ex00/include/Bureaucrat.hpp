#ifndef	BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
public:
	//Constructors
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &other);

	//Assignation operator
	Bureaucrat &operator=(Bureaucrat const &other);

	//Destructor
	~Bureaucrat();

	//Member functions
	std::string const getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

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
	int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif