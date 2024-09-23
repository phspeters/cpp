#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const
{
     std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
