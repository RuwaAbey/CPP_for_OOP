#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    for (const std::string& s : strings)
    {
        std::cout << s << std::endl;
    }
}