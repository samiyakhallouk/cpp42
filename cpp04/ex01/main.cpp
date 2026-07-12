#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // std::cout << "\n--- Calling constructors ---\n" << std::endl;
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // Brain b;

    // std::cout << "\n----------------------------\n" << std::endl;
    
    // std::cout << b.getIdea(0) << std::endl;
    // b.setIdea("Food", 0); 
    // std::cout << b.getIdea(0) << std::endl; 

    // std::cout << "\n----------------------------\n" << std::endl;

    int size = 10;
    Animal* animals[size];
    Brain b;
    for (size_t i = 0; i < 10; i++)
    {
        b.setIdea("hhh", i);
    }
    

    std::cout << "\n--- Calling constructors ---\n" << std::endl;

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    

    std::cout << "\n--- Deleting animals ---\n" << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        delete animals[i];
    }
    
    // std::cout << "\n--- calling destructors ---\n" << std::endl;
    // delete j;
    // delete i;

    return 0;
}