#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
    // Constructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);

    // Assignment operator
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    // Destructor
    ~ShrubberyCreationForm();

    // Member functions
    void beExecuted() const;
};

#endif