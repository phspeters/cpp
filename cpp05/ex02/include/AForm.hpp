#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	//Constructors
	AForm();
	AForm(std::string const name, int gradeToSign, int gradeToExecute, std::string const target);
	AForm(AForm const &other);

	//Assignment operator
	AForm &operator=(AForm const &other);

	//Destructor
	~AForm();

	//Member functions
	std::string const getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string const getTarget() const;
	void beSigned(Bureaucrat const &signee);
	void execute(Bureaucrat const &executor) const;

	//Exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	
protected:
	virtual void beExecuted() const = 0;

private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;
	std::string const _target;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif