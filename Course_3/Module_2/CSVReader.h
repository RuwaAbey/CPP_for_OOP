#pragma once

#include "OrderBookEntry.h"
#include <vector>

class CSVReader
{
    public:
       CSVReader();
       
       static std::vector<OrderBookEntry> readCSV(std::string csvFile);

    private:
       static std::vector<std::string> tokenise(std::string csvLine, char seperator);
       static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};