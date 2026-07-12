#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T_array, typename Fun>
void iter(T_array *add, const size_t lenght, Fun f)
{
    if (!add)
        return ;

    for (size_t i = 0; i < lenght; i++)
    {
        f(add[i]);
    }
}

#endif