#include "CSVReader.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include <fstream>

CSVReader::CSVReader()
{

}

// This function reads a csv file and returns a vector of OrderBookEntry objects.
std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    // declare a vector of OrderBookEntries
    std::vector<OrderBookEntry> entries;
    // By calling the constructor of the ifstream class we can open the csv file and read from it. 
    // The ifstream class is a part of the fstream library and is used for reading from files. 
    // We pass the csv filename as a parameter to the constructor to open the file.
    std::ifstream csvFile{csvFilename};
    std::string line;
    if (csvFile.is_open())
    {
        while(std::getline(csvFile, line))
        {
            try{
            OrderBookEntry obe = stringToOrderBookEntry(tokenise(line, ','));
            entries.push_back(obe);
            } catch (const std::exception& e)
            {
                std::cout << "CSVReader::readCSV bad data" << std::endl;
                std::cout << "Error processing line: " << line << std::endl;
                std::cout << "Exception message: " << e.what() << std::endl;
            }
        }
    }
    std::cout << "CSVReader::readCSV - Finished reading file: " << entries.size() << " entries" << std::endl;
    return entries;
}

// Takes in a line of text from the csv file and splits it into a vector of strings based on the separator character.
std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    // stores the tokens
    std::vector<std::string> tokens;
    // created start and end variables to delineate the position of the tokens in the csv line.
    signed int start, end;
    // declare variable to store the temporary token
    std::string token;
    // start the algorithm by finding the first character that is not the separator character. This will be the start of the first token.
    start = csvLine.find_first_not_of(separator);
    do
    {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end)
        break;
        if (end >= 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token); // add token to vector
        start = end + 1;     // move past the token
    } while (end > 0);
    //continue the loop condition
    return tokens;
}

// Takes in a vector of strings and converts it into an OrderBookEntry object. 
// The vector of strings represents the columns in the csv file. 
// The first column is the timestamp, the second column is the product, the third column is the order type, the fourth column is the price and the fifth column is the amount.
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

            OrderBookEntry obe{
                price, 
                amount, 
                tokens[0], // timestamp represented by tokens[0] because the first column in the csv file is the timestamp
                tokens[1], // product represented by tokens[1] because the second column in the csv file is the product
                OrderBookEntry::stringToOrderBookType(tokens[2]) // order type represented by tokens[2] because the third column in the csv file is the order type
            };
            return OrderBookEntry{0, 0, "", "", OrderBookType::bid};
}

