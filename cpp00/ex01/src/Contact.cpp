#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContactInfo()
{
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	std::cout << "Contact saved\n" << std::endl;
}

void	Contact::displayContactInfo()
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << '\n' << std::endl;

}

std::string	Contact::getFirstName()
{
	return firstName;
}

std::string	Contact::getLastName()
{
	return lastName;
}

std::string	Contact::getNickname()
{
	return nickname;
}

std::string truncateString(const std::string& str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}