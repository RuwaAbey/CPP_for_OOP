#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:

        OrderBookEntry(double _price,
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

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
  
};

std::string orderBookTypeToString(OrderBookType type)
{
    if (type == OrderBookType::bid)
        return "bid";
    else
        return "ask";
}

double computeAveragePrice(std::vector<OrderBookEntry>& entries)
{

    double sum = 0;
    for(unsigned int i = 0; i < entries.size(); ++i)
   {
       sum += entries[i].price;
    
   }

   return sum / entries.size();

}

double computeLowPrice(std::vector<OrderBookEntry>& entries)
{
     double lower_price = entries[0].price;

    for(unsigned int i = 0; i < entries.size(); ++i)
   {
      

       if (entries[i].price < lower_price)
       {
        lower_price = entries[i].price;
       }
    
   }
   return lower_price;
}

double computeHighPrice(std::vector<OrderBookEntry>& entries)
{
   double higher_price = entries[0].price;
    for(unsigned int i = 0; i < entries.size(); ++i)
   {
       if (entries[i].price > higher_price)
       {
        higher_price = entries[i].price;
       }
    
   }
   return higher_price;
}

double computePriceSpread(std::vector<OrderBookEntry>& entries)
{
    double low_price = computeLowPrice(entries);
    double high_price = computeHighPrice(entries);

    return high_price - low_price;
}

int main(){

    std::vector<OrderBookEntry> orders;

    orders.push_back(OrderBookEntry{ 1000, 
                                     0.02, 
                                     "2020/03/17 17:01:24.884492", 
                                     "BTC/USDT", 
                                     OrderBookType::bid
                                    });

    orders.push_back(OrderBookEntry{ 2000, 
                                     0.02, 
                                     "2020/03/17 18:01:24.884492", 
                                     "BTC/USDT", 
                                     OrderBookType::bid
                                    });

    orders.push_back(OrderBookEntry{ 3000, 
                                     0.04, 
                                     "2020/03/17 19:01:24.884492", 
                                     "BTC/USDT", 
                                     OrderBookType::bid
                                    });
    
    orders.push_back(OrderBookEntry{ 4000, 
                                     0.02, 
                                     "2020/03/17 20:01:24.884492", 
                                     "BTC/USDT", 
                                     OrderBookType::ask
                                    });                                   



   for(unsigned int i = 0; i < orders.size(); ++i)
   {
    //classic syntax
       std::cout << "==========================" << std::endl;
       std::cout << "The data of order: " << i << std::endl;
       std::cout << "The price is: " << orders[i].price << std::endl;
       std::cout << "The amount is: " << orders[i].amount << std::endl;
       std::cout << "The timestamp is: " << orders[i].timestamp << std::endl;
       std::cout << "The product is: " << orders[i].product << std::endl;
       std::cout << "The order type is: "
          << orderBookTypeToString(orders[i].orderType)
          << std::endl;
  
   }

   std::cout << "==========================" << std::endl;

   std::cout << "Average price is: " << computeAveragePrice(orders) << std::endl;
   std::cout << "Low price is: " << computeLowPrice(orders) << std::endl;
   std::cout << "High price is: " << computeHighPrice(orders) << std::endl;
   std::cout << "Price spread is: " << computePriceSpread(orders) << std::endl;

}
