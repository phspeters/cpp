#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	contacts[contactCount % 8].setContactInfo();
	contactCount++;
}

void PhoneBook::searchContact() {
	if (contactCount == 0) {
		std::cout << "Phonebook is empty\n\n";
		return;
	}

	std::cout << "Saved contacts:\n";
	std::cout << "	 Index|First Name| Last Name|  Nickname\n";
	std::cout << "-------------------------------------------\n";
	int displayCount = std::min(contactCount, 8);
	for (int i = 0; i < displayCount; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << '\n';
	}
	std::cout << "-------------------------------------------" << '\n' << '\n';

	std::cout << "Enter index of contact to be displayed: ";
	std::string str_index;
	getline(std::cin, str_index);

	int index = std::atoi(str_index.c_str());
	if ((str_index != "0"  && index <= 0) || index >= displayCount) {
		std::cout << "Invalid index\n\n";
		return;
	}
	contacts[index].displayContactInfo();
}
