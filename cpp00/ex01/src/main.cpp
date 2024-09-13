#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook	phonebook;

	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::string	command;

		std::cout << "Enter a command: " << std::flush;
		std::cin >> command;
		if (command == "EXIT" || std::cin.eof())
			break;
		else if (command == "ADD")
		{
			phonebook.addContact();
		}
		else if (command == "SEARCH")
		{
			phonebook.searchContact();
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
}
