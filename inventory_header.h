//*USER CLASS TO DEMONSTRATE THE CONCEPT OF POLYMORPHISM.*//
class Users{

    private:

        string user_name;
        string user_password;

    public:

        //*CONSTRUCTOR*//
        Users(string user_name="" , string user_passeword="");

        //*DESTRUCTOR OF USER CLASS*//
        virtual ~Users(){ }

        //*LOGIN FUNCTION.*//
        virtual bool LOGIN_VERIFY() = 0 ;

        //*MAIN MENU FUNCTION.*//
        virtual void MAIN_MENU() = 0 ;

        //*I-STREAM VIRTUAL FRIEND FUNCTION.*//
        friend istream& operator>>(istream& is, Users& obj);

};



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



//*MAKING THE {INVENTORY} CALSS [CONTAINS ALL THE STOCK INFORMATION].*//
class Inventory : public Stock{

    public:

        //*USER DEFINED DEFAULT CONSTRUCTOR*//
        Inventory(): Stock( ){}

        //*DESTRUCTOR*//
        ~Inventory();

        //*ADD ITEM TO THE STOCK.*//
        void Add_Item();

        //*SEARCH ITEM IN STOCK.*//
        void Search_Item();

        //*UPDATE ANY ITEM-[PRICE OR QUANTITY AND EVEN NAME]*//
        void Update_Item();

        //*DELETE ANY ITEM*//
        void Delete_Item();

        //*DISPLAY FUNCTION FOR INVENTROY-[ACCESSIBLE FOR ALL]*//
        void display_stock();

        //*ANALYSE THE QUANTITY OF EVERY PRODUCT, AND GENERATE NOTIFICATION IF THE ITEM WAS LOWER IN QUANTITY.*//
        void Auto_Notify();

        //*LOCAL MAIN FOR MANAGEMENT FUNCTIONS.*//
        void inventory_management();

        //*READ NOTIFICATIONS ON LOWER QUANTITY PRODUCTS.*//
        void Read_Notifications();

};




//*MAKING THE {ONLINE_ORDER} CALSS [CONTAINS ALL THE FUNCTIONS FOR ORDERING ONLINE ITEMS].*//
class Online_Order : public Stock{
    
    private:

        string customer_name;
        string current_time;
        string delivery_time;

    public:

        //*DEFAULT CONSTRUCTOR.*//
        Online_Order(string customer_name="", string delivery_time="");

        //*PLACE_ORDER FUNCTION.*//
        void ONLINE_ORDER();

        //*DISPLAY STOCK ONLINE.*//
        void display_stock_online();

        //*DISPLAY_ORDER FUNCTION.*//
        void help_display_order();

        //*DESTRUCTOR.*//
        ~Online_Order();

        //*I-STREAM FRIEND FUNCTION TO TAKE INPUT.*//
        friend istream& operator>>(istream& in, Online_Order& obj);
        
};




//*PHYSICAL ORDER CLASS [EMPLOYEE ONLY]*//
class Physical_Order : public Stock{
    
    public:

        //*CONSTRUCTOR*//
        Physical_Order();

        //*TAKE_ORDER FUNCTION.*//
        void PHYSICAL_ORDER();

        //*DISPLAY STOCK ONLINE.*//
        void display_stock_SHOP();

        //*DISPLAY_ORDER FUNCTION.*//
        void HELP_MAKE_BILL();

        //*DESTRUCTOR.*//
        ~Physical_Order();    

};




//////// [* CREDENTIALS MANAGEMENT *] ////////
class Credentials{

    private:

        string compare_1;
        string compare_2;

    public:

        //*DEFAULT_CONSTRUCTOR*//
        Credentials(string compare_1="", string compare_2=""){
            this->compare_1 = compare_1;
            this->compare_2 = compare_2;
        }

        //*DESTRUCTOR.*//
        ~Credentials(){
            //just roaming around...
        }
        

        int ADMIN_VERIFICATION_1();			// admin.cpp		{ access to admin passwords file}
        
        int ADMIN_VERIFICATION_2();			// admin.cpp		{ access to employee passwords file}
        
        int ADMIN_VERIFICATION_3();			// admin.cpp		{ access to user / staff passwords file}

        int ADMIN_VERIFICATION();           // get the authentication first...

        
        //*MAIN FUNCTION TO CHANGE CREDENTIALS.*//
        void Change_Credentials();

        void Change_Admin_Credentials();            // SUB-FUNCTION_01
        void Change_Employee_Credentials();         // SUB-FUNCTION_02
        void Change_User_Credentials();             // SUB-FUNCTION_03

        //*I-STREAM FRIEND FUNCTION TO TAKE INPUT.*//
        friend istream& operator >> (istream& in , Credentials& obj);

};




//*DEFINING THE {ADMIN-CLASS} [WHICH WILL BE ACTING AS THE PARENT FOR ALL THE OTHER CLASSES].*//
class Admin  : public Users , public Credentials , public Inventory{

    private:

        string name;
        string password;
        Track_Sales t1;
    
    public:

        // Constructor for the Admin class
        Admin(string name = "" , string password = "");

        //*DESTRUCTOR FOR THE ADMIN CLASS.*//
        ~Admin();

        //*VERIFICATION FUNCTION.*//
        bool LOGIN_VERIFY() override;

        //*UNALLOATION OF MEMORY.*//
        void Free_Memory(char** Product_Name , double* Price , double* Total_Price , int* Quantity , int row);
   
        //*local main for admin.*//
        void MAIN_MENU() override;

        //*[STOCK MANAGEMENT FUNCTION.]*//
        void stock_management();

        //*[SALES MANAGEMENT FUNCTION.]*//
        void sales_management();

        //*[CUSTOMER-EMPLOYEE MANAGEMENT FUNCTION.]*//
        void customer_emp_management();


        //*RESPONSE TO USER COMPLAINTS.*//
        void Response_to_Complaints();

        //*NOTIFICATIONS HANDLING.*//
        void Notification_Hub();

        //*SEE DETAILS OF ONLINE ORDERS-[FOR BOTH SIGNED AND UNSIGNED USESRS]*//
        void see_details_of_online_orders();

        //*RESPONSE TO ORDER.*//
        void Give_Response_To_Order();

        //*SALES HANDLING HUB*//
        void Sales_Handling_Hub();

        //*SEE THE BEST SELLING ITEM.*//
        void see_best_selling_item();

        //*SEE THE BEST SELLER EMLOYEE.*//
        void see_best_seller_employee();

        //*SEE INDIVIDUAL SALES.*//
        void see_individual_sales();

        //*I-STREAM FRIEND FUNCTION TO TAKE INPUT.*//
        friend istream& operator >> (istream& in , Admin& obj);

};




//*EMPLOYEE CLASS DECLERATION.*//
class Employee  : public Users , public Inventory , public Physical_Order {

    private:

        string name;
        string password;

    public:

        //*USER DEFINED DEFAULT CONSTRUCTOR.*//
        Employee(string name="", string password="" );

        //*VERIFICATION FUNCTION.*//
        bool LOGIN_VERIFY() override;

        //*I-STREAM FRIEND FUNTION TO TAKE INPUT FROM THE USER.*//
        friend istream& operator>>(istream& input, Employee& emp);

        //*MAIN MENU OF EMPLOYEE FUNCTION.*//
        void MAIN_MENU() override;

        //*SEE DETAILS OF ONLINE ORDERS-[FOR BOTH SIGNED AND UNSIGNED USESRS]*//
        void see_details_of_online_orders();

        //*RESPONSE TO ORDER.*//
        void Give_Response_To_Order();


};




//*CUSTOMER CLASS DECLERATION.*//
class Customer  : public Users , public Inventory , public Online_Order{

    private:

        string name;
        string password;

    public:

        //*PARAMETRIZED CONSTRUCTOR.*//
        Customer(string name="", string password="");

        //*DESTRUCTOR.*//
        ~Customer(){

        }

        //*VERIFICATION FUNCTION.*//
        bool LOGIN_VERIFY() override;

        //*local main for CUSTOMERS.*//
        void MAIN_MENU() override;

        //*mechanism for feedback.*//
        void give_review();

        //*check response given by the admin.*//
        void see_response();

        //*interesting notifications by ADMIN*//
        void CDS_NOTIFICATIONS();

        //*I-STREAM FRIEND FUNCTION TO TAKE INPUT FROM THE USER.*//
        friend istream& operator>>(istream& input, Customer& cust);

};


