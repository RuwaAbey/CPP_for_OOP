#pragma once
#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
    public:
    //we only need these 2 as public
        MerkelMain();
        /* Call this to start the sim*/
        void init();

    private:
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enteroffer() ;
        void enterBId();
        void printWallet();
        void gotonextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);

        std::vector<OrderBookEntry> orders;
    
};