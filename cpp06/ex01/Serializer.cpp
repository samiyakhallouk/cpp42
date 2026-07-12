#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer &other)
{
    (void)other;
    return *this;
}

uintptr_t Serializer::Serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deSerialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

