#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap's Default constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap's Constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other) :ClapTrap(other)
{
    std::cout << "FragTrap's Copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap's Copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's Destructor called" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    if (hit_points > 0 && energy_points > 0)
        std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
    else
        std::cout << "FragTrap " << name << " is out of energy or hit points!" << std::endl;
}
