#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   public:
    // Constructors
    Form();
    Form(const std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);

    // Assignment operator
    Form& operator=(const Form& other);

    // Destructor
    ~Form();

    // Member functions
    const std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

   private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& form);
void testForm(const std::string name, int gradeToSign, int gradeToExecute);

#endif