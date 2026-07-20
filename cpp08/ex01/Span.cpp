#include "Span.hpp"

Span::Span()
{
    N = 0;
}

Span::Span(unsigned int n)
{
    N = n;
}

Span::Span(const Span &other)
{
    N = other.N;
    container = other.container;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        container = other.container;   
    }
    return (*this);
}

Span::~Span(){}

const char* Span::IsFull::what() const throw()
{
    return ("Span is full: you can´t add more numbers");
}

const char* Span::NoSpanCanBeFound::what() const throw()
{
    return ("Not enough numbers to find a span");
}

void Span::addNumber(int nb)
{
    if (N <= container.size())
        throw IsFull();
    container.push_back(nb);
}

int Span::shortestSpan()
{
    int min;
    size_t len = container.size();
    if (len < 2)
        throw NoSpanCanBeFound();

    std::vector<int> tmp = container;
    std::sort(tmp.begin(), tmp.end());
    min = tmp[1] - tmp[0];
    for (size_t i = 1; i < len - 1; i++)
    {
        int tmp_min = tmp[i + 1] - tmp[i];
        if (tmp_min < min)
            min = tmp_min;
    }
    return (min);
}

int Span::longestSpan()
{
    int max;
    if (container.size() < 2)
        throw NoSpanCanBeFound();

    std::vector<int> tmp = container;
    std::sort(tmp.begin(), tmp.end());
    max = tmp[tmp.size() - 1] - tmp[0];
    return (max);
}
