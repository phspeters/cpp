#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    // constructors
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap& fragtrap);

    // assignment operator
    FragTrap& operator=(const FragTrap& fragtrap);

    // destructor
    ~FragTrap(void);

    // member functions
    void highFivesGuys(void);
};

#endif