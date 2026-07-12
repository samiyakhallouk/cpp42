#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(const int index) const
{
    if (0 <= index && 100 > index)
        return (this->ideas[index]);
    else
        return ("Invalid index!");
}

void Brain::setIdea(const std::string &idea, const int index)
{
    if (0 <= index && 100 > index)
        this->ideas[index] = idea;
    else
        std::cout << "Invalid index!" << std::endl;
}
