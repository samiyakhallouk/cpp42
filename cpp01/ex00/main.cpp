#include "Zombie.hpp"

int main()
{
    std::string name = "Foo";
    Zombie* zombie;
	zombie = newZombie(name);
	zombie->announce();
	randomChump("name");
    delete(zombie);
    return 0;
}