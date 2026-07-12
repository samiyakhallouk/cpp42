#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);;

        for (size_t i = 0; i < a.size(); i++)
        {
            a[i] = i + 1;
        }
        
        Array<int>b = a;
        b[0] = 12;
        std::cout << a[0] << std::endl;
        std::cout << b[0] << std::endl;
        std::cout << a[6] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}