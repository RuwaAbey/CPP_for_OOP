

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
        void enteroffer() ;
        void enterBId();
        void printWallet();
        void gotonextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
    
};