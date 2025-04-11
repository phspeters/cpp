#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat {
   public:
    // Constructors
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);

    // Assignment operator
    Bureaucrat& operator=(const Bureaucrat& other);

    // Destructor
    ~Bureaucrat();

    // Member functions
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);

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
    int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
void testBureaucrat(const std::string name, int grade);

#endif