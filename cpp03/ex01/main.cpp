#include "ScavTrap.hpp"

int main()
{
    std::cout << "---- Create ScavTrap A ----" << std::endl;
    ScavTrap a("Guardian");

    std::cout << "\n---- Attack test ----" << std::endl;
    a.attack("Intruder");

    std::cout << "\n---- Guard Gate mode ----" << std::endl;
    a.guardGate();

    std::cout << "\n---- Copy constructor test ----" << std::endl;
    ScavTrap b(a);
    b.attack("Copy target");

    std::cout << "\n---- Assignment operator test ----" << std::endl;
    ScavTrap c;
    c = a;
    c.attack("Assigned target");

    std::cout << "\n---- Energy depletion test ----" << std::endl;
    for (int i = 0; i < 5; i++)
        a.attack("Energy drain");

    std::cout << "\n---- Destructor test ----" << std::endl;
    return 0;
}
