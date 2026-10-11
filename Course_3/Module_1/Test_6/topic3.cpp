#include <string>
#include <iostream>

int main()
{
    double d = 0;
    std::string s = "adcsg";
    try
    {
        d = std::stod(s);
    }
    catch (const std::exception& e)
    {
        
    }
    
    std::cout << "d: " << d << std::endl;
}