#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // std::cout << "\n--- Calling constructors ---\n" << std::endl;
    const AAnimal* j = new Dog();
    j->makeSound();
    Brain b;

    std::cout << "\n----------------------------\n" << std::endl;
    
    std::cout << b.getIdea(0) << std::endl;
    b.setIdea("Food", 0); 
    std::cout << b.getIdea(0) << std::endl; 
    
    std::cout << "\n--- calling destructors ---\n" << std::endl;
    delete j;

    return 0;
}