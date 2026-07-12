#include "Zombie.hpp"

void leak(void) {
    system("leaks ex01");
}

int main()
{
    atexit(leak);
    Zombie* zombie;
    int N = 3;
    if (N <= 0)
        return (1);
    zombie = zombieHorde(N, "name");
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
    delete[]zombie;
    return (0);
}