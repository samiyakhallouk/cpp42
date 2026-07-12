#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
void easyfind(T& c, int i)
{
    typename T::iterator it = std::find(c.begin(), c.end(), i);
    if (it == c.end())
        throw std::runtime_error ("Not found!");
    std::cout << "Found: " << *it << std::endl;
}


#endif