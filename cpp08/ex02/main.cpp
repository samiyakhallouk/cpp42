#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mystack;

    mystack.push(3);
    mystack.push(2);
    mystack.push(1);
    mystack.push(53);
    mystack.push(4);
    mystack.push(7);
    
    // std::cout << mystack.top() << std::endl;
    MutantStack<int>::iterator it = mystack.begin();
    it++;

    mystack.pop();
    for (; it != mystack.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "---------------------------------\n";

    MutantStack<int> ss(mystack);

    ss.top() = 40;
    it = ss.begin();
    for (; it != ss.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}