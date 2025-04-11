#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    // Constructors
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);

    // Assignment operator
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    // Destructor
    ~PresidentialPardonForm();

    // Member functions
    void beExecuted() const;
};

#endif