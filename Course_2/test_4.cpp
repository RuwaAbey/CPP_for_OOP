#include <iostream>

int main()
{
    signed long i = 65537;

    std::cout << "size of signed long: " << sizeof(i) << std::endl;
    std::cout << "size of unsigned short: " << sizeof(unsigned short) << std::endl;
    std::cout << "i contains " << i << std::endl;

    return 0;
}