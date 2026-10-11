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

void printMenu()
{
    //1 print help
    std::cout << "1: Print Help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer" << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6 continue
    std::cout <<  "6: Continue" << std::endl;

    std::cout << "=============" << std::endl;
    
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make bids and offers" << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks good" << std::endl;
}

void enteroffer() 
{
    std::cout << "Make and offer - enter the amount" << std::endl;
}

void enterBId()
{
    std::cout << "Make a bid -  enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}

void gotonextTimeFrame()
{
    std::cout << "Going to next time frame" << std::endl;
}

int getUserOption()
{
    int userOption;

    std::cout << "Type 1 - 6" << std::endl;
    std::cin >> userOption;
    std::cout << "You choose: " << userOption << std::endl;

    return userOption;
}

void processUserOption(int userOption){

    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enteroffer();
    }
    if (userOption == 4)
    {
        enterBId();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotonextTimeFrame();
    }
    
}

int main(){

/*
    std::string timestamp{"2020/03/17 17:01:24.884492"};
    std::string product{"BTC/USDT"};
    //std::string orderType{"bid"};
    enum class OrderBookType{bid, ask};
    OrderBookType orderType = OrderBookType::bid;
    //bool orderType = true;
    
    std::string timestamp2{"2020/03/17 17:01:24.884492"};
    std::string product2{"BTC/USDT"};
    //std::string orderType{"bid"};
    enum class OrderBookType2{bid, ask};
    OrderBookType orderType = OrderBookType::bid;
 */

//We can use growable array like above

    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timestamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderTypes;

    // prices.push_back(5000.3234);
    // amounts.push_back(0.001);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::bid);

    // std::cout << "prices: " << prices[0] << std::endl;
    // std::cout << "amounts: " << amounts[0] << std::endl;
    // std::cout << "timestamps: " << timestamps[0] << std::endl;
    // std::cout << "products: " << products[0] << std::endl;
    // std::cout << "orderTypes: " << static_cast<int>(orderTypes[0]) << std::endl;

    // while(true){
        
    //     printMenu();

    //     int userOption = getUserOption();
        
    //     processUserOption(userOption);
    // }

    std::vector<OrderBookEntry> orders;

    OrderBookEntry order1{1000, 
                          0.02, 
                          "2020/03/17 17:01:24.884492", 
                          "BTC/USDT", 
                          OrderBookType::bid};

    OrderBookEntry order2{1000, 
                          0.02, 
                          "2020/03/17 17:01:24.884492", 
                          "BTC/USDT", 
                          OrderBookType::bid};

    orders.push_back(order1);
    orders.push_back(order2);

   // std::cout << "order1 price: " << order1.price << std::endl;
   std::cout << "order1 price: " << orders[0].price << std::endl;

    return 0;
}
