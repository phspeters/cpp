#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContactInfo()
{
	std::cout << "Enter first name: ";
	readInput(std::cin, firstName);

	std::cout << "Enter last name: ";
	readInput(std::cin, lastName);

	std::cout << "Enter nickname: ";
	readInput(std::cin, nickname);

	std::cout << "Enter phone number: ";
	readInput(std::cin, phoneNumber);

	std::cout << "Enter darkest secret: ";
	readInput(std::cin, darkestSecret);
	
	std::cout << "Contact saved\n" << std::endl;
}

void	Contact::displayContactInfo() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << '\n' << std::endl;

}

std::string	Contact::getFirstName() const
{
	return firstName;
}

std::string	Contact::getLastName() const
{
	return lastName;
}

std::string	Contact::getNickname() const
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

void readInput(std::istream &input, std::string& buffer)
{
	std::getline(input, buffer);
	while (buffer.empty())
	{
		std::cout << "Contact field cannot be empty. Please try again: ";
		std::getline(input, buffer);
	}
}
