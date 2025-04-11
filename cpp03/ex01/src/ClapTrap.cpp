#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("'without a name'"),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been constructed by default!\n";
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " has been constructed!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;

    std::cout << "ClapTrap " << _name << " has been copy constructed!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::string oldName = _name;

    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }

    if (oldName != "") {
        std::cout << "ClapTrap " << oldName
                  << " has been assigned the attributes of " << _name << '\n';
    } else {
        std::cout << "ClapTrap has been assigned the attributes of " << _name
                  << '\n';
    }

    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << _name << " has been destroyed!\n";
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " is already dead and can't attack!\n";
        return;
    }

    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " is out of energy points and can't attack!\n";
        return;
    }

    _energyPoints--;

    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " is already dead and can't take more damage!\n";
        return;
    }

    if (amount > _hitPoints) {
        amount = _hitPoints;
    }

    _hitPoints -= amount;

    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " is already dead and can't be repaired!\n";
        return;
    }

    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name
                  << " is out of energy points and can't be repaired!\n";
        return;
    }

    _hitPoints += amount;
    _energyPoints--;

    std::cout << "ClapTrap " << _name << " is repaired for " << amount
              << " points!\n";
}

std::string ClapTrap::getName(void) const { return _name; }

unsigned int ClapTrap::getHitPoints(void) const { return _hitPoints; }

unsigned int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }

unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;

    std::cout << "ClapTrap " << _name
              << " has had its hitpoints artificially set to " << hitPoints
              << "!\n";
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;

    std::cout << "ClapTrap " << _name
              << " has had its energy points artificially set to "
              << energyPoints << "!\n";
}
