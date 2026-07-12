#include "Zombie.hpp"


Zombie::Zombie()
{

}

Zombie::~Zombie()
{
    std::cout << name << " is desroyed" << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}