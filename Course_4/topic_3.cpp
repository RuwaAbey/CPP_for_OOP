#include <string>
#include <iostream>

int main()
{
    std::string s = "Matthew";
    std::cout << "length of s " << s.length() << std::endl;

    s = "Something else";
    std::cout << "length of s " << s.length() << std::endl;

    std::stod("10");
}