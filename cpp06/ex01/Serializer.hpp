#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string name;
    int id;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
    public:
        static uintptr_t Serialize(Data* ptr);
        static Data* deSerialize(uintptr_t raw);
};



#endif