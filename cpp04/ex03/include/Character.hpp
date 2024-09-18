#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string const &name);
	Character(Character const &src);
	~Character();
	Character &operator=(Character const &rhs);
};

#endif