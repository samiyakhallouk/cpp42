#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "\033[35m---------------Vector Test---------------\033[m" << std::endl;

    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
    {
        easyfind(v, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\033[35m---------------Deque Test----------------\033[m" << std::endl;

    std::deque<int> d;
    d.push_back(53);
    d.push_back(3);
    d.push_front(11);
    try
    {
        easyfind(d, 2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\033[35m---------------List Test-----------------\033[m" << std::endl;

    std::list<int> l;
    l.push_back(5);
    l.push_back(13);
    l.push_back(0);

    try
    {
        easyfind(l, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
