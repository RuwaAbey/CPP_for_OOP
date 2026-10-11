#include <iostream>
#include <vector>
#include <iostream>

std::vector<std::string> tokenise(std::string csvLine, char seperator)
{

// string vector tokens ## stores the tokens
    std::vector<std::string> tokens;

// int start, end ## used to delineate the position of the tokens
    signed int start, end;
    std::string token;

// start = csvLine.find_first_not_of(separator)
    start = csvLine.find_first_not_of(seperator,0);
// do
    do{
//     end = next 'seperator' after start
        end = csvLine.find(seperator,start);
//     if start == csvLine.length or start == end ## nothing more to find
        if (start == csvLine.length() || start == end) break;
//         break
//     if end >= 0 ## we found the seperator
        if (end >= 0) token = csvLine.substr(start, end - start);
//         token = csvLine.substr(start, end - start) ##start, substring length
//     else
//         token = csvLine.substr(start, csvLine.length - start) ## end is invalid
        else token = csvLine.substr(start, csvLine.length() -start);

//     tokens.push_back(token) ##save the token
        tokens.push_back(token);

//     start = end + 1 ## move past this token
        start = end + 1;
    } while (end > 0);

// while (end > 0) ## continue loop condition
    return tokens;
}

int main()
{

    std::vector<std::string> tokens;
    std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.0218238,41.5";
    tokens = tokenise(s, ',');
    for (std::string t : tokens)
    {
        std::cout << t << std::endl;
    }
    return 0;

}