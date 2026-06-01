#pragma once 
#include "OrderBookEntry.h"
#include <vector>
#include <string>


class CSVReader
{
    public:
        CSVReader();
        static std::vector<OrderBookEntry> readCSV(std::string csvFile); //stateless function - does rely on anything else 
    private:
        // static OrderBookEntry stringToOrderBookEntry(std::string csvLine);
        static  std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> strings);


};