#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>


int main()
{
    std::vector<int> d(3);

    d.push_back(1);
    d.push_back(3);
    d.push_back(0);

    for (size_t i = 0; i < 3; i++)
    {
        std::cout << d[i] << std::endl;
    }
    
}