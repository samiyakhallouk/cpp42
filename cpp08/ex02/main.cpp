#include "MutantStack.hpp"

int main()
{
    std::list<int> l(5);

    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    std::list<int>::iterator it = l.begin();
    *it = 11;

    for (; it != l.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    return (0);
}