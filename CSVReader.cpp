#include "CSVReader.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
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
OrderBookEntry CSVReader::stringToOrderBookEntry(std::vector<std::string> tokens)
{
    double price, amount;
     if (tokens.size() != 5) //bad
            {
                std::cout << "Invalid line: " << std::endl;
                throw std::exception{};
            }
       

    
            try {
                price = std::stod(tokens[3]);
                amount = std::stod(tokens[4]);
                std::cout << "Price: " << price << " Amount: " << amount << std::endl;

            } catch (const std::exception& e) {
                std::cout << "Invalid number in line due to a bad float: " << tokens[3] << std::endl;
                std::cout << "Invalid number in line due to a bad float: " << tokens[4] << std::endl;
                throw;
            }

            for (const std::string& t : tokens)
            {
                std::cout << t << std::endl;
            }
            std::cout << "==============" << std::endl;
            OrderBookEntry{
                price, 
                amount, 
                tokens[0], // timestamp represented by tokens[0] because the first column in the csv file is the timestamp
                tokens[1], // product represented by tokens[1] because the second column in the csv file is the product
                OrderBookEntry::stringToOrderBookType(tokens[2]) // order type represented by tokens[2] because the third column in the csv file is the order type
            };
            return OrderBookEntry{0, 0, "", "", OrderBookType::bid};
}

