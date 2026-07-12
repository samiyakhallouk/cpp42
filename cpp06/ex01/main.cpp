#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "IDK";

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "id: " << data.id << ", name: " << data.name << std::endl;

    uintptr_t raw = Serializer::Serialize(&data);

    std::cout << "\nSerializerd value: " << raw << std::endl;

    Data* recovered = Serializer::deSerialize(raw);

    std::cout << "\nRecovered pointer: " << recovered << std::endl;
    std::cout << "id: " << recovered->id << ", name: " << recovered->name << std::endl;

    if (recovered == &data)
        std::cout << "\n✔ Same pointer recovered!" << std::endl;
    else
        std::cout << "\n❌ Different pointer!" << std::endl;

    return 0;
}