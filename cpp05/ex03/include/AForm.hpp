#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
   public:
    // Constructors
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExecute,
          const std::string target);
    AForm(const AForm& other);

    // Assignment operator
    AForm& operator=(const AForm& other);

    // Destructor
    virtual ~AForm();

    // Member functions
    const std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string getTarget() const;
    void beSigned(const Bureaucrat& signee);
    void execute(const Bureaucrat& executor) const;

    // Exceptions
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

   protected:
    virtual void beExecuted() const = 0;

   private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif