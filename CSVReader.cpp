#include "CSVReader.h"
CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;
    return entries;
}
std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    return tokens;
}
OrderBookEntry CSVReader::stringToOrderBookEntry(std::vector<std::string> strings)
{
    return OrderBookEntry{
        0, 
        0, 
        "", 
        "", 
        OrderBookType::bid
    };
    return OrderBookEntry{0, 0, "", "", OrderBookType::bid};
}

