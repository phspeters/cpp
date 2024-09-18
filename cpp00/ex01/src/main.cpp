#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook	phonebook;


	while (true)
	{
		std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Enter a command: " << std::flush;

		std::string	command;
		getline(std::cin, command);
		
		if (command == "EXIT" || std::cin.eof())
			break;
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Invalid command\n" << std::endl;
	}
}
