#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry( double _price, 
                        double _amount, 
                        std::string _timestamp, 
                        std::string _product, 
                        OrderBookType _orderType)
: price(_price), 
  amount(_amount), 
  timestamp(_timestamp),
  product(_product), 
  orderType(_orderType)
{
    
}

// in the cpp file we dont need to repeat the static keyword because we are not defining the function here we are just declaring it. 
// We only need to use the static keyword in the header file when we are declaring the function. 
// In the cpp file we just need to define the function without the static keyword.
// namespace it with "orderBookEntry::" to show that this function belongs to the OrderBookEntry class. 
// We know the function belongs to the OrderBookEntry class because we declared it in the header file as a static function.
OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
   if ( s == "ask")
   {
       return OrderBookType::ask;
   }
   if ( s == "bid")
   {
       return OrderBookType::bid;
   }
  return OrderBookType::unknown;
}
