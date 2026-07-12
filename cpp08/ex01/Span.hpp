#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    private:
        unsigned int N;
        std::vector <int> container;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();

        class IsFull : public std::exception
        {
            const char *what() const throw();
        };

        class NoSpanCanBeFound : public std::exception
        {
            const char *what() const throw();
        };

        template<typename iterator>
        void addrange(iterator begin, iterator end)
        {
            if (container.size() + std::distance(begin, end) > N)
                throw IsFull();
                
            container.insert(container.end(), begin, end);
        }
};





#endif