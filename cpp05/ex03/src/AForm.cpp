#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150), _target("unknown")
{
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute, std::string const target) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target)
{
}

AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm()
{
}

std::string const AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

std::string const AForm::getTarget() const
{
	return (_target);
}

void AForm::beSigned(Bureaucrat const &signee)
{
	if (signee.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	beExecuted();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed");
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade ";
	out << form.getGradeToExecute() << " to execute";
	return (out);
}

