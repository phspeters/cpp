#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::beExecuted() const {
    srand(time(NULL));

    std::cout
        << "Wzzzzt... VRRRRRRRRRRR... ZZZZZZZZZZZT... BRRRRRRR... Vrrrr\n";
    if (rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully.\n";
    } else {
        std::cout << getTarget() << " resisted robotomization.\n";
    }
}
