//*CLASS-STOCK[CONTAINS THE STOCK IT-SELF]*//
class Stock{

    public:

        int row=0;
        double* Price;
        int* No_Items;
        double* Total_Price;
        char** iT_Name;
        char* header_txt;

        //*USER DEFINED DEFAULT CONSTRUCTOR*//
        Stock(int row=0 , double* Price=nullptr , int* No_Items=nullptr , double* Total_Price=nullptr , char** iT_Name=nullptr , char* header_txt=nullptr );

        //*UNALLOCATE MEMORY FUNCTION.*//
        void Unallocate_Memory();

        //*DESTRUCTOR*//
        ~Stock();

};
