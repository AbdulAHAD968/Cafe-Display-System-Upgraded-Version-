//*CLASS TO TRACK THE SALES MADE BY CAFE.*//
class Track_Sales{

    private:

        int col = 20;
        int row=0;
        double* Price;
        int* No_Items;
        double* Total_Price;
        char** iT_Name;
        double sum_Price=0;

    public:

        //*PARAMETERLESS CONSTRUCTOR.*//
        Track_Sales();

        //*FUNCTION TO DE-ALLOCATE ALL THE MEMORY.*//
        void Free_Them();

        //*DESTRUCTOR.*//
        ~Track_Sales();

        //*MAIN TRACKING FUNCTION.*//
        void track_sales();

        //*FOR DAY SALES.*//
        void Day_Sales();

        //*FOR OVERALL SALES.*//
        void Track_Total_Sales();

        //*FOR CALCULATING THE TOTAL PRICE OF ITEMS IN STOCK.*//
        void Evaluate_Stock_Price();

};

