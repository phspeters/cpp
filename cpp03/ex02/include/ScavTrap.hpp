#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
   public:
    // constructors
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& scavtrap);

    // assignment operator
    ScavTrap& operator=(const ScavTrap& scavtrap);

    // destructor
    ~ScavTrap(void);

    // member functions
    void attack(const std::string& target);
    void guardGate(void);
};

#endif