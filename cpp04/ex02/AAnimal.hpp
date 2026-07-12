#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(const AAnimal & other);
    AAnimal & operator=(AAnimal const & other);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;
    std::string getType( void ) const;
};

#endif