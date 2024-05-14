/////////////////////////////// *{ WHOLE ADMIN CLASS DEFINED HERE. }* ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"


//*FUNCTION TO ENCRYPT OR DECRYPT USING [XOR_CIPHER].*//
string Xor_Cipher(const string& text, const string& key){

    string result = text;
    
    for(int i=0 ; i<text.size() ; i++){
        result[i] = text[i] ^ key[i % key.size()];          //MASKING WITH THE ^ {size of key}.
    }

return result;
}


//CONSTRUCTOR FOR THE ADMIN CLASS...
Admin::Admin(string name , string password ){
    this->name = name;
    this->password = password;
}


//*DESTRUCTOR FOR THE ADMIN CLASS.*//
Admin::~Admin(){

}


//*I-STREAM FRIEND FUNCTION TO TAKE INPUT.*//
istream& operator >> (istream& in_put , Admin& obj){
    
    cout<<"\n ENTER THE ADMIN NAME : ";
    in_put>>obj.name;
    cout<<"\n ENTER THE ADMIN PASSWORD : ";
    in_put>>obj.password;

return in_put;
}



//*VERIFICATION FUNCTION.*//
bool Admin::LOGIN_VERIFY(){

    string compare_1;
    string compare_2;

    cout<<"\n ENTER THE ADMIN NAME : ";
    cin>>this->name;
    cout<<"\n ENTER THE ADMIN PASSWORD : ";
    cin>>this->password;

    string decrypted_name = Xor_Cipher(this->name , "key");
    string decrypted_password = Xor_Cipher(this->password , "key");

    ifstream pass("admin_pass.txt" , ios::in );     //OPEN FILE IN READING MODE...

    if(!pass){
        cout<<"\n FILE NOT FOUND...";
        return false;
    }

    while(!pass.eof() ){
        
        pass>>compare_1>>compare_2;
        if( compare_1 == decrypted_name &&  compare_2== decrypted_password ){
            pass.close();
            return true;
        }
    }
         
    pass.close();       // CLOSING THE FILE...

return false;           // GRANTING ACCESS...
}


//*UNALLOATION OF MEMORY.*//
void Admin::Free_Memory(char** Product_Name , double* Price , double* Total_Price , int* Quantity , int row){
    
    for(int i=0 ; i<row ; i++){
        delete [] Product_Name[i];			// DELETING THE MEMORY ALLOCATED IN HEAP.
    }
    delete [] Product_Name;
    delete [] Total_Price;
    delete [] Quantity;
    delete [] Price;
    
    Product_Name = NULL;					// UNDANGLING THE ARRAYS.
    Total_Price = NULL;
    Quantity = NULL;
    Price = NULL;
}


//*A KIND OF MAIN FOR ADMIN.*//
void Admin::MAIN_MENU()
{
    char choice;
    char exit;

    do{
		
		cout<< "\n\t\t-----------------------------------"; 
		cout<< "\n\t\t| >> WELCOME TO  ADMIN   MENU <<  |";
        cout<< "\n\t\t-----------------------------------\n\n";
        	
        	//loading_line();				// CALLING THE LOADING LINE FUNCTION.

        	cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
			cout<<"\t\t | "<<setw(55)<<left<<"<< ENTER THE CORRESPOMDING CHARACTER TO PROCEED >> "<<"|\n";
			cout<<"\t\t | "<<setfill('-')<<setw(55)<<""<<setfill(' ')<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"A. CAFE STOCK MANAGEMENT "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"B. GENERATE NOTIFICATION ( If item lower in quantity )"<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"C. ORDER ITEM [ IF LOWER IN QUANTITY ] "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"D. SEARCH, ADD, REMOVE & UPDATE ANY ITEM IN STOCK"<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"E. ADD OR REMOVE CREDENTIALS OF EMPLOYEE OR STAFF."<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"F. DISPLAY INTERESTING NOTIFICATIONS"<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"G. SEE ONLINE ORDERS "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"H. HANDLE COMPLAINTS "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"I. BEST-SELLER EMPLOYES"<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"J. TRACK THE SALES RECORD. [ AT ONE-STOP ] "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"K. PLAY GAMES [* AMUSEMENT *].  "<<"|\n";
			cout<<"\t\t | "<<setw(55)<<left<<"L. LOGOUT FROM THE SITE "<<"|\n";
			cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
  		
		cin>>choice;

        switch (choice)
        {
            case 'A':
            case 'a':						// [ 1 ]
            {		
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->stock_management();
            }		
            break;
            case 'B':
            case 'b':						// [ 2 ]
            {
           		clearScreen();			    // CALLING THE CLEAR SCREEN FUNCTION.
           		
                int read;
                cout<<"\n\t\t-------------------------------------------------------";
                cout<<"\n\t\t| >> THIS FUNCTION WAS TO GENERATE NOTIFICATIONS. <<  |";
                cout<<"\n\t\t|        >> WHEN PRODUCT LOW IN QUANTITY. <<          |";
                cout<<"\n\t\t| >> NOW IT IS AUTOMATED - PRESS [1] TO READ FILE <<  |";
                cout<<"\n\t\t-------------------------------------------------------\n\n";
                cin>>read;

                if(read == 1){
                    this->Read_Notifications();
                    //Sleep(5000);
                }
                else{
                    break;
                }

            }	
            break;
            case 'C':
            case 'c':						// [ 3 ]
            {    	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                cout<<"\n LINKING WITH INVENTORY MANAGEMENT-[UPDATE-ITEM] "<<endl;
                this->Update_Item();
            }   	
            break;
            case 'D':
            case 'd':						// [ 4 ]
            {    	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->inventory_management();
            }   	
            break;
            case 'E':
            case 'e':						// [ 5 ]
            {    
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->Change_Credentials();
            }   	
            break;
            case 'F':
            case 'f':						// [ 6 ]
            {    	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->Notification_Hub();
            }   	
            break;
            case 'G':
            case 'g':						// [ 7 ]
            {    	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->see_details_of_online_orders();
                this->Give_Response_To_Order();
            }   	
            break;
            case 'H':
            case 'h':						// [ 8 ]
            {   	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                this->Response_to_Complaints();
            }    	
            break;
            case 'I':
            case 'i':						// [ 9 ]
            {    	
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                this->Sales_Handling_Hub();
            }   	
            break;
            case 'J':						// [10]
            case 'j':
            {
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
            
               t1.track_sales();
            }
            break;
            case 'K':						// [11]
            case 'k':
            {
                clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
                
                Play_Games();
            }
            break;           
            case 'L':
            case 'l':						// [ 12 ]
            {    	  	
                cout<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
                cout<<"\t\t | "<<setw(48)<<left<<"          ** TERMINATING THE PROGRAM ** "<<"|\n";
                cout<<"\t\t | "<<setw(48)<<left<<"             && THANKS FOR COMING && "<<"|\n";
                cout<<"\t\t | "<<setw(48)<<left<<"                     GOOD_BYE"<<"|\n";
                cout<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl<<endl;
            
            return;
            }    	
            default:
            {
                cout<<"\n\t\t--------------------------------------\n";
                cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t\t----------------------------------------\n";
                break;
            }

       }

    }while(1);

return;
}


/////////////// [* STOCK HANDLING *] /////////////////////
void Admin::stock_management()
{
	char w;
	cout<<"\n *** [ WELCOME TO THE STOCK MANAGEMENT MENU ] *** \n\n";
	cout<<" WHAT OPERATION DO YOU WANT TO PERFORM ? \n";
	cout<<"\t ENTER >> \n\t [1]. TO SEE THE STOCK. \n\t [2]. TO HANDLE STOCK AT ONE PLACE. \n\t [0]. EXIT. \n\n";
	cin>>w;
	
	switch(w)
	{
		case '1':
		{	
			this->display_stock();        //*calling the display stock function.*//

        break;
        }
		case '2':
		{
            this->inventory_management();           //*calling the management function.*//4
        
        break;
        }
		case '0':
		{	
            cout<<"\n *** [ EXITING FROM THE STOCK MANAGEMENT MENU ] *** \n";

        break;
        }
		default:
		{	
            cout<<"\n\t\t--------------------------------------\n";
		  	cout<<"\t\t|   !!!!  ENTER A  VALID  CHOICE !!!!  |\n";
			cout<<"\t\t----------------------------------------\n";
			this->stock_management();
        }
	}
	
}


////////////// [ COMPLAIN FEEDBACK FUNCTION ] ///////////////////	
void Admin::Response_to_Complaints()
{
    cin.ignore();
	char c;
    cout<<"\n\t\t-------------------------------------------------------------------\n";
	cout<<"\t\t|  >>>            WELCOME TO THE REVIEW SECTION                 <<< |\n";
    cout<<"\t\t|  >>> YOU CAN SEE AND RESPOND THE CUSTOMERS REVIEWS FROM HERE. <<< |\n";
    cout<<"\t\t|  >>>      DO YOU WANT TO GIVE RESPOSE TO THE REVIEWS <?>      <<< |\n";
    cout<<"\t\t|  >>>            YES [Y/y]  or NO TO EXIT [N/n]                <<< |\n";
	cout<<"\t\t---------------------------------------------------------------------\n";

	cin>>c;
	  
	if(c=='y' || c=='Y')
	{
		const int s=200;
		char reaD[s];
	
		ifstream read("review.txt",ios::in);		// READING THE REVIEWS BY THE USERS.
		while(read.getline(reaD,s,'\n')){
			cout<<reaD<<endl;
		}
		read.close();					// CLOSING FILE TO PREVENT CORRUPTION.
		
		const int size = 200 , a = 10 ;
		char res[size];
		char name[a];
		cin.ignore();
		cout<<"\n ENTER THE USER NAME OR ID HERE >>> \n";
		cin.getline(name, a );
	
		cout<<"\n ENTER YOUR RESPONSE >>> \n";		// GIVING RESPONSE TO THE USERS REVIEWS.
		cin.getline(res, size);
	
		ofstream t("response.txt", ios::app);
		if( !t ){
        	cout<<"\n FILE NOT FOUND. \n";			
        }
        else{
        	t<<" RESPONDING TO  [ "<<name<<" ] :: "<<res<<endl;
   		    t.close();			// CLOSING FILE TO PREVENT CORRUPTION.
        }
	}
	else if(c=='n' || c=='N'){
        return;
	}
	
return;
}


///////// [* GENERATE NOTIFICATION ' NOTIFICATION HANDLING ' *] ////////////
void Admin::Notification_Hub()
{
	const int maxLines = 150;
	const int size = 300;
   	char chat[maxLines][size];
    int line = 0;
    int key;
	int choice;
	
	buttons();				// CALLING THE BUTTONS FUNCTION.

    while(1){
	
        cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
        cout<<"\t\t | "<<setw(30)<<left<<" [ WHAT DO YOU WANT TO DO ? ] "<<"|\n";
        cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
        cout<<"\t\t | "<<setw(30)<<left<<" 1. ADD NOTIFICATIONS. "<<"|\n";
        cout<<"\t\t | "<<setw(30)<<left<<" 2. VIEW NOTIFICATIONS. "<<"|\n";
        cout<<"\t\t | "<<setw(30)<<left<<" 3. REMOVE NOTIFICATIONS. "<<"|\n";
        cout<<"\t\t | "<<setw(30)<<left<<" 4. EXIT {RETURN BACK} "<<"|\n";
        cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
        
        cin>>choice;

        switch(choice)
        {
            case 1: 		/////// [ ADD ] ///////
            {
                cout<<"\nENTER THE NOTIFICATION >>>>\n";
                
                fstream o("notification.txt", ios::app);		// OPENING FILE IN APPEND MODE.
                
                cin.ignore();
                cin.getline(chat[line], size);
                
                o<< chat[line] <<endl;				// SAVING DATA IN FILE.
                o.close();						// CLOSING FILE TO PREVENT CORRUPTION.
            
            break; 
            }
            case 2: 		////////// [ VIEW ] //////////// 
            {
                ifstream d("notification.txt");		// IT IS READING AND DISPLAYING DATA AT THE SAME TIME.
                line=0;
                while(line < maxLines && d.getline(chat[line], size)){

                    cout<<" [ "<< line+1 <<" ] "<<chat[line] <<endl;
                    line++;
                }
            
            break; 
            }
            case 3:                     ////////// [ DELETE ] /////////
            {
                ifstream e("notification.txt");
                line = 0;

                while(e.getline(chat[line], size) && line < maxLines){	// READING AND DISPLAYING FILE AT-ONCE

                    cout<<" [ "<<line+1<<" ] "<<chat[line] <<endl;
                    line++;
                }

                cout<<"\nENTER THE NOTIFICATION *{INDEX}* YOU WANT TO REMOVE: >>>\n";
                cin>>key;

                if(key >= 1 && key <= line){

                    key -- ; 			// Adjust key to array index [0].
                    
                    ofstream w("notification.txt", ios::out);

                    for(int i = 0; i < line; i++){

                        if(i!= key){        	// SKIP THE SPECIFIC LINE WHILE WRITING BACK...
                            w<< chat[i]<<endl;
                        }
                    }

                    w.close();				// CLOSING FILE TO PREVENT CORRUPTION.
                }
                else{
                    cout<<"\nINVALID INDEX.\n";
                }
            
            break;
            }
            case 4:
            {
                cout<<"\n\t\t-----------------------------------------------";
                cout<<"\n\t\t|   !EXITING THE NOTIFICATION HANDLING MENU!  |";
                cout<<"\n\t\t-----------------------------------------------\n\n";  
            return;
            }
            default:
            {   
                cout<<"\n\t\t--------------------------------------\n";
                cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t\t----------------------------------------\n";   
                
                this->Notification_Hub();			// CALLING THE FUNCTION AGAIN.
            
            break;
            }
        }
    }

}


///////// *[ SEE ONLINE ORDERS ]* ////////////
void Admin::see_details_of_online_orders()
{
	cout<<"\n\t\t----------------------------------------------------------\n";
    cout<<"\t\t|      ****  [ WELCOME TO THE ONLINE ORDER MENU ] ****     |\n";
    cout<<"\t\t|   [ SEE THE DETAILS OF ORDERS PLACED BY THE CUSTOMERS ]  |\n";
    cout<<"\t\t------------------------------------------------------------\n";  
	
    int count=0;
    char ch;

    fstream read("online.txt" , ios::in);

    if(read.is_open())
    {
        while(!read.eof()){
            read.get(ch);
            if(ch == '\n'){
                count++;
            }
        }
    }
    else{
        cerr<<"\n FILE NOT FOUND. \n";
        return;
    }
    read.close();

    string display[count+3];

    int i=0;
    fstream read1("online.txt" , ios::in);
    while(!read1.eof()){
        getline(read1, display[i]);
        cout<<display[i]<<"\n";     //*DISPLAY DATA.*//
        i++;
    }
    read1.close();

    cout<<"\n\t\t-------------------------------------------------------\n";
    cout<<"\t\t|  **  [ SO THAT WERE ALL WITH THE ONLINE ORDERS. ] **  |\n";
    cout<<"\t\t|                <<<< GOOD BYE >>>>                     |\n";
    cout<<"\t\t---------------------------------------------------------\n";  
	
	
return;	
}


///////// *[ RESPONSE TO ORDER. ]* ////////////
void Admin::Give_Response_To_Order()
{
	const int s = 300 , n = 50 ;
	char* rev = new char[s];			// ALLOCATING MEMORY IN THE HEAP.
	string name;
	string user_name;

    cout<<"\n\t\t-----------------------------------------------------------\n";
    cout<<"\t\t| GIVE RESPONSE TO THE CUSTOMER [STUDENT-STAFF] FROM HERE.  |\n";
    cout<<"\t\t-------------------------------------------------------------\n"; 
	
	cin.ignore();
	
    name = this->name;
	
	cout<<" ENTER THE CUSTOMER NAME [ **** ]  >>> :: ";
	getline(cin , user_name);
	
	cout<<" ENTER YOUR RESPONSE >>  \n";
	cin.getline(rev , s );
	
	ofstream write("responseOrder.txt" , ios::app );	// WRITING IN APPEND MODE TO AVOID TRUNKING.
	
	if(!write){
		cout<<"\n ERROR OPENING FILE \n";
		cout<<" CHECK THE FILE NAME \n";
	}
	else{
		write<<"RESPONDED BY :: [ "<<name<<" ]   TO   { "<<user_name<<" }  "<<rev<<endl;
	}
	
	write.close();				// CLOSING FILE TO PREVENT CORRUPTION. 
	
	delete []rev;
    rev = NULL;
	
return;
}


//*MAIN SALES HANDLING FUNCTION.*//
void Admin::Sales_Handling_Hub(){

    int choice;
    cout<<"\t\t -"<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
	cout<<"\t\t | "<<setw(38)<<left<<" >>> [ SELECT TO OVERVIEW ] <<< "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
  	cout<<"\t\t | "<<setw(38)<<left<<" [1]. EMP. INDIVIDUAL SALES. "<<"|\n";
  	cout<<"\t\t | "<<setw(38)<<left<<" [2]. BEST SELLING ITEM. "<<"|\n";
  	cout<<"\t\t | "<<setw(38)<<left<<" [3]. BEST SELLER EMPLOYEE."<<"|\n";
    cout<<"\t\t | "<<setw(38)<<left<<" [4]. EXIT."<<"|\n";
  	cout<<"\t\t -"<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
    cin>>choice;

    switch(choice){
        case 1:
        {
            this->see_individual_sales();
        
        break;
        }
        case 2:
        {
            this->see_best_selling_item();
        
        break;
        }
        case 3:
        {
            this->see_best_seller_employee();
        
        break;
        }
        case 4:
        {
            cout<<"\n\t\t----------------------";
            cout<<"\n\t\t|  >>> [EXITED]  <<< |";
            cout<<"\n\t\t----------------------\n";
        
        return;
        }
        default:
        {
            cout<<"\n\t\t--------------------------------------\n";
            cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t\t----------------------------------------\n";
            this->Sales_Handling_Hub();
        }
    }

return;
}


///// [* TRACK INDIVIDUAL SALES *] ///////
void Admin::see_individual_sales()
{
	char yes;
	int ID;
	
    cout<<"\n\t\t----------------------------------------------------------\n";
    cout<<"\t\t|  >>> YOU CAN SEE THE BEST SELLER EMPLOYEE FROM HERE  <<< |\n";
    cout<<"\t\t------------------------------------------------------------\n";
	
	buttons();				// CALLING THE BUTTONS FUNCTION.
	
	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
	cout<<"\t\t | "<<setw(30)<<left<<" >>> [ SELECT THE ID ] <<< "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
  	cout<<"\t\t | "<<setw(30)<<left<<" [1].   EMPLOYEE_1 "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [2].   EMPLOYEE_2 "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [3].   EMPLOYEE_3 "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [4].   EMPLOYEE_4 "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [5].   EMPLOYEE_5 "<<"|\n";
  	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
    	 
    cout<<"\n\t ENTER THE EMPLOYEE-ID TO TRACK SALES RECORD  [ 1-5 ] >>> ::  \n";
    cin>>ID;
    	
    loading_line();				// CALLING THE LOADING LINE FUNCTION.

    string file_name;
    
    switch(ID){
        case 1:
        {
            file_name = "emp1.txt";
            break;
        }
        case 2:
        {
            file_name = "emp2.txt";
            break;
        }
        case 3:
        {
            file_name = "emp3.txt";
            break;
        }
        case 4:
        {
            file_name = "emp4.txt";
            break;
        }
        case 5:
        {
            file_name = "emp5.txt";
            break;
        }
        default:
        {
            cout<<"\n\t\t--------------------------------------\n";
            cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t\t----------------------------------------\n";
            see_individual_sales();
        }
    }
    	
     
    const int col=20;
    int row=0;
    char a;
    
    fstream line(file_name, ios::in);		// OPEN FILE IN READING MODE.
    
    if(!line){
        cerr<<"\n\t\t FILE NOT FOUND. CHECK THE FILE NAME.\n";
        return;
    }

    while(line.get(a)){
        if(a=='\n'){			// COUNTING THE NUMBER OF LINES FROM THE FILE.
            row++ ;
        }
    }
    
    line.clear();				// CLEARING THE BUFFER SPACE.
    line.seekg( 0 , ios::beg);		// MOVE CURSOR TO THE BEGINING OF FILE.
    line.close();				// CLOSING THE FILE TO PREVENT DATA CORRUPTION.
    
    
    ////////////////////////////////////////////////

    char** Product_Name = new char*[this->row];
    
    for(int i=0 ; i<this->row ; i++){
        Product_Name[i] = new char[col];		// ALLOCATING MEMORY IN THE HEAP.
    }
        
    int* Price = new int[this->row];
    double* Total_Price = new double[this->row];
    int* Quantity = new int[this->row];
    double sum = 0;
    int w=0;


    ifstream q( file_name , ios::in );		// READING FROM FILE.

    if(!q){
        cout<<" FILE NOT FOUND ! \n";
    }

    int R=0;
    cout<<"\n\t\t------------------------------------------------\n";
    cout<<"\t\t| TOTAL SALES MADE BY EMPLOYEE ["<<ID<<"] >>>>  ARE = |\n";
    cout<<"\t\t------------------------------------------------\n";
        
    cout<<"\t ORDER "<<"  PRODUCT_NAME   "<<" PRICE "<<"  QUANTITY "<<"  TOTAL_PRICE"<<endl<<endl;

    while( !q.eof() ){

        q>>Product_Name[R] >>Price[R] >>Quantity[R] >>Total_Price[R] ;
        
        if( !q.eof() ){     	// DISPLAYING CONTENT OF FILE.

        cout<<setw(5)<<"\t [ "<<R+1<<" ] "<<setw(5)<<" "<<setw(10)<<Product_Name[R]<<"  |  "<<setw(5)<<Price[R]<<"  |  "<<setw(5)<<Quantity[R]<<"  |  "
            <<setw(5)<<Total_Price[R]<<endl  ;
            R++;    
        }    
    }
        

    q.close();			// CLOSING FILE TO AVOID CORRUPTION.
       
    for( ; w<R ; w++ ){
        sum += Total_Price[w] ;			// CALCULATING THE TOTAL SALE SUM.
    }
        
    cout<<"\n\n\t\t -"<<setfill('-')<<setw(42)<<"-"<<setfill(' ')<<endl;
    cout<<"\t\t | "<<setw(25)<<left<<" NO. OF ORDERS   >>  "<<"   ::  "<<setw(8)<<w<<"|\n";
    cout<<"\t\t | "<<setw(25)<<left<<" TOTAL BILLINGS  >>  "<<"   ::  "<<setw(8)<<sum<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(42)<<"-"<<setfill(' ')<<endl;
    
    for(int i=0 ; i<row ; i++){
        delete [] Product_Name[i];			// DELETING THE MEMORY ALLOCATED IN HEAP.
    }
    delete [] Product_Name;
    delete [] Total_Price;
    delete [] Quantity;
    delete [] Price;
    
    Product_Name = NULL;					// UNDANGLING THE ARRAYS.
    Total_Price = NULL;
    Quantity = NULL;
    Price = NULL;
    	
    	
    cout<<"\n\t\t---------------------------------------------\n";
	cout<<"\t\t| DO YOU WANT TO SEE OTHER'S EMPLOYEE SALES ? |\n";
	cout<<"\t\t| PROCEES WITH  [Y/Y] AND RETURN WITH  [N/n]  |\n";
	cout<<"\t\t-----------------------------------------------\n";
	cin>>yes;
	if(yes=='y' || yes=='Y'){
		see_individual_sales();
	}
	else{
		return;
	}

return;	
}


///// [* SEE THE BEST SELLER EMPLOYEE *] ///////
void Admin::see_best_seller_employee() {
    const int col = 20;
    int row = 0, R = 0;
    char a;

    double Highest_Sale = 0;
    int Item_Count = 0;
    int Save_Id = 0;

    for(int i=0 ; i<5 ; i++){
        
        string file_name = "emp" + to_string(i + 1) + ".txt";

        fstream line(file_name, ios::in);
        if (!line) {
            cerr << "\n\t\t FILE NOT FOUND. CHECK THE FILE NAME.\n";
            return;
        }

        while (line.get(a)) {
            if (a == '\n') {
                row++;
            }
        }

        line.clear();
        line.seekg(0, ios::beg);
        line.close();

        int order_count = 0;
        double sale = 0;
        char** Product_Name = new char*[row];
        for (int i = 0; i < row; i++) {
            Product_Name[i] = new char[col];
        }

        double* Price = new double[row];
        double* Total_Price = new double[row];
        int* Quantity = new int[row];

        ifstream q(file_name, ios::in);
        if(!q){
            cout<<" FILE NOT FOUND ! \n";
        }

        while(q >> Product_Name[R] >> Price[R] >> Quantity[R] >> Total_Price[R]) {
            sale += Total_Price[R];
            order_count += Quantity[R];
            R++;
        }

        q.close();

        if (sale > Highest_Sale) {
            Highest_Sale = sale;
            Item_Count = order_count;
            Save_Id = i + 1;
        }

        
        for (int i = 0; i < row; i++) {
            delete[] Product_Name[i];
        }
        delete[] Product_Name;
        delete[] Price;
        delete[] Total_Price;
        delete[] Quantity;
    }

    cout << "\n\n\t\t -" << setfill('-') << setw(42) << "-" << setfill(' ') << endl;
    cout << "\t\t | " << setw(25) << left << " EMPLOYEE        >>  " << "   ::  " << setw(8) << Save_Id << "|\n";
    cout << "\t\t | " << setw(25) << left << " NO. OF ORDERS   >>  " << "   ::  " << setw(8) << Item_Count << "|\n";
    cout << "\t\t | " << setw(25) << left << " TOTAL BILLINGS  >>  " << "   ::  " << setw(8) << Highest_Sale << "|\n";
    cout << "\t\t -" << setfill('-') << setw(42) << "-" << setfill(' ') << endl;

    cout << "\n\t\t---------------------------------------------\n";
    cout << "\t\t| DO YOU WANT TO SEE OTHER'S EMPLOYEE SALES ? |\n";
    cout << "\t\t| PROCEED WITH  [Y/y] AND RETURN WITH  [N/n]  |\n";
    cout << "\t\t-----------------------------------------------\n";
    cin >> a;
    if (a == 'y' || a == 'Y') {
        this->see_individual_sales();
    } else {
        return;
    }
}


///// [* SEE THE BEST SELLING PRODUCT *] ///////
void Admin::see_best_selling_item(){

    const int col = 20;
    int row=0 , R=0;
    char a;

    fstream line("sales.txt", ios::in); // OPEN FILE IN READING MODE.
    if(!line){
        cerr<<"\n\t\t FILE NOT FOUND. CHECK THE FILE NAME.\n";
        return;
    }

    while(line.get(a)){
        
        if(a == '\n'){
            row++;
        }
    }

    line.clear();               //CLEAR THE BUFFER SPACE.
    line.seekg(0, ios::beg);    //MOVE CURSOR TO THE BEGINING OF FILE.
    line.close();               //CLOSE THE FILE TO PREVENT CORRUPTION.

    ////////////////////////////////////////////

    string* Product_Name = new string[row];
    double* Total_Price = new double[row];
    int* Quantity = new int[row];

    ifstream read("sales.txt", ios::in);
    if(!read){
        cout << " FILE NOT FOUND ! \n";
        return;
    }

    string product;
    double price, total, sale = 0;
    int quantity;

    while(read >> product >> price >> quantity >> total){

        sale += total;          //CALCULATE TOTAL SALES.

        bool found = false;
        for(int i=0 ; i<R ; i++){

            if(Product_Name[i] == product){         // finding the common product...

                Total_Price[i] += total;
                Quantity[i] += quantity;
                found = true;
                break;
            }
        }

        if(!found){         //FEEDING ARRAYS ONLY UNIQUE PRODUCTS...

            Product_Name[R] = product;
            Total_Price[R] = total;
            Quantity[R] = quantity;
            R++;
        }
    }

    read.close();

    int Highest_Quantity = 0;
    string Best_Product;

    for(int i=0 ; i<R ; i++){
        if(Quantity[i] > Highest_Quantity){
            Highest_Quantity = Quantity[i];
            Best_Product = Product_Name[i];
        }
    }

    cout << "\n\t\t -" << setfill('-') << setw(43) << "-" << setfill(' ') << endl;
    cout << "\t\t | " << setw(25) << left << " BEST SELLING PRODUCT >>  " << "   ::  " << setw(8) << Best_Product << "|\n";
    cout << "\t\t | " << setw(25) << left << " QUANTITY SOLD        >>  " << "   ::  " << setw(8) <<  Highest_Quantity << "|\n";
    cout << "\t\t -" << setfill('-') << setw(43) << "-" << setfill(' ') << endl;

    delete []Quantity;          //unallocating the memory.
    delete []Total_Price;
    delete []Product_Name;
    Quantity = NULL;
    Total_Price = NULL;
    Product_Name = NULL;

    int mans;
    cout<<"\n WOULD YOU LIKE TO INCREASE IT'S QUANTITY<?>";
    cout<<"\n [1].   YES  OR  [2].   NO. ";
    cin>>mans;
    if(mans==1){
        this->Update_Item();
    }
    else{
        return;
    }

return;
}

