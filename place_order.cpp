/////////////////////////////// *{ ONLINE + PHYSICAL ORDER CLASS. }* ///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"


//*CONSTRUCTOR.*//
Online_Order::Online_Order(string customer_name, string delivery_time)
{
    this->customer_name = customer_name;

    time_t now = time(0);
    tm* currentTime = localtime(&now);

    // Format the current time
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", currentTime);
    this->current_time = buffer;

    this->delivery_time = delivery_time;
}


//*DESTRUCTOR.*//
Online_Order::~Online_Order(){
    this->Unallocate_Memory();
}


//*ISTREAM FRIEND FUNCTION TO TAKE INPUT FROM USER.*//
istream& operator>>(istream& in, Online_Order& obj)
{
    cout<<"\n\t\t|'''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> [ KINDLY ENTER SOME INFORMATION  ] <<  |";
    cout<<"\n\t\t|___________________________________________|\n";

    cout<<"\n ENTER YOUR NAME =  ";
    getline( in , obj.customer_name);

    cout<<"\n SET THE DELIVERY TIME =  ";
    getline( in , obj.delivery_time);

    return in;
}


//*DISPLAY STOCK ONLINE.*//
void Online_Order::display_stock_online(){

    this->row = count_stock_rows();

    if(this->row > 0){
        this->Price = new double[this->row];
        this->No_Items = new int[this->row];
        this->Total_Price = new double[this->row];
        
        this->iT_Name = new char*[this->row];
        for(int i = 0; i < this->row; i++){
            this->iT_Name[i] = new char[50];
        }
        this->header_txt = new char[100];
    }

    cout<<"\n\t\t|'''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> [ WELCOME TO THE DISPLAY STOCK PORTAL ] << |";
    cout<<"\n\t\t|_______________________________________________|\n\n";
	
	int p=0;
	const char* color = ANSI_COLOR_RESET;			// NON-CONSTANT POINTER TO CONSTANT DATA.

	fstream stock("stock.txt", ios::in);

    if(!stock)
    {
        cout<<"\n !!! FILE NOT FOUND !!!";
        cout<<"\n CHECK THE FILE NAME.";
    }
    else
    {
        // LOADING DATA IN ARRAYS FROM FILE.
        stock.getline(header_txt, 100, '\n');

        while(stock.getline(iT_Name[p], 50, ' ') , stock >> Price[p] >> No_Items[p] >>Total_Price[p] ){

            stock.ignore();
            p++;
        }
    }

    stock.close();					// CLOSING FILE TO AVOID CORRUPTION.
	
	arrange( this->row-1 , this->No_Items, this->iT_Name, this->Price, this->Total_Price);	    // CALLING THE SORT FUNCTION [BY-QUANTITY].
	
    cout<<"\n\t\t|''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<setw(6)<<color<<ANSI_COLOR_PURPLE<<"\n\t\t|     INDEX "<<header_txt<<ANSI_COLOR_RESET<<"  |";
    cout<<"\n\t\t|______________________________________________________________|";
    cout<<"\n\t\t|                                                              |\n";

	for(int c=0 ; c<p ; c++ )
	{
		if(this->No_Items[c] == 0)                //[ASSIGNING COLOR ON THE BASES OF THRESHOLD-{30} ]
		{
			color = ANSI_COLOR_RED;
		}
		else if( this->No_Items[c] > 0 && this->No_Items[c] <=30 )
		{
			color = ANSI_COLOR_YELLOW;
		}
		else if( this->No_Items[c] > 30 )
		{
			color = ANSI_COLOR_GREEN;
		}
		
       cout<<color<<"\t\t|     [ "<<setw(2) << c+1<<" ]   "<< setw(10) << this->iT_Name[c]<<"  |  "<< setw(5)<<this->Price[c]<<"  |  "
             <<setw(5)<<this->No_Items[c]<<"  |  "<< setw(8)<<this->Total_Price[c] <<" "<< setw(4)<<" "<<"|"<<endl;
	
	}

    cout<<"\t\t|                                                              |";
    cout<<"\n\t\t|______________________________________________________________|"<<ANSI_COLOR_RESET<<endl;

    
return;	
}



//*DISPLAY_ORDER FUNCTION.*//
void Online_Order::help_display_order(){

    int line=0;
    char ch;

    cout<<"\n\t\t|'''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> [ KINDLY ENTER SOME INFORMATION  ] <<  |";
    cout<<"\n\t\t|___________________________________________|\n";

    cin.ignore();
    cout<<"\n ENTER YOUR NAME =  ";
    getline( cin , this->customer_name);

    cout<<"\n SET THE DELIVERY TIME =  ";
    getline( cin , this->delivery_time);

    ifstream count_line("temp.txt" , ios::in);          //open file in read mode.

    if(!count_line){
        cerr<<"\n !!! FILE NOT FOUND !!!";
        cerr<<"\n CHECK THE FILE NAME.";
        return;
    }
    else{
        while(count_line.get(ch)){
            if(ch == '\n'){
                line++;
            }
        }
    }
    count_line.close();         //close file to prevent data corruption.

    char choice;    	
    cout<<"\n DO YOU WANT TO SEE ORDER DETAILS ::  ";	// ASKING IF HE/SHE WANTS TO SEE ORDER DETAILS.
    cout<<"\n PRESS [Y/y] to continue ...";
    cout<<"\n PRESS [N/n] to continue ...";
    cin>>choice;

    this->Price=new double[line];
    this->No_Items=new int[line];
    this->Total_Price=new double[line];
    
    this->iT_Name=new char*[line];
    for(int i=0 ; i<line ; i++){
        this->iT_Name[i]=new char[50];
    }
    
    double Order_Price = 0;
    int Order_Quantity = 0;


    ifstream q( "temp.txt" , ios::in );		// READING FROM FILE.
    if(!q){
        cout<<" FILE NOT FOUND ! \n";
    }

    int R=0;
                
    switch(choice)
    {
        case 'Y':			// DISPLAY THE ORDER DETAILS.
        case 'y':
        {  
            loading_line();				// CALLING THE LOADING LINE FUNCTION.
            
            cout<<"\n\t\t--------------------------------\n";
            cout<<"\t\t| TOTAL ORDER'S PLACED WERE    = |\n";
            cout<<"\t\t----------------------------------\n\n";
                
            cout<<"\t\t ORDER "<<"  PRODUCT_NAME   "<<" PRICE "<<"  QUANTITY "<<"  TOTAL_PRICE"<<endl<<endl;

            while( !q.eof() ){
                q>>iT_Name[R] >>Price[R] >>No_Items[R] >>Total_Price[R] ;	// DISPLAYING CONTENT OF FILE.
                if( !q.eof() ){
                    cout<<setw(4)<<"\t\t [ "<<R+1<<" ]  "<<setw(10)<<iT_Name[R]<<"  |  "<<setw(5)<<Price[R]<<"  |  "<<setw(5)<<No_Items[R]<<"  |  "<<setw(5)<<Total_Price[R]<<endl  ;
                    Order_Price += Total_Price[R];
                    Order_Quantity += No_Items[R];
                    ++R;    
                }
            }
            q.close();			// CLOSING FILE TO AVOID CORRUPTION.

            cout<<setw(25)<<"\n\t\t  ORDER DETAILS ARE MENTIONED HERE :: \n\n";
            cout<<"\t\t "<<setfill('-')<<setw(54)<<"-"<<endl;
            cout<<"\t\t |"<<setw(25)<<setfill(' ')<<"  ORDERED BY "<<"  ::  "<<setw(20)<< this->customer_name <<" |"<< endl;
            cout<<"\t\t |"<<setw(25)<<"  ORDERED AT TIME "<<"  ::  "<<setw(20)<< this->current_time <<" |"<<endl ;
            cout<<"\t\t |"<<setw(25)<<"  TO BE DELIVERED AT "<<"  ::  "<<setw(20)<< this->delivery_time <<" |"<<endl ;
            cout<<"\t\t |"<<setw(25)<<"  NUMBER OF PRODUCTS "<<"  ::  "<<setw(20)<< Order_Quantity <<" |"<<endl ;
            cout<<"\t\t |"<<setw(25)<<"  TOTAL PRICE PAYABLE  =/"<<"  ::  "<<setw(20)<< Order_Price <<" |"<<endl;
            cout<<"\t\t "<<setfill('-')<<setw(54)<<"-"<<endl;
            
        break;	
        }
        case 'N':
        case 'n':			// RE-DIRECT TO COUNTER.
        {
            cout<<"\n\t\t -----------------------------------------------------";
            cout<<"\n\t\t |  THANKS. YOU CAN RECIEVE ORDER FROM THE COUNTER.  |";
            cout<<"\n\t\t -----------------------------------------------------";

        break;	
        }
        default:
        {
            cout<<"\n\t--------------------------------------\n";
            cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t----------------------------------------\n";
    
        break;
        }
    }

    ofstream online("online.txt", ios::app);	    // WRITING IN APPEND MODE TO AVOID TRUNKING.

    if(!online){
        cout<<"\n !!! UNABLE TO WRITE ORDER DETAILS IN FILE !!! \n\n";
        return;
    }				                

    ////////////// *{ WRITING DATA IN FILE TO PREVENT DATA LOSS.}* /////////////////

    for(int i=0 ; i<R ; i++){
        online<<iT_Name[i]<<" "<<Price[i]<<" "<<No_Items[i]<<" "<<Total_Price[i]<<endl;    // WRITING DATA IN FILE.
    }
    online<<"ORDERED BY = " << this->customer_name<<endl;
    online<<"ORDERED AT TIME = " << current_time;
    online<<"          TO BE DELIVERED AT : " << delivery_time <<endl;
    online<<"NUMBER OF PRODUCTS : " << Order_Quantity;
    online<<"                           \tTOTAL PRICE PAYABLE  =/ : " << Order_Price <<endl;
    online<<setfill('-') << setw(50) << "-" << "\n";

    online.close();	

    ////////////////////////////////////

    ofstream write_sales("sales.txt" , ios::app);
    if(!write_sales){
        cout<<"\n !!! UNABLE TO WRITE ORDER DETAILS IN FILE !!! \n\n";
        return;
    }                                // WRITING DATA IN FILE TO PREVENT DATA LOSS.
    else{
        for(int i=0 ; i<R ; i++){
            write_sales<<iT_Name[i]<<" "<<Price[i]<<" "<<No_Items[i]<<" "<<Total_Price[i]<<endl;    // WRITING DATA IN FILE.
        }
    }
    write_sales.close();


return;
}



//// **[ ONLINE ORDERS ]** ///////
void Online_Order::ONLINE_ORDER()
{    

    const int g = 20;
    char search[g];
    int p = 0;
    bool found = false;			// CHECK IF THE PRODUCT EXISTS.
    int quantity;
    double Order_Price;
    int temp_count=0;

    while(1){

        this->display_stock_online();
        
        do{

            cout<<"\n\n ENTER THE PRODUCT NAME >>>   ::   ";
            cin>>search;
            p=0 ;				// SET THE INDEX BACK TO 0.
        
            while(p < row-1){

                if (strcmp(this->iT_Name[p], search) == 0){		// FINDING THE PRODUCT.
                break;
                }
                else{
                    p++;
                }
            }
            if(p == row-1){
                cout<<" ITEM NOT FOUND IN THE CART. \n";    	    
            }
            else{
                cout<<"\n ITEM FOUND IN THE CART AT [ "<<p+1<<" ] \n\n";
                break;
            }
        
        }while(!found);			// CHECKING THE FLAG.
            
        cout<<" ENTER THE NUMBER OF [ "<< search <<" ] YOU WANT TO ORDER :: ";
        cin>>quantity;
                
        if( (this->No_Items[p] < quantity) || (quantity<0) )
        {
            cout<<"\n INSUFFICENT QUANTITY IN THE STOCK. [ SORRY ] \n\n";
            cout<<"\n REDIRECTING TO THE MENU AGAIN. \n";
            ONLINE_ORDER();
        }
        else
        {
            this->No_Items[p] -= quantity;			// OREDRS DETAILS.
            this->Total_Price[p] -= this->Price[p] * quantity;
            Order_Price = this->Price[p] * quantity;

            cout<<"\n ORDER SUCCESSFUL \n\n";

            // OPEN FILE IN WRITING MODE.
                    
            ofstream d("stock.txt", ios::out);			// TRUNCKING THE PREVIOUS FILE DATA.

            if(!d){             // CHECK TO SEE THE FILE EXISTANCE.
                cerr<<"\n !!! UNABLE TO WRITE TO FILE !!!";
            }

            d<<header_txt<<endl;					// WRITING DATA BACK TO FILE.
            for(int k=0; k<row-1 ; k++)
            {
                d<<iT_Name[k] <<" "<< Price[k] <<" "<< No_Items[k] <<" "<<Total_Price[k] <<endl;
            }

            d.close();						// CLOSING FILE TO PREVENT CORRUPTION.


            ofstream save_data("temp.txt", ios::app);

            if(!save_data){
                cerr<<"\n !!! UNABLE TO WRITE TO FILE !!!";
            }
			else{
                save_data<< iT_Name[p] <<" "<< Price[p] <<" "<<quantity<<" "<<Price[p]*quantity<<endl;           	
                save_data.close();				// CLOSING THE FILE TO AVOID CORRUPTION.
            }

        }

        int skip;
        cout<<"\n DO YOU WANT TO ADD MORE ITEMS TO THE ORDER ::  ";
        cout<<"\n\t [ 1 ] :: YES. \n\t [ 2 ] :: NO ";
        cout<<"\n\t ENTER YOUR CHOICE ::  ";
        cin>>skip;

        if(skip == 2){
            break;
        }
        else{
            continue;
        }

    }

    this->Unallocate_Memory();

    this->help_display_order();         //THIS WILL GENERATE A BILL AND STORE DATA IN THE FILE.

    fstream clear_temp("temp.txt" , ios::out | ios::trunc);            //TRUNCATED THE TEMPORARY FILE...
    if(!clear_temp){
        cerr<<"\n !!! UNABLE TO CLEAR THE TEMPORARY FILE !!!";
        return;
    }
    clear_temp.close();

return;
}



// *CONSTRUCTOR*//
Physical_Order::Physical_Order()
{
    this->row = 0;
    this->header_txt = nullptr;
    this->iT_Name = NULL;
    this->Price = NULL;
    this->No_Items = NULL;
    this->Total_Price = NULL;
}


// *DESTRUCTOR*//
Physical_Order::~Physical_Order()
{
    this->Unallocate_Memory();
}


// *DISPLAY_STOCK FUNCTION.*//
void Physical_Order::display_stock_SHOP(){

    this->row = count_stock_rows();

    if(this->row > 0){
        this->Price = new double[this->row];
        this->No_Items = new int[this->row];
        this->Total_Price = new double[this->row];
        
        this->iT_Name = new char*[this->row];
        for(int i = 0; i < this->row; i++){
            this->iT_Name[i] = new char[50];
        }
        this->header_txt = new char[100];
    }

    cout<<"\n\t\t|'''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> [ WELCOME TO THE DISPLAY STOCK PORTAL ] << |";
    cout<<"\n\t\t|_______________________________________________|\n\n";
	
	int p=0;
	const char* color = ANSI_COLOR_RESET;			// NON-CONSTANT POINTER TO CONSTANT DATA.

	fstream stock("stock.txt", ios::in);

    if(!stock)
    {
        cout<<"\n !!! FILE NOT FOUND !!!";
        cout<<"\n CHECK THE FILE NAME.";
    }
    else
    {
        // LOADING DATA IN ARRAYS FROM FILE.
        stock.getline(header_txt, 100, '\n');

        while(stock.getline(iT_Name[p], 50, ' ') , stock >> Price[p] >> No_Items[p] >>Total_Price[p] ){

            stock.ignore();
            p++;
        }
    }

    stock.close();					// CLOSING FILE TO AVOID CORRUPTION.
	
	arrange( this->row-1 , this->No_Items, this->iT_Name, this->Price, this->Total_Price);	    // CALLING THE SORT FUNCTION [BY-QUANTITY].
	
    cout<<"\n\t\t|''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<setw(6)<<color<<ANSI_COLOR_PURPLE<<"\n\t\t|     INDEX "<<header_txt<<ANSI_COLOR_RESET<<"  |";
    cout<<"\n\t\t|______________________________________________________________|";
    cout<<"\n\t\t|                                                              |\n";

	for(int c=0 ; c<p ; c++ )
	{
		if(this->No_Items[c] == 0)                //[ASSIGNING COLOR ON THE BASES OF THRESHOLD-{30} ]
		{
			color = ANSI_COLOR_RED;
		}
		else if( this->No_Items[c] > 0 && this->No_Items[c] <=30 )
		{
			color = ANSI_COLOR_YELLOW;
		}
		else if( this->No_Items[c] > 30 )
		{
			color = ANSI_COLOR_GREEN;
		}
		
       cout<<color<<"\t\t|     [ "<<setw(2) << c+1<<" ]   "<< setw(10) << this->iT_Name[c]<<"  |  "<< setw(5)<<this->Price[c]<<"  |  "
             <<setw(5)<<this->No_Items[c]<<"  |  "<< setw(8)<<this->Total_Price[c] <<" "<< setw(4)<<" "<<"|"<<endl;
	
	}

    cout<<"\t\t|                                                              |";
    cout<<"\n\t\t|______________________________________________________________|"<<ANSI_COLOR_RESET<<endl;

    
return;	
}


// *DISPLAY_ORDER FUNCTION.*//
void Physical_Order ::  HELP_MAKE_BILL(){

    int line=0;
    char ch;
    string customer_name;

    cout<<"\n\t\t|'''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> [ KINDLY ENTER SOME INFORMATION  ] <<  |";
    cout<<"\n\t\t|___________________________________________|\n";

    cin.ignore();
    cout<<"\n TELL ME YOUR NAME RESPECTED CUSTOMER  :)  =  ";
    getline( cin , customer_name);    

    ifstream count_line("temp.txt" , ios::in);          //open file in read mode.

    if(!count_line){
        cerr<<"\n !!! FILE NOT FOUND !!!";
        cerr<<"\n CHECK THE FILE NAME.";
        return;
    }
    else{
        while(count_line.get(ch)){
            if(ch == '\n'){
                line++;
            }
        }
    }
    count_line.close();         //close file to prevent data corruption.

    char choice;    	
    cout<<"\n TO RECIEVE THE ORDER RECIEPT FOLLOW THE INSTRUCTIONS ::  ";	// ASKING IF HE/SHE WANTS TO SEE ORDER DETAILS.
    cout<<"\n PRESS [Y/y] to RECIEVE ...";
    cout<<"\n PRESS [N/n] to PASS IT ...";
    cin>>choice;

    this->Price=new double[line];
    this->No_Items=new int[line];
    this->Total_Price=new double[line];
    
    this->iT_Name=new char*[line];
    for(int i=0 ; i<line ; i++){
        this->iT_Name[i]=new char[50];
    }
    
    double Order_Price = 0;
    int Order_Quantity = 0;


    ifstream q( "temp.txt" , ios::in );		// READING FROM FILE.
    if(!q){
        cout<<" FILE NOT FOUND ! \n";
    }

    int R=0;
                
    switch(choice)
    {
        case 'Y':			// DISPLAY THE ORDER DETAILS.
        case 'y':
        {  
            loading_line();				// CALLING THE LOADING LINE FUNCTION.
            
            cout<<"\n\t\t--------------------------------\n";
            cout<<"\t\t| TOTAL ORDER'S PLACED WERE    = |\n";
            cout<<"\t\t----------------------------------\n\n";
                
            cout<<"\t\t ORDER "<<"  PRODUCT_NAME   "<<" PRICE "<<"  QUANTITY "<<"  TOTAL_PRICE"<<endl<<endl;

            while( !q.eof() ){
                q>>iT_Name[R] >>Price[R] >>No_Items[R] >>Total_Price[R] ;	// DISPLAYING CONTENT OF FILE.
                if( !q.eof() ){
                    cout<<setw(4)<<"\t\t [ "<<R+1<<" ]  "<<setw(10)<<iT_Name[R]<<"  |  "<<setw(5)<<Price[R]<<"  |  "<<setw(5)<<No_Items[R]<<"  |  "<<setw(5)<<Total_Price[R]<<endl  ;
                    Order_Price += Total_Price[R];
                    Order_Quantity += No_Items[R];
                    ++R;    
                }
            }
            q.close();			// CLOSING FILE TO AVOID CORRUPTION.

            cout<<setw(25)<<"\n\t\t  ORDER DETAILS ARE MENTIONED HERE :: \n\n";
            cout<<"\t\t "<<setfill('-')<<setw(54)<<"-"<<endl;
            cout<<"\t\t |"<<setw(25)<<setfill(' ')<<"  ORDERED BY "<<"  ::  "<<setw(20)<< customer_name <<" |"<< endl;
            cout<<"\t\t |"<<setw(25)<<"  NUMBER OF PRODUCTS "<<"  ::  "<<setw(20)<< Order_Quantity <<" |"<<endl ;
            cout<<"\t\t |"<<setw(25)<<"  TOTAL PRICE PAYABLE  =/"<<"  ::  "<<setw(20)<< Order_Price <<" |"<<endl;
            cout<<"\t\t "<<setfill('-')<<setw(54)<<"-"<<endl;
            
        break;	
        }
        case 'N':
        case 'n':			// RE-DIRECT TO COUNTER.
        {
            cout<<"\n\t\t -----------------------------------------------------";
            cout<<"\n\t\t |  THANKS. YOU CAN RECIEVE ORDER FROM THE COUNTER.  |";
            cout<<"\n\t\t -----------------------------------------------------";

        break;	
        }
        default:
        {
            cout<<"\n\t--------------------------------------\n";
            cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t----------------------------------------\n";
    
        break;
        }
    }

    ////////////// *{ WRITING DATA IN FILE TO PREVENT DATA LOSS.}* /////////////////

    int DAY,ID;
    cout<<"\n\n";
    cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
    cout<<"\t\t | "<<setw(30)<<left<<" >>> [ SELECT THE DAY ] <<< "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [1].   MONDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [2].   TUESDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [3].   WEDNESDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [4].   THURSDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [5].   FRIDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [6].   SATURDAY. "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [7].   SUNDAY.  "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
    cout<<"\n\t\t ENTER THE CURRENT DAY  [ 1-7 ]  >>  ::  \n";

    cout<<"\n  [PLEASE] SELECT THE CURRENT DAY. ";
    cin>>DAY;
    while(DAY<0 || DAY>7){
        cout<<"\n  [PLEASE] SELECT THE CURRENT DAY. ";
        cin>>DAY;
    }

    string file_name;
    
    switch(DAY){
        case 1:
        {
            file_name="monday.txt";
            break;
        }
        case 2:
        {
            file_name="tuesday.txt";
            break;
        }
        case 3:
        {
            file_name="wednesday.txt";
            break;
        }
        case 4:
        {
            file_name="thursday.txt";
            break;
        }
        case 5:
        {
            file_name="friday.txt";
            break;
        }
        case 6:
        {
            file_name="saturday.txt";
            break;
        }
        case 7:
        {
            file_name="sunday.txt";
            break;
        }
        default:
        {
            cout<<"\n\t--------------------------------------\n";
            cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t----------------------------------------\n";
            break;
        }
    }

    ofstream day_data( file_name, ios::app);	    // WRITING IN APPEND MODE TO AVOID TRUNKING.

    if(!day_data){
        cout<<"\n !!! UNABLE TO WRITE ORDER DETAILS IN FILE !!! \n\n";
        return;
    }

    for(int i=0 ; i<R ; i++){
        day_data<<iT_Name[i]<<" "<<Price[i]<<" "<<No_Items[i]<<" "<<Total_Price[i]<<endl;    // WRITING DATA IN FILE.
    }

    day_data.close();

    
    string file_name_E;             //RESET THE FILE NAME.

    cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
    cout<<"\t\t | "<<setw(30)<<left<<" >>> [ SELECT THE ID ] <<< "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [1].   EMPLOYEE_1 "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [2].   EMPLOYEE_2 "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [3].   EMPLOYEE_3 "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [4].   EMPLOYEE_4 "<<"|\n";
    cout<<"\t\t | "<<setw(30)<<left<<" [5].   EMPLOYEE_5 "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;	  
    cout<<"\n\t\t ENTER YOUR ID-ALLOCATED BY THE CDS  [ 1-5 ] >>> ::  \n";

    cout<<"\n ENTER YOUR ID [DEAR EMPLOYEE] :: ";
    cin>>ID;
    while(ID<0 || ID>5){
        cout<<"\n ENTER YOUR ID [DEAR EMPLOYEE] :: ";
        cin>>ID;
    }

    switch(ID){
        case 1:
        {
            file_name_E ="emp1.txt";
            break;
        }
        case 2:
        {
            file_name_E ="emp2.txt";
            break;
        }
        case 3:
        {
            file_name_E ="emp3.txt";
            break;
        }
        case 4:
        {
            file_name_E ="emp4.txt";
            break;
        }
        case 5:
        {
            file_name_E ="emp5.txt";
            break;
        }
        default:
        {
            cout<<"\n\t--------------------------------------\n";
            cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t----------------------------------------\n";
            break;
        }
    }

    ofstream emp_data( file_name_E , ios::app);	    // WRITING IN APPEND MODE TO AVOID TRUNKING.

    if(!emp_data){
        cout<<"\n !!! UNABLE TO WRITE ORDER DETAILS IN FILE !!! \n\n";
        return;
    }

    for(int i=0 ; i<R ; i++){
        emp_data<<iT_Name[i]<<" "<<Price[i]<<" "<<No_Items[i]<<" "<<Total_Price[i]<<endl;    // WRITING DATA IN FILE.
    }

    emp_data.close();	

    ////////////////////////////////////

    ofstream write_sales("sales.txt" , ios::app);
    if(!write_sales){
        cout<<"\n !!! UNABLE TO WRITE ORDER DETAILS IN FILE !!! \n\n";
        return;
    }                                // WRITING DATA IN FILE TO PREVENT DATA LOSS.
    else{
        for(int i=0 ; i<R ; i++){
            write_sales<<iT_Name[i]<<" "<<Price[i]<<" "<<No_Items[i]<<" "<<Total_Price[i]<<endl;    // WRITING DATA IN FILE.
        }
    }
    write_sales.close();


return;
}



//*FUNCTION TO TAKE ORDER FROM EMPLOYEE.*//
void Physical_Order :: PHYSICAL_ORDER(){

    
    const int g = 20;
    char search[g];
    int p = 0;
    bool found = false;			// CHECK IF THE PRODUCT EXISTS.
    int quantity;
    double Order_Price;
    int temp_count=0;

    while(1){

        this->display_stock_SHOP();
        
        do{

            cout<<"\n\n ENTER THE PRODUCT NAME >>>   ::   ";
            cin>>search;
            p=0 ;				// SET THE INDEX BACK TO 0.
        
            while(p < row-1){

                if (strcmp(this->iT_Name[p], search) == 0){		// FINDING THE PRODUCT.
                break;
                }
                else{
                    p++;
                }
            }
            if(p == row-1){
                cout<<" ITEM NOT FOUND IN THE CART. \n";    	    
            }
            else{
                cout<<"\n ITEM FOUND IN THE CART AT [ "<<p+1<<" ] \n\n";
                break;
            }
        
        }while(!found);			// CHECKING THE FLAG.
            
        cout<<" ENTER THE NUMBER OF [ "<< search <<" ] YOU WANT TO ORDER :: ";
        cin>>quantity;
                
        if( (this->No_Items[p] < quantity) || (quantity<0) )
        {
            cout<<"\n INSUFFICENT QUANTITY IN THE STOCK. [ SORRY ] \n\n";
            cout<<"\n REDIRECTING TO THE MENU AGAIN. \n";
            this->PHYSICAL_ORDER();
        }
        else
        {
            this->No_Items[p] -= quantity;			// OREDRS DETAILS.
            this->Total_Price[p] -= this->Price[p] * quantity;
            Order_Price = this->Price[p] * quantity;

            cout<<"\n ORDER SUCCESSFUL \n\n";

            // OPEN FILE IN WRITING MODE.
                    
            ofstream d("stock.txt", ios::out);			// TRUNCKING THE PREVIOUS FILE DATA.

            if(!d){             // CHECK TO SEE THE FILE EXISTANCE.
                cerr<<"\n !!! UNABLE TO WRITE TO FILE !!!";
            }

            d<<header_txt<<endl;					// WRITING DATA BACK TO FILE.
            for(int k=0; k<row-1 ; k++)
            {
                d<<iT_Name[k] <<" "<< Price[k] <<" "<< No_Items[k] <<" "<<Total_Price[k] <<endl;
            }

            d.close();						// CLOSING FILE TO PREVENT CORRUPTION.


            ofstream save_data("temp.txt", ios::app);

            if(!save_data){
                cerr<<"\n !!! UNABLE TO WRITE TO FILE !!!";
            }
			else{
                save_data<< iT_Name[p] <<" "<< Price[p] <<" "<<quantity<<" "<<Price[p]*quantity<<endl;           	
                save_data.close();				// CLOSING THE FILE TO AVOID CORRUPTION.
            }

        }

        int skip;
        cout<<"\n DO YOU WANT TO ADD MORE ITEMS TO THE ORDER ::  ";
        cout<<"\n\t [ 1 ] :: YES. \n\t [ 2 ] :: NO ";
        cout<<"\n\t ENTER YOUR CHOICE ::  ";
        cin>>skip;

        if(skip == 2){
            break;
        }
        else{
            continue;
        }

    }

    this->Unallocate_Memory();

    this->HELP_MAKE_BILL();         //THIS WILL GENERATE A BILL AND STORE DATA IN THE FILE.

    fstream clear_temp("temp.txt" , ios::out | ios::trunc);            //TRUNCATED THE TEMPORARY FILE...
    if(!clear_temp){
        cerr<<"\n !!! UNABLE TO CLEAR THE TEMPORARY FILE !!!";
        return;
    }
    clear_temp.close();

return;
}




// int main(){
    
//     Physical_Order order;
//     order.PHYSICAL_ORDER();
//     return 0;
// }

