#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
    // Constructors
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& other);

    // Assignment operator
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    // Destructor
    ~RobotomyRequestForm();

    // Member functions
    void beExecuted() const;
};

#endif