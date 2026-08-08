#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    try
    {
        PmergeMe merge;
        merge.fordJohnsonAlgo(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}