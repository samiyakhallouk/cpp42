#include "Span.hpp"

int main()
{

    try
    {
        // Span sp = Span(5);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;

        std::vector<int> v;
        for (size_t i = 0; i < 10000; i++)
        {
            v.push_back(i);
        }
        std::cout << "---------------------------" << std::endl;
        Span s(10001);
        s.addNumber(3);
        s.addrange(v.begin(), v.end());
    
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}