#include "iter.hpp"

void upper(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    
}

void increment(int &i)
{
    i++;
}

void print(const std::string &std)
{
    std::cout << std << std::endl;
}


int main()
{
    {
        std::string array[4]= {"bobo", "coco", "soso", "nono"};

        ::iter(array, array->length(), upper);
        for (size_t i = 0; i < 4; i++)
        {
            std::cout << array[i] << std::endl;
        }
        ::iter(array, 0, print);
    }
    {
        int array[4] = {0, 1, 2, 3};

        ::iter(array, 4, increment);
        for (size_t i = 0; i < 4; i++)
        {
            std::cout << array[i] << std::endl;
        }
        
    }
}