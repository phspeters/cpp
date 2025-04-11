#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExecuted() const {
    std::ofstream file((getTarget() + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "	  /\\\n";
        file << "	 /\\*\\\n";
        file << "	/\\O\\*\\\n";
        file << "   /*/\\/\\/\\\n";
        file << "  /\\O\\/\\*\\/\\\n";
        file << " /\\*\\/\\*\\/\\/\\\n";
        file << "/\\O\\/\\/*/\\/O/\\\n";
        file << "	  ||\n";
        file << "	  ||\n";
        file << "	  ||\n";
        file << "	\\====/\n";
        file << "	/\\/\\/\\\n";
        file.close();
    }
}
