#include "FragTrap.hpp"

int main()
{
    FragTrap a("Frag");

    a.attack("Enemy");
    a.highFivesGuys();

    FragTrap b(a);
    b.attack("Copy");

    FragTrap c;
    c = a;
    c.attack("Assigned");

    return 0;
}
