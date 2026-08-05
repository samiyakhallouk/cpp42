#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<float> s;
    public:
        RPN();
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        ~RPN();

        void parse_line(std::string);
        float calcul(float, float, char);
};






#endif