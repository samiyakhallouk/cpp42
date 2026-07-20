#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "**********************VECTOR**********************\n";
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    try
    {
        ::easyfind(v, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "**********************LIST************************\n";

    std::list<int> l;
    l.push_back(11);
    l.push_back(5);
    l.push_back(3);
    l.push_back(74);

    try
    {
        easyfind(l, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "**********************DEQUE***********************\n";

    std::deque<int> d;
    l.push_back(8);
    l.push_back(1);
    l.push_back(12);
    l.push_back(-3);

    try
    {
        easyfind(d, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}