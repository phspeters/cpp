#include "AForm.hpp"

AForm::AForm()
    : _name("default"),
      _signed(false),
      _gradeToSign(150),
      _gradeToExecute(150),
      _target("unknown") {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute,
             const std::string target)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute),
      _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute),
      _target(other._target) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }

    return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const { return _name; }

bool AForm::getSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

const std::string AForm::getTarget() const { return _target; }

void AForm::beSigned(const Bureaucrat &signee) {
    if (signee.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }

    _signed = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!_signed) {
        throw AForm::FormNotSignedException();
    }

    if (executor.getGrade() > _gradeToExecute) {
        throw AForm::GradeTooLowException();
    }

    beExecuted();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << " is "
        << (form.getSigned() ? "signed" : "NOT signed");
    out << " and requires grade " << form.getGradeToSign()
        << " to sign and grade ";
    out << form.getGradeToExecute() << " to execute";
    return out;
}
