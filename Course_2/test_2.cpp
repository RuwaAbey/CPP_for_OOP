#include <iostream>

int main()
{
    unsigned long i = 65536;

    std::cout << "Size of unsigned short " << sizeof(unsigned short) << std::endl;
    std::cout << "Size of unsigned short " << sizeof(unsigned long) << std::endl;
    std::cout << "i contains " << i << std::endl;

    return 0;
}