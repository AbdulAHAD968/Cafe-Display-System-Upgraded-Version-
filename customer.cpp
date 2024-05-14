//////// *{ WHOLE INVENTORY ALONG WITH SOME GLOBAL FUNCTIONS CLASS DEFINED HERE. }* /////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "header.h"


//*COUNT NUMBER OF LINES IN STOCK FILE.*//
int count_stock_rows(){

    int row = 0;
    char a;
    
    fstream line("stock.txt" , ios::in);		// OPEN FILE IN READING MODE.
    
    if(!line){
    	cerr<<"\n\t\t FILE NOT FOUND . CHECK THE FILE NAME.\n";
    	return 0;
    }
    while(line.get(a)){
    	if(a=='\n'){
    		row++ ;
    	}
    }
    
    line.clear();
    line.seekg(0 , ios::beg);		// MOVE THE CURSOR TO THE BEGINING OF THE FILE.
    
    line.close();		// CLOSING THE FILE TO PREVENT DATA CORRUPTION.

return row;
}


//*USER DEFINED DEFAULT CONSTRUCTOR*//
Stock::Stock(int row, double* Price, int* No_Items, double* Total_Price, char** iT_Name, char* header_txt)
{       
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
}


//*UNALLOCATE MEMORY FUNCTION.*//
void Stock::Unallocate_Memory(){

    delete[] Price;             // FREE THE ALLOCATED MEMORY.
    delete[] No_Items;
    delete[] Total_Price;
    delete[] header_txt;

    for(int i=0;i<row;i++){
        delete[] iT_Name[i];
    }
    delete[] iT_Name;

    iT_Name = NULL;             // UNDANGLE THE ARRAYS.
    Price = NULL;
    No_Items = NULL;
    Total_Price = NULL;
    header_txt = NULL;
}


//*DESTRUCTOR*//
Stock::~Stock(){
    this->Unallocate_Memory();
}

/////////////////////////////////////////////////////////////////!SECTION


//*DESTRUCTOR*//
Inventory :: ~Inventory(){

}


////// [ DISPLAY THE MENU ] ///////
void Inventory::display_stock()
{

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
	
    this->Auto_Notify();          //GENERATE NOTIFICATION IF ANY ITEM WAS LOWER IN QUANTITY...

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


////// *[ ADD NEW-ITEM TO THE STOCK ]* /////// 
void Inventory::Add_Item()
{

    cout<<"\n\t\t|''''''''''''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> YOU CAN ADD ANY PRODUCT [* TRENDING *] FROM HERE << |";
    cout<<"\n\t\t|________________________________________________________|\n\n";

    
    this->display_stock();
    
    char  New_Name[30];
    double New_Price;
    int New_Quantity;

    cout<<"\n ENTER THE DETAILS OF THE PRODUCT YOU WANT TO ADD :: \n";
    cout<<"\n\t <<<< [ ADDING NEW ITEM TO THE STOCK ] >>>> \n\n";
    cout<<"\n ENTER THE NAME OF THE ITEM : ";
    cin>> New_Name;

    bool flag = true;

    while(flag){
        flag = false;
        for(int i=0 ; i<this->row-1 ; i++){
            if(strcmp( New_Name, this->iT_Name[i]) == 0){
                cerr<<"\n ITEM ALREADY EXISTS IN THE STOCK. ";
                flag = true;
                cout<<"\n ENTER THE NAME OF THE ITEM [AGAIN]: ";
                cin>> New_Name;
                break;
            }
        }
    }

    cout<<" PRICE :: ";
    cin>>New_Price;
    while(New_Price<0){
        cout<<"\n ENTER THE PRICE [POSITIVE VALUE] :: ";
        cin>>New_Price;
    }
    
    cout<<" QUANTITY :: ";
    cin>>New_Quantity;
    while(New_Quantity<0){
        cout<<"\n ENTER THE QUANTITY [POSITIVE VALUE] :: ";
        cin>>New_Quantity;
    }
    
    cin.ignore();
    
    fstream write("stock.txt", ios::app);		// WRITING FILE IN APPEND MODE TO PREVENT TRUNKING.

    // [ENTERING THE PRODUCT IN THE STOCK].			
    write << New_Name<<" "<<New_Price<<" "<<New_Quantity<<" "<<New_Price * New_Quantity<<endl;

    write.close();					// CLOSING FILE TO PREVENT CORRUPTION.

    cout<<"\n ITEM ADDED SUCCESSFULLY IN THE PREVIOUS STOCK. \n";
    
    
return;    
}


////// [ UPDATE ANY ITEM, NAME AND PRICE ] //////// 
void Inventory::Update_Item()
{

    cout<<"\n\t\t ---------------------------------------------------------------------";
    cout<<"\n\t\t| >> YOU CAN UPDATE THE  PRICE, QUANTITY & TOTAL PRICE FROM HERE. << |";
    cout<<"\n\t\t|____________________________________________________________________|\n\n";
    
    this->display_stock();

    int index;
    cout<<"\n\n\t ENTER THE INDEX [ 0-9 ] OF THE PRODUCT TO UPDATE >> :: ";
    cin>>index;

    index= index - 1 ;				// [ SETTING IT TO THE ARRAY INDEXING FROM 0.th ]

    if(index >= 0 && index < row )
    {
        
        double New_Price;
        int New_Quantity;

        cout<<"\n ENTER THE DETAILS OF THE PRODUCT YOU WANT TO ADD :: \n";
        cout<<"\n\t <<<< [ UPDATING PREVIOUS ITEM IN THE STOCK ] >>>> \n\n";
    
        char new_name[30] = {};
        strcpy(new_name,iT_Name[index]);

        cout<<"\nTHE NAME OF THE PRODUCT IS :: { "<<new_name<<" } \n";

        cout<<" PRICE :: ";
        cin>>New_Price;
        while(New_Price<0){
            cout<<"\n ENTER THE PRICE [POSITIVE VALUE] :: ";
            cin>>New_Price;
        }
        
        cout<<" QUANTITY :: ";
        cin>>New_Quantity;
        while(New_Quantity<0){
            cout<<"\n ENTER THE QUANTITY [POSITIVE VALUE] :: ";
            cin>>New_Quantity;
        }

        double newTotalPrice = New_Price * New_Quantity ;
        // CALLING THE UPDATE-PRODUCT FUNCTION.
								
        update_Product(iT_Name, Price, No_Items, Total_Price, index, new_name , New_Price, New_Quantity, newTotalPrice);

        fstream dump("stock.txt", ios::out);			// TRUNKING THE PREVIOUS DATA IN FILE.

        dump<<header_txt<<endl;				// WRITING THE HEADER TXT.

        for( int a=0 ; a<row-1 ; a++ )			// WRITING UPDATED DATA BACK TO FILE.
        {
            dump<<iT_Name[a] <<" "<< Price[a] <<" "<<No_Items[a] <<" "<<Total_Price[a] <<endl;
        }

        dump.close();					// CLOSING FILE TO PREVENT CORRUPTION.
        
        cout<<"\n PRODUCT UPDATED SUCCESSFULLY.\n\n";
        
    }
    else
    {
        cerr<<"\n\t\t !!! INVALID INDEX !!! \n\n";
        cout<<"\n\t\t RETURNING TO THE UPDATE MENU FUNCTION AGAIN.\n";
        Update_Item();
    }

return;
}


////// [ DELETE ANY ITEM ] //////
void Inventory::Delete_Item()
{

    cout<<"\n\t\t|''''''''''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t\t| >> YOU CAN REMOVE ANY ITEM IN THE STOCK FROM HERE << |";
    cout<<"\n\t\t|______________________________________________________|\n\n";

    char del;				// DELETE ITEM ON DEMAND.

    arrange(row-1 , No_Items, iT_Name, Price, Total_Price);		// CALLING THE SORT FUNCTION [BY-QUANTITY].
    display_stock();

    char search[30];				// GETTING THE KEY.
    cout<<"\n ENTER THE ITEM FROM THE MENU YOU WANT TO REMOVE >>> ";
    cin>>search;
    int p=0;

    while(p < row-1)
    {
        if(strcmp(iT_Name[p], search) == 0){			// FINDING ITEM IN STOCK.
            break;
        }
        else{
        	p++;
        }
    }

    if(p == row-1){
        cout<<"\n ITEM NOT FOUND IN THE CART. \n";        
    }
    else{

        cout<<"\n ITEM FOUND IN THE CART AT [ "<< p+1 <<" ] \n\n";		// INCRIMENT IN INDEX(+1).
        cout<<" DO YOU WANT TO REMOVE THIS ITEM ? \n";
        cout<<" TO DELETE [Y/y] OTHERWISE [N/n] \n";
        cin>>del;
        
        switch(del){

        	case 'Y':
        	case 'y':
        	{
        		fstream task("stock.txt", ios::out);	// TRUNCATING PREVIOUS DATA IN THE FILE.

       			 task<< header_txt <<endl;

       			 for(int a=0 ; a <row-1 ; a++)		// WRITING UP-DATED DATA BACK TO THE FILE.
       			 {
         		    if(a == p)
            		    continue;
            		task<<iT_Name[a] <<" "<<Price[a] <<" "<<No_Items[a] <<" "<<Total_Price[a] <<endl;
        		 }
        		
			    task.close();				// CLOSING FILE TO PREVENT CORRUPTION.
 
        	break;	
        	}
        	case 'N':
        	case 'n':
        	{
        		cout<<"\n WELL ! YOU CAN DO THIS LATER TOO. \n\n";
    
        	break;	
        	}
        	default:
        	{
        		cout<<"\n\t\t--------------------------------------\n";
                cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t\t----------------------------------------\n";
            }
        	break;
	
        }
    }
    
    
return;
}


///// [ * SEARCH ITEMS IN CDS * ] ////////
void Inventory::Search_Item()
{   
    cout<<"\n\t\t ----------------------------------";
    cout<<"\n\t\t| >> SEARCH ITEMS IN THE STOCK. << |";
    cout<<"\n\t\t|__________________________________|";

    
    this->display_stock();        // calling display_stock.    
    
    const int g = 20;
    char search[g];				// GETTING THE KEY.
    cout<<"\n\n ENTER THE PRODUCT NAME >>>   ::   ";
    cin>>search;
    int p=0;

    while(p < row-1){

        if(strcmp(iT_Name[p], search) == 0){
            break;
        }
        else{
        	p++;
        }
    }

    if(p == row-1){
        cout<<"\n ITEM NOT FOUND IN THE CART. \n\n";
    }
    else{
        cout<<"\n ITEM FOUND IN THE CART AT [ "<<p+1<<" ] \n\n";		// INCRIMENT IN INDEX(+1).
    }
    
return;
}


////////*LOCAL MAIN FOR MANAGEMENT FUNCTIONS [* SEARCH,ADD,REMOVE & UPDATE *].*////////
void Inventory::inventory_management(){
    
    char c;
	char yes;
	
	buttons();				// CALLING THE BUTTONS FUNCTION.
	
	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
	cout<<"\t\t | "<<setw(30)<<left<<" [ WHAT DO YOU WANT TO DO ? ] "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<"1. SEARCH ITEM IN STOCK."<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<"2. ADD ITEM TO STOCK."<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<"3. REMOVE ITEM FROM STOCK."<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<"4. UPDATE ANY ITEM IN STOCK."<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<"5. EXIT FROM THE MENU."<<"|\n";
  	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
	cin>>c;
	
	loading_line();				// CALLING THE LOADING LINE FUNCTION.
	
	switch(c)
	{
		case '1':
		{
			this->Search_Item();				// CALLING THE SEARCH ITEM FUNCTION.
		
		break;	
		}
		case '2':
		{
			this->Add_Item();				// CALLING THE ITEM ADDING FUNCTION.
		
		break;
		}
		case '3':
		{
			this->Delete_Item();				// CALLING THE ITEM DELETING FUNCTION.
		
		break;
		}
		case '4':
		{	
			this->Update_Item();				// CALLING THE UPDATE MENU FUNCTION.
		
		break;
		}
		case '5':
		{
			cout<<"\n\t *** EXITING FROM THE MANAGEMENT MENU. \n";
			cout<<"\n <<<<  خدا حافظ  >>>>  \n\n";
			return;
			
		break;	
		}
		default:
		{
            cout<<"\n\t\t--------------------------------------\n";
		  	cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
			cout<<"\t\t----------------------------------------\n";
			cout<<"\t\t REDIRECTING TO THE STOCK MANAGEMENT MENU. \n";
			
			this->inventory_management();     //validating input...
        }
			
	}
	
	cout<<"\n\t\t--------------------------------------------------\n";
	cout<<"\t\t| DO YOU WANT TO RETURN TO THE MANAGEMENT PORTAL ? |\n";
	cout<<"\t\t|    PROCEED WITH  [Y/Y] AND RETURN WITH  [N/n]    |\n";
	cout<<"\t\t----------------------------------------------------\n";
	
	cin>>yes;
	
	if(yes=='y' || yes=='Y'){
		inventory_management();
	}
	else{
		return;
	}
	
return;
}


//*ANALYSE THE QUANTITY OF EVERY PRODUCT, AND GENERATE NOTIFICATION IF THE ITEM WAS LOWER IN QUANTITY.*//
void Inventory::Auto_Notify()		
{
    ofstream o("orderItem.txt", ios::app);		// OPEN IN APPEND MODE TO AVOID TRUNKING.
        
    if(o.is_open() )
    {							// WRITING IN FILE.
        for(int i=0 ; i<this->row-1 ; i++){
            if(this->No_Items[i] < 30){           // [30] IS THE THRESHOLD. YOU CAN CHANGE IT AS WELL.

                o<<"ITEM NUMBER :: [ "<< i+1 <<" ]  ,  NAME =  ["<<this->iT_Name[i]<<"] IS LOWER IN QUANTITY.\n";		// INCRIMENT IN INDEX(+1).
            }
        }

        o.close();				// CLOSING FILE TO AVOID CORRUPTION.

    }else{
        cout<<"\n FILE NOT FOUND. \n";
    }
    
    
return; 
}


//*READ NOTIFICATIONS ON LOWER QUANTITY PRODUCTS.*//
void Inventory::Read_Notifications(){

    cout<<"\n\t\t---------------------------------------------------------------\n";
	cout<<"\t\t|   [ WELCOME TO THE LOW QUANTITY-ITEM'S NOTIFICATION CENTER ]  |\n";
	cout<<"\t\t-----------------------------------------------------------------\n";

    int count=0;
    char ch;

    fstream read("orderItem.txt" , ios::in);

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

    string display[row+9];
    int i=0;
    fstream read1("orderItem.txt" , ios::in);
    while(!read1.eof()){
        getline(read1, display[i]);
        cout<<display[i]<<"\n";     //*DISPLAY DATA.*//
        i++;
    }
    read1.close();

return;
}


///////// [* SORT THE INVENTORY ON BASIS OF QUANTITY *] /////////
void arrange(int n, int No_Items[], char** iT_Name, double Price[], double Total_Price[] ) 
{
    for (int i=0 ; i<n-1 ; i++){
        for (int j=0 ; j<n-i-1 ; j++){      //*BUBBLE SORTING ALGORITHM*//

            if (No_Items[j] > No_Items[j+1]){

                swap(No_Items[j], No_Items[j+1]);
                
                char temp[30];
                strcpy(temp, iT_Name[j]);			// COPYING THE CONTENT OF 2ND ARRAY.
                strcpy(iT_Name[j], iT_Name[j+1]);
                strcpy(iT_Name[j+1], temp);
                
                swap(Price[j], Price[j+1]);         //SWAP PRICE OF ITEMS
                swap(Total_Price[j], Total_Price[j+1]);     //SWAP TOTAL PRICE OF ITEMS
            }
        }
    }

return;
}


////////// *[ UPDATING THE FILE FUNCTION ]* ////////////
void update_Product(char** iT_Name, double Price[], int No_Items[], double Total_Price[], int index,
                   const char* newName, double newPrice, int newQuantity, double newTotalPrice) 
{
	strcpy(iT_Name[index], newName);	// NON-CONSTANT POINTER TO CONSTANT DATA.
	Price[index] = newPrice;
	No_Items[index] = newQuantity;
	Total_Price[index] = newTotalPrice;
	return;
}


//////// [ BUTTONS-MENU ] ////////////
void buttons()
{
		const char* color = ANSI_COLOR_RESET;
		cout<<"\n\t\t ______________________________________";
		cout<<"\n\t\t|                                      |";
		cout<<color<<ANSI_COLOR_GREEN<<"\n\t\t| > PRESS THE BUTTON {ONE AT A TIME} < |"<<ANSI_COLOR_RESET;
		cout<<"\n\t\t|      __________________________      |";
		cout<<"\n\t\t|     |                          |     |";
		cout<<"\n\t\t|     |    ' 1 '   ' 2 '   ' 3 ' |     |";
		cout<<"\n\t\t|     |                          |     |";
		cout<<"\n\t\t|     |    ' 4 '   ' 5 '   ' 6 ' |     |";
		cout<<"\n\t\t|     |                          |     |";
		cout<<"\n\t\t|     |    ' 7 '   ' 8 '   ' 9 ' |     |";
		cout<<"\n\t\t|     |__________________________|     |";
		cout<<"\n\t\t|                                      |";
		cout<<"\n\t\t|______________________________________|\n\n";
		
		return;
}


//////// *[ LOADING LINE FUNCTION ]* //////////
void loading_line()
{
	
	int star = 20;
	int space = 65;
	int per = 25;
	
	clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
	
    const char* color = ANSI_COLOR_RESET;
	cout<<"\n\n\t\t\t\t\t _____________________________________" ;
	cout<<"\n\t\t\t\t\t|                                     |";
	cout<<color<<ANSI_COLOR_RED<<"\n\t\t\t\t\t|  >>>    LOADING PLEASE WAIT     <<< |"<<ANSI_COLOR_RESET;
	cout<<"\n\t\t\t\t\t|_____________________________________|"<<endl;
	
	cout<<"\t\t "<<setfill('-')<<setw(89)<<"-"<<setfill(' ')<<endl;
	
	for(int i=0 ; i<=3 ; i++ )
	{
		Sleep(400);
		if(i==0){
			color = ANSI_COLOR_RED;
		}
		else if(i==1){
			color = ANSI_COLOR_PURPLE;
		}
		else if(i==2){
			color = ANSI_COLOR_ORANGE;
		}
		else if(i==3){
			color = ANSI_COLOR_GREEN;
		}
		
		cout<<"\t\t | "<<color<<setfill('*')<<setw(star)<<" "<<setfill(' ')<<setw(space)<<" "<<" | "<<per<<" %"<<ANSI_COLOR_RESET<<endl;
		
		star += 20 ;
		space -= 20;
		per += 25 ;
	}
	
	cout<<"\t\t "<<setfill('-')<<setw(89)<<"-"<<setfill(' ');
	
	cout<<"\n\t\t\t\t\t\t ___________________________" ;
	cout<<"\n\t\t\t\t\t\t|                           |";
	cout<<color<<ANSI_COLOR_GREEN<<"\n\t\t\t\t\t\t|  >>>    COMPLETED    <<<  |"<<ANSI_COLOR_RESET;
	cout<<"\n\t\t\t\t\t\t|___________________________|\n"<<endl;
		
return;
}


/////// *[ CLEAR-SCREEN FUNCTION ]* //////////
void clearScreen()
{
    cout<<CLEAR_SCREEN;  		// USING THE DEFINED FUNCTIONALITY.
}


