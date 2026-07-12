#include <iostream>
#include <stdlib.h>

int main(int ac, char **av)
{
    char c;
    int i = 1;
    int j;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                c = toupper(av[i][j]);
                std::cout << c;
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
}