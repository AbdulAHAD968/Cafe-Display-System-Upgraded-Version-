/////////////////////////////// *{ WHOLE EMPLOYEE CLASS DEFINED HERE. }* ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "header.h"


//*I-STREAM FRIEND FUNTION TO TAKE INPUT FROM THE USER.*//
istream& operator>>(istream& input , Employee& emp){

    cout<<"\n ENTER THE NAME OF THE EMPLOYEE : ";
    input>>emp.name;
    cout<<"\n ENTER THE PASSWORD OF THE EMPLOYEE : ";
    input>>emp.password;

return input;
}


//*USER DEFINED DEFAULT CONSTRUCTOR.*//
Employee::Employee(string name, string password ){
    this->name = name;
    this->password =password;
}


//*VERIFICATION FUNCTION.*//
bool Employee::LOGIN_VERIFY(){

    string read_name="";
    string read_password="";
    
    bool login = false;

    cout<<"\n ENTER THE NAME OF THE EMPLOYEE : ";
    cin>>this->name;
    cout<<"\n ENTER THE PASSWORD OF THE EMPLOYEE : ";
    cin>>this->password;

    ifstream extract("employee_pass.txt" , ios::in );

    if(!extract){
        cout<<"\n\t\t FILE NOT FOUND. \n\n";
        return false;
    }

    while( extract >> read_name >> read_password){		// EXTRACTIONG DATA FROM FILE.
        if(read_name == this->name && read_password == this->password ){
            extract.close();
            return true;
        }
    }

    extract.close();					// CLOSING FILE TO PREVENT CORRUPTION.

return false;
}


//*MAIN MENU OF EMPLOYEE FUNCTION.*//
void Employee::MAIN_MENU(){

    char choice;
    char exit;

    do{
    		
        cout<< "\n\t\t-----------------------------------"; 
        cout<< "\n\t\t| >> WELCOME TO EMPLOYEE MENU <<  |";
        cout<< "\n\t\t-----------------------------------\n\n\n";
        
        buttons();				// CALLING THE BUTTONS FUNCTION.
            
        cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
  		cout<<"\t\t | "<<setw(55)<<left<<"<< ENTER THE CORRESPONDING NUMBER TO PROCEED >> "<<"|\n";
  		cout<<"\t\t | "<<setfill('-')<<setw(55)<<""<<setfill(' ')<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"1. TAKE ORDER FROM STUDENT / STAFF - ADD SALES TO CDS. "<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"2. SEARCH ITEMS. "<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"3. SEE NOTIFICATIONS FROM ADMIN ON LOW STOCK PRODUCTS."<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"4. SEE ONLINE / SCHEDULED ORDERS. "<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"5. PLAY GAMES [ TIME-PASS ]."<<"|\n";
  		cout<<"\t\t | "<<setw(55)<<left<<"6. LOGOUT FROM THE SITE. "<<"|\n";
  		cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;        
        cin>> choice;
        	
    	loading_line();				// CALLING THE LOADING LINE FUNCTION.

    	if( choice<='0' || choice>='9' )
 		{
  			cout<<"\n\t #################   WARNING    ###################\n"; 
			cout<<"\n\t  !!!!!! KINDLY AVOID ENTERING CHARACTRES !!!!!! \n";
			cout<<"\t         ------- RE-ENTER THE CASE ------- \n";
			cout<<"\n\t -- [ THE MAIN MENUE WILL BE SHORTLY DISPLAYED ] --\n\n";
			
        continue;
  		}
    
  	if( choice>='0' && choice<='9' )
  	{
        switch (choice)
        {  
            case '1':
            {
                this->PHYSICAL_ORDER();					// TAKE ORDERS.
            		
            break;
            }
	        case '2':							// SEARCH ITEM IN STOCK.
           	{	
           		this->Search_Item();

            break;
            }
            case '3':							// LOWER-QUANTITY PRODUCTS.
           	{	
           		this->Read_Notifications();
           		
            break;
            }
            case '4':							// SEE ONLINE ORDERS.
            {    	
                this->see_details_of_online_orders();
                this->Give_Response_To_Order();
                	
            break; 
            }
            case '5':							// PLAY GAMES.
            {    	
                Play_Games();
                	
            break;           
            }
            case '6':
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
                cout<<"\n\t\t-----------------------------\n";
                cout<<"\t\t|  !  ENTER A VALID INPUT ! |\n";
                cout<<"\t\t-----------------------------\n";
			
            break;
            }
        }
         
              
        cout<< "\n\t\t------------------------------------------------------"; 
        cout<< "\n\t\t|  DO YOU WANT TO EXIT FROM EMPLOYEE MENU ? [ Y/N ]  |";
        cout<< "\n\t\t------------------------------------------------------\n\n";
        cin>>exit;

        if(exit=='y' || exit=='Y'){

            cout<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
            cout<<"\t\t | "<<setw(48)<<left<<"          ** TERMINATING THE PROGRAM ** "<<"|\n";
            cout<<"\t\t | "<<setw(48)<<left<<"             && THANKS FOR COMING && "<<"|\n";
            cout<<"\t\t | "<<setw(48)<<left<<"                     GOOD_BYE"<<"|\n";
            cout<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl<<endl;
        
        break;
        }
        else if(exit=='n' || exit=='N'){
            cout<<"\n\t ******* SELECT THE FUNCTION YOU WANT TO PERFORM AGAIN ******* \n"; 
        }
	}

   }while(1);

return;
}


///////// *[ SEE ONLINE ORDERS ]* ////////////
void Employee::see_details_of_online_orders()
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

    string display[count];

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
void Employee::Give_Response_To_Order()
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



