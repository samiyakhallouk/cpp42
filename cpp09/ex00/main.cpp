#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange btc;
    try
    {
        btc.shearch_on();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}