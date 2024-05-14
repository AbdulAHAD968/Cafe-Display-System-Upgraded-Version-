////////////////////////// *{ SALES TRACKING CLASS AVAILABLE HERE. }* ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"


//*CONSTRUCTOR OF TRACK_SALES CLASS.*//
Track_Sales::Track_Sales(){
    
    this->col = 20;
    this->row = 0;
    this->Price = nullptr;
    this->No_Items = nullptr;
    this->Total_Price = nullptr;
    this->iT_Name = nullptr;
    this->sum_Price = 0;
    
}


//*FUNCTION TO DE-ALLOCATE ALL THE MEMORY.*//
void Track_Sales::Free_Them(){

    delete[] this->Price;
    delete[] this->No_Items;
    delete[] this->Total_Price;
    delete[] this->iT_Name;
    for(int i=0 ; i<row ; i++){
        delete [] iT_Name[i];			// DELETING THE MEMORY ALLOCATED IN HEAP.
    }

    this->Price = nullptr;
    this->No_Items = nullptr;
    this->Total_Price = nullptr;
    this->iT_Name = nullptr;
}


//*DESTRUCTOR.*//
Track_Sales::~Track_Sales(){
    Free_Them();            //FREE AND UNDANGLE ALL THE ALLOCATED MEMORY.
}


///////* [LOCAL-MAIN FOR SALES RELATED FUNCTIONS.]* //////////
void Track_Sales::track_sales()
{
	cout<<"\n\t\t------------------------------------------"; 
    cout<<"\n\t\t| >> WELCOME TO THE TRACK SALES MENU <<  |";
    cout<<"\n\t\t------------------------------------------\n\n";
    
    int choice;
    buttons();				// CALLING THE BUTTONS FUNCTION.
        
    cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
  	cout<<"\t\t | "<<setw(55)<<left<<"<< ENTER THE RESEPCTED NUMBER TO PROCEED >> "<<"|\n";
  	cout<<"\t\t | "<<setw(55)<<left<<" [1]. TRACK THE SALES PER-DAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(55)<<left<<" [2]. TRACK THE TOTAL SALES. "<<"|\n";
  	cout<<"\t\t | "<<setw(55)<<left<<" [3]. TOTAL PRICE OF STOCK ITEMS. "<<"|\n";
  	cout<<"\t\t | "<<setw(55)<<left<<" [4]. EXIT. "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
    cin>>choice;
        
    switch(choice)
    {
        case 1:
        {
            this->Day_Sales();
        }
        break;
        case 2:
        {
            this->Track_Total_Sales();
        }
        break;
        case 3:
        {
            this->Evaluate_Stock_Price();
        }
        break;
        case 4:
        {
            cout<<"\n *** EXITING THE SALES TRACK MENU. \n";
            cout<<"\n <<<<  خدا حافظ  >>>>  \n\n";
        }
        break;
        default:
        {
            cout<<"\n\t\t--------------------------------------\n";
            cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t\t----------------------------------------\n";
            cout<<"\t\t RE-DIRECTING TO THE MENU_BAR. \n";
            
            this->track_sales();
        }
    }
    
return;      
}


/////// *[ DAY-SALES RECORD ]*//////////
void Track_Sales::Day_Sales()
{
	char yes;
	int day;
	cout<<"\n\t\t ------------------------------------------------------";
	cout<<"\n\t\t | >>> WELCOME TO THE DAY-SALES TRACKING CENTER. <<<  |";
	cout<<"\n\t\t ------------------------------------------------------";
	
	buttons();				// CALLING THE BUTTONS FUNCTION.
	
	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
	cout<<"\t\t | "<<setw(30)<<left<<" >>> [ SELECT THE DAY ] <<< "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [1].   MONDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [2].   TUESDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [3].   WEDNESDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [4].   THURSDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [5].   FRIDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [6].   SATURDAY. "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [7].   SUNDAY.  "<<"|\n";
  	cout<<"\t\t | "<<setw(30)<<left<<" [8].   EXIT.  "<<"|\n";
  	cout<<"\t\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
	cin>>day;
	
	loading_line();				// CALLING THE LOADING LINE FUNCTION.
	
	string File_Name="";
    string DAY="";
    
	switch(day)
	{
		case 1:
		{
            DAY = "MONDAY";
			File_Name = "monday.txt";
        }		
		break;
		case 2:
		{
            DAY = "TUESDAY";
            File_Name = "tuesday.txt";
        }
		break;
		case 3:
		{
            DAY = "WEDNESDAY";
            File_Name = "wednesday.txt";
        }		
		break;
		case 4:
		{
            DAY = "THURSDAY";
            File_Name = "thursday.txt";
        }	
		break;
		case 5:
		{
            DAY = "FRIDAY";
            File_Name = "friday.txt";
        }		
		break;
		case 6:
		{
            DAY = "SATURDAY";
            File_Name = "saturday.txt";
        }
        break;
		case 7:
		{
            DAY = "SUNDAY";
            File_Name = "sunday.txt";
        }		
		break;		
		case 8:
		{
            
    		cout<<"\n\t RETURNING FROM THE SALES TRACKING MENU. \n";
			return;
        }
		break;
		default:
		{	
			cout<<"\n\t DAY NOT FOUND IN MY CALENDER. THERE ARE ONLY 7-DAYS.  \n";
  	 		cout<<"\n\t\t--------------------------------------\n";
			cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
			cout<<"\t\t----------------------------------------\n";
			Day_Sales();
        }
		break;
		
	}

    char a;
    fstream line(File_Name , ios::in);		// OPEN FILE IN READING MODE.
    
    if(!line){
        cerr<<"\n\t\t FILE NOT FOUND. CHECK THE FILE NAME.\n";
        return;
    }
    
    while(line.get(a)){
        if(a=='\n'){			// COUNTING THE NUMBER OF LINES FROM THE FILE.
            this->row++ ;
        }
    }
    
    line.clear();				// CLEARING THE BUFFER SPACE.
    line.seekg( 0 , ios::beg);		// MOVE CURSOR TO THE BEGINING OF FILE.
    line.close();				// CLOSING THE FILE TO PREVENT DATA CORRUPTION.
    
    Price=new double[this->row];
    No_Items=new int[this->row];
    Total_Price=new double[this->row];
    
    iT_Name=new char*[this->row];
    for(int i=0 ; i<this->row ; i++){
        iT_Name[i]=new char[50];
    }
    
    double sum = 0;
    int w=0 ;


    ifstream q( File_Name , ios::in );		// READING FROM FILE.
    if(!q){
        cout<<" FILE NOT FOUND ! \n";
    }

    int R=0;
    cout<<"\n\t\t------------------------------------------\n";
    cout<<"\t\t| TOTAL SALES MADE  ON  "<<DAY<<"  ARE ::  |\n";
    cout<<"\t\t--------------------------------------------\n\n";
        
    cout<<"\t ORDER "<<"  PRODUCT_NAME   "<<" PRICE "<<"  QUANTITY "<<"  TOTAL_PRICE"<<endl<<endl;

    while( !q.eof() ){

        q>>iT_Name[R] >>Price[R] >>No_Items[R] >>Total_Price[R] ;	// DISPLAYING CONTENT OF FILE.
        if( !q.eof() ){

            cout<<setw(4)<<"\t [ "<<R+1<<" ]  "<<setw(10)<<iT_Name[R]<<"  |  "<<setw(5)<<Price[R]<<"  |  "<<setw(5)<<No_Items[R]<<"  |  "<<setw(5)<<Total_Price[R]<<endl  ;
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

    Free_Them();            //FREE AND UNDANGLE ALL THE ALLOCATED MEMORY.

	
	cout<<"\n\t\t---------------------------------------------\n";
	cout<<"\t\t| DO YOU WANT TO SEE OTHER'S  > DAY < SALES ? |\n";
	cout<<"\t\t| PROCEED WITH  [Y/Y] AND RETURN WITH  [N/n]  |\n";
	cout<<"\t\t-----------------------------------------------\n";
	cin>>yes;
	
	if(yes=='y' || yes=='Y'){
		Day_Sales();
	}
	else{
		return;
	}
	
}


/////// *** [TRACK TOTAL SALES IR-RESPACTIVE OF DAY.] *** /////
void Track_Sales::Track_Total_Sales()
{
    cout<<"\n\t\t -------------------------------------------------------------------";
	cout<<"\n\t\t |      <<< WELCOME TO THE TOTAL SALES-TRACKING MENU.   >>>        |";
	cout<<"\n\t\t |   >>> YOU CAN TRACK THE TOTAL SALES AND ORDER FROM HERE. <<<    |";
	cout<<"\n\t\t -------------------------------------------------------------------";

    char a;
    fstream line("sales.txt" , ios::in);		// OPEN FILE IN READING MODE.
    if(!line){
        cerr<<"\n\t\t FILE NOT FOUND. CHECK THE FILE NAME.\n";
        return;
    }
    while(line.get(a)){
        if(a=='\n'){			// COUNTING THE NUMBER OF LINES FROM THE FILE.
            this->row++ ;
        }
    }
    
    line.clear();				// CLEARING THE BUFFER SPACE.
    line.seekg( 0 , ios::beg);		// MOVE CURSOR TO THE BEGINING OF FILE.
    line.close();				// CLOSING THE FILE TO PREVENT DATA CORRUPTION.
    
    Price=new double[this->row];
    No_Items=new int[this->row];
    Total_Price=new double[this->row];
    
    iT_Name=new char*[this->row];
    for(int i=0 ; i<this->row ; i++){
        iT_Name[i]=new char[50];
    }
    
    double sum = 0;
    int w=0 ;


    ifstream q( "sales.txt" , ios::in );		// READING FROM FILE.
    if(!q){
        cout<<" FILE NOT FOUND ! \n";
    }

    int R=0;
    cout<<"\n\t\t---------------------------------------\n";
    cout<<"\t\t| TOTAL SALES MADE THROUGHT PERIOD    = |\n";
    cout<<"\t\t-----------------------------------------\n\n";
        
    cout<<"\t ORDER "<<"  PRODUCT_NAME   "<<" PRICE "<<"  QUANTITY "<<"  TOTAL_PRICE"<<endl<<endl;

    while( !q.eof() ){

        q>>iT_Name[R] >>Price[R] >>No_Items[R] >>Total_Price[R] ;	// DISPLAYING CONTENT OF FILE.
        if( !q.eof() ){

            cout<<setw(4)<<"\t [ "<<R+1<<" ]  "<<setw(10)<<iT_Name[R]<<"  |  "<<setw(5)<<Price[R]<<"  |  "<<setw(5)<<No_Items[R]<<"  |  "<<setw(5)<<Total_Price[R]<<endl  ;
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

    Free_Them();            //FREE AND UNDANGLE ALL THE ALLOCATED MEMORY.

return;    	        	
}


///// **{FOR CALCULATING THE TOTAL PRICE OF ITEMS IN STOCK.}** /////
void Track_Sales::Evaluate_Stock_Price(){
    
	this->row = 0;
    char a;
    
    fstream line("stock.txt" , ios::in);		// OPEN FILE IN READING MODE.
    
    if(!line){
    	cerr<<"\n\t\t FILE NOT FOUND . CHECK THE FILE NAME.\n";
    	return;
    }
    
    while(line.get(a)){
    	if(a=='\n'){
    		this->row++ ;
    	}
    }
    
    line.clear();
    line.seekg(0 , ios::beg);		// MOVE THE CURSOR TO THE BEGINING OF THE FILE.
    line.close();		// CLOSING THE FILE TO PREVENT DATA CORRUPTION.

    Price=new double[this->row+1];
    No_Items=new int[this->row+1];
    Total_Price=new double[this->row+1];
    
    iT_Name=new char*[this->row+1];
    for(int i=0 ; i<this->row+1 ; i++){
        iT_Name[i]=new char[50];
    }
	cout<<"\n *** [ WELCOME TO THE DISPLAY STOCK PORTAL ] *** \n";
	cout<<" HERE YOU CAN ONLY SEE THE ITEMS AVAILABLE IN THE STOCK. \n";
	
    char head[100];
	int p=0;
	
	const char* color = ANSI_COLOR_RESET;			// NON-CONSTANT POINTER TO CONSTANT DATA.
	
	
	fstream o( "stock.txt", ios::in );		// OPEN IN READING MODE.
	
	if(!o){
		cout<<"\n FILE NOT EXISTS. \n";
		cout<<"\n CHECK THE FILE NAME. \n";
	}
	else{
		o.getline(head,100,'\n') ;			// FEEDING DATA FROM FILE
		while( o.getline( iT_Name[p] , 50 , ' ') , o >> Price[p] >> No_Items[p] >> Total_Price[p] ){
			o.ignore();
			p++ ;
		}
	}
	o.close();					// TO PREVENT FILE FROM BEING CORRUPTED.
	
	arrange( p, No_Items, iT_Name, Price, Total_Price);	    // CALLING THE SORT FUNCTION [BY-QUANTITY].
	
	cout<<setw(6)<<color<<ANSI_COLOR_PURPLE<<"\n\t INDEX "<<head<<ANSI_COLOR_RESET<<endl;
	
	for(int c=0 ; c<p ; c++ )
	{
		if(No_Items[c] == 0)                //[ASSIGNING COLOR ON THE BASES OF THRESHOLD-{30} ]
		{
			color = ANSI_COLOR_RED;
		}
		else if( No_Items[c] > 0 && No_Items[c] <=30 )
		{
			color = ANSI_COLOR_YELLOW;
		}
		else if( No_Items[c] > 20 )
		{
			color = ANSI_COLOR_GREEN;
		}
		
       cout<<color<<"\t [ "<<setw(2) << c+1<<" ] "<< setw(10) << iT_Name[c]<<"  |  "<< setw(5)<<Price[c]<<"  |  "
             <<setw(5)<<No_Items[c]<<"  |  "<< setw(7)<<Total_Price[c] <<ANSI_COLOR_RESET<<endl;
	
	}

    double Evaluate[2];
    Evaluate[0]=0;
    Evaluate[1]=0;
    for(int i=0 ; i<row-1 ; i++){
        Evaluate[0] += No_Items[i];
        Evaluate[1] += Total_Price[i];
    }

    cout<<"\n\t\t------------------------------------------\n";
	cout<<"\t\t| TOTAL RECORD OF THE ITEMS AND PRICE :: |\n";
	cout<<"\t\t------------------------------------------\n";

    cout<<"\n\n\t\t -"<<setfill('-')<<setw(47)<<"-"<<setfill(' ')<<endl;
    cout<<"\t\t | "<<setw(25)<<left<<" TOTAL STOCK PRICE        >>  "<<"   ::  "<<setw(8)<<Evaluate[1]<<"|\n";
    cout<<"\t\t | "<<setw(25)<<left<<" TOTAL NUMBER OF ITEMS    >>  "<<"   ::  "<<setw(8)<<Evaluate[0]<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(47)<<"-"<<setfill(' ')<<endl<<endl;

return;
}



