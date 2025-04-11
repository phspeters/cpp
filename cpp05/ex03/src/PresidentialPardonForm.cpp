#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::beExecuted() const {
    std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox.\n";
}
