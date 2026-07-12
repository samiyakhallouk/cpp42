#include <iostream>


int main()
{
    std::string s;
    s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "The memory address of the string: " << &s << std::endl;
    std::cout << "The memory address of the stringPTR: " << &stringPTR << std::endl;
    std::cout << "The memory address of the stringREF: " << &stringREF << std::endl;
    std::cout << "---------------------------------------------------"<< std::endl;

    std::cout << "The value of the string: " << s << std::endl;
    std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value of the stringREF: " << stringREF << std::endl;

}