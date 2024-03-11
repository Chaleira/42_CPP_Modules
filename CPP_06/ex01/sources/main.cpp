#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data        data = {42};
    uintptr_t   ptr;
    Data        *data_ptr;

    ptr = Serializer::serialize(&data);
    data_ptr = Serializer::deserialize(ptr);
    if (&data == data_ptr)
        std::cout << "Data is the same" << std::endl;
    else
        std::cout << "Data is different" << std::endl;
    return 0;
}
