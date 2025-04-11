#include "Form.hpp"

Form::Form()
    : _name("default"),
      _signed(false),
      _gradeToSign(150),
      _gradeToExecute(150) {}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form &other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }

    return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return _name; }

bool Form::getSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    }

    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName() << " is "
        << (form.getSigned() ? "signed" : "NOT signed");
    out << " and requires grade " << form.getGradeToSign()
        << " to sign and grade ";
    out << form.getGradeToExecute() << " to execute";
    return out;
}

void testForm(const std::string name, int gradeToSign, int gradeToExecute) {
    try {
        Form form(name, gradeToSign, gradeToExecute);
        std::cout << form << '\n';
    } catch (const std::exception &exception) {
        std::cerr << "Error: can't create form " << name << ": "
                  << exception.what() << '\n';
    }
}
