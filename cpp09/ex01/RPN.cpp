#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other){s = other.s;}

RPN& RPN::operator=(const RPN& other) 
{
    if (this != &other)
    {
        s = other.s;
    }
    return (*this);
}

void RPN::parse_line(std::string line) 
{
    std::stringstream ss(line);
    std::string token;
    float rsl = 0;
    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            s.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (s.size() < 2)
                throw std::runtime_error("Error");
            float sec = s.top();
            s.pop();
            float first = s.top();
            s.pop();
            rsl = calcul(first, sec, token[0]);
            s.push(rsl);
        }
        else
            throw std::runtime_error("Error");

    }
    if (s.size() != 1)
        throw std::runtime_error("Error");
    std::cout << "> Result: " << s.top() << std::endl;
}

float RPN::calcul(float first, float sec, char c)
{
    if (c == '+')
        return (first + sec);
    else if (c == '-')
        return (first - sec);
    else if (c == '/')
    {
        if (sec == 0)
        throw std::runtime_error("Division by zero");
        return (first / sec);
    }
    else
        return (first * sec);
}