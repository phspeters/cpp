#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>	

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		Contact();
		~Contact();
		void		setContactInfo();
		void		displayContactInfo() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
};

std::string	truncateString(const std::string& str);
void 		readInput(std::istream &input, std::string& buffer);

#endif