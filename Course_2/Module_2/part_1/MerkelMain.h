

class MerkelMain
{
    public:
        MerkelMain();
        /* Call this to start the sim*/
        void init();
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