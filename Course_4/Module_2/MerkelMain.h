#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
    //we only need these 2 as public
        MerkelMain();
        /* Call this to start the sim*/
        void init();

    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk() ;
        void enterBid();
        void printWallet();
        void gotonextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);

        std::string currentTime;
        
        OrderBook orderBook{"20200317.csv"};
    
};