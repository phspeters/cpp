#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Contact {
   public:
    Contact();
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;

    void setContactInfo();
    void displayContactInfo() const;

   private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

std::string truncateString(const std::string& str);
void readInput(std::istream& input, std::string& buffer);

#endif