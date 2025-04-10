#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;

    while (true) {
        std::cout << "Commands: ADD, SEARCH, EXIT\n";
        std::cout << "Enter a command: " << std::flush;

        std::string command;
        getline(std::cin, command);

        if (command == "EXIT" || std::cin.eof()) {
            break;
        } else if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else {
            std::cout << "Invalid command\n\n";
        }
    }
}
