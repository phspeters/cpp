#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact();

   private:
    int contactCount;
    Contact contacts[8];
};

#endif