/////////////////////////////// *{ WHOLE CUSTOMER CLASS DEFINED HERE. }* ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"


//*PARAMETRIZED CONSTRUCTOR.*//
Customer::Customer(string name, string password){
    this->name = name;
    this->password = password;
}


//*I-STREAM FRIEND FUNCTION TO TAKE INPUT FROM THE USER.*//
istream& operator>>(istream& input, Customer& cust){
    cout<<"\n PLEASE ENTER YOUR NAME = ";
    input>>cust.name;
    cout<<"\n PLEASE ENTER YOUR PASSWORD = ";
    input>>cust.password;

return input;
}


//*VERIFICATION FUNCTION.*//
bool Customer::LOGIN_VERIFY(){

    string read_name;
    string read_password;

    cout<<"\n PLEASE ENTER YOUR NAME = ";
    cin>>this->name;
    cout<<"\n PLEASE ENTER YOUR PASSWORD = ";
    cin>>this->password;
    
    bool login = false;
    
    ifstream extract("user_pass.txt");

    if(!extract){
        cout<<"\n ERROR IN OPENING FILE.";
        return false;
    }

    while( extract >> read_name >> read_password){		// EXTRACTIONG DATA FROM FILE.

        if(read_name == this->name && read_password == this->password){
            extract.close();
            return true;
        }
    }
         
    extract.close();					// CLOSING FILE TO PREVENT CORRUPTION.
  
return false;
}


//*[UTILITY FUNCTION FOR RESPONSE]SEARCH IS THE WORD IS PRESENT IN THE TEXT LINE.*//
bool search(const char* c1, const char* c2){
    
    int len_1 = strlen(c1);
    int len_2 = strlen(c2);

    for(int i=0 ; i<=len_1-len_2 ; ++i){

        int j;
        for(j=0 ; j<len_2 ; ++j){
            if (c1[i + j] != c2[j]){
                break;
            }
        }
        if(j == len_2){
            return true;
        }
    }

return false;
}


//*GIVE REVIEW ON THE SERVICES,FOOD, AND BEHAVOIUR OF EMPLOYEE.*//
void Customer::give_review()
{
	const int size=300 , col=30;
	
	char* rev = new char[size];		// ALLOCATING MEMORY IN HEAP.
	char* purpose = new char[col];
	
	cin.ignore();
	
    cout<<"\n ON WHICH THING YOU WANT TO GIVE YOUR RESPONSE [FOOD, EMPLOYEE, CLEANLINESS, etc.]\n";
	cin.getline(purpose, col);
	
	cout<<"\n ENTER YOUR REVIEW >>> \n";
	cin.getline(rev, size);
	
	ofstream review("review.txt", ios::app);		// OPEN IN APPEND MODE TO AVOID TRUNKING.
	
	if(review.is_open() ){							// WRITING IN FILE.
        
        review<<" ON { " <<purpose<<" } BY : [ "<<this->name<<" ] ::  "<<rev<<endl;
        review.close();					// CLOSING FILE TO AVOID CORRUPTION.
    }
    else{
        cout<<"\n FILE NOT FOUND. \n";
    }
	
    char** Good_word = new char*[5];
    char** Bad_word = new char*[5];
    for (int i=0 ; i<5 ; i++){
        Good_word[i] = new char[20];
        Bad_word[i] = new char[20];
    }

    strcpy(Good_word[0], "GOOD");
    strcpy(Bad_word[0], "AVERAGE");
    strcpy(Good_word[1], "BETTER");
    strcpy(Bad_word[1], "POOR");
    strcpy(Good_word[2], "BEST");
    strcpy(Bad_word[2], "WORST");
    strcpy(Good_word[3], "WELL");
    strcpy(Bad_word[3], "BAD");
    strcpy(Good_word[4], "AMAZING");
    strcpy(Bad_word[4], "NOT GOOD");

    int Good_count = 0;
    int Bad_count = 0;
    
    for(int i=0 ; i<5 ; i++){
        
        if(search(rev , Good_word[i])){
            Good_count++;
        }
        
        if(search(rev , Bad_word[i])){
            Bad_count++;
        }
    }

    if(Good_count > Bad_count ){
        cout<<"\n\t\t---------------------------------------\n";
		cout<<ANSI_COLOR_ORANGE<<"\t\t| THANKS ALOT. FOR YOUR RESPONSE  :)  |\n"<<ANSI_COLOR_RESET;
		cout<<"\t\t---------------------------------------\n";
    }
    else if(Good_count == Bad_count){
        cout<<"\n\t\t----------------------------------------";
		cout<<ANSI_COLOR_GREEN<<"\n\t\t|  :)  UNABLE TO GUESS THE MOOD   ):   |"<<ANSI_COLOR_RESET;
		cout<<"\n\t\t----------------------------------------";
    }
    else{
        cout<<"\n\t\t---------------------------------------\n";
		cout<<ANSI_COLOR_RED<<"\t\t|  SORRY FOR OUR INCONVINENCE.   ):   |\n"<<ANSI_COLOR_RESET;
		cout<<"\t\t---------------------------------------\n";
    }

    for(int i=0 ; i<5 ; i++){
        delete[] Good_word[i];
        delete[] Bad_word[i];
    }

    delete[] Bad_word;
    delete[] Good_word;
	delete []rev;			// DELETING THE ALLOCATED MEMORY.
	delete []purpose;
	
	rev = NULL;			    // UNDANGLING THEM.
	purpose = NULL;
    Bad_word = NULL;
    Good_word = NULL;

return;
}


/////////////////////*{SEE THE RESPONSE OF ADMIN}*////////////////////
void Customer::see_response()
{
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

    cout<<"\n -------------------------------------------------------";
	cout<<"\n |   ***** WELCOME TO THE NOTIFICATIONS BAR. *****     | ";
	cout<<"\n |  YOU CAN SEE EXCIETING NOTIFICATIONS FROM HERE ON.  | ";
    cout<<"\n -------------------------------------------------------\n";

    
    fstream read1("responseOrder.txt" , ios::in);
    while(!read1.eof()){
        getline(read1, display[i]);
        cout<<" => ["<<i+1<<"] "<<display[i]<<endl;
        i++;
    }
    read1.close();
    
return;
}


/////////////// [ * SEE NOTIFICATIONS BY CDS * ] /////////////////////
void Customer::CDS_NOTIFICATIONS()
{
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

    cout<<"\n -------------------------------------------------------";
	cout<<"\n |   ***** WELCOME TO THE NOTIFICATIONS BAR. *****     | ";
	cout<<"\n |  YOU CAN SEE EXCIETING NOTIFICATIONS FROM HERE ON.  | ";
    cout<<"\n -------------------------------------------------------\n";

    
    fstream read1("notification.txt" , ios::in);
    while(!read1.eof()){
        getline(read1, display[i]);
        cout<<" => ["<<i+1<<"] "<<display[i]<<endl;
        i++;
    }
    read1.close();
	
return;       	    
}


////////// *[ FUNCTION TO DISPLAY THE --[CUSTOMER]--MENU. ]* ///////////////////
void Customer::MAIN_MENU()
{
    char choice;
    char exit;

    do{
       	
        cout<< "\n\t\t------------------------------------------"; 
        cout<< "\n\t\t| >> WELCOME TO STUDENT / STAFF MENU  << |";
        cout<< "\n\t\t------------------------------------------\n\n";
        
        buttons();				// CALLING THE BUTTONS FUNCTION.
            
        cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
        cout<<"\t\t | "<<setw(55)<<left<<"<< ENTER THE CORRESPONDING NUMBER TO PROCEED >> "<<"|\n";
        cout<<"\t\t | "<<setfill('-')<<setw(55)<<""<<setfill(' ')<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"1. SEARCH AND ORDER FOOD "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"2. GIVE COMPLAINTS THROUGH CDS "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"3. SEARCH ITEMS THROUGH CDS "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"4. GIVE ONLINE AND SCHEDULED ORDERS. "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"5. SEE NOTIFICATIONS THROUGH CDS. "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"6. PLAY GAMES. [ NEWLY ADDED ] "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"7. SEE [ ADMIN / EMPLOYEE ] RESPONSE. "<<"|\n";
        cout<<"\t\t | "<<setw(55)<<left<<"8. LOGOUT FROM THE SITE. "<<"|\n";
        cout<<"\t\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
        cin>>choice;
        
        loading_line();				// CALLING THE LOADING LINE FUNCTION.
        
        
        if( choice<='0' || choice>='9' ){
        cout<<"\n\t\t #################   WARNING    ###################\n"; 
        cout<<"\n\t\t !!!!!!!! KINDLY AVOID ENTERING CHARACTRES !!!!!!!! \n\n";
        cout<<"\t\t         ------ RE-ENTER THE CASE ------- \n";
        cout<<"\n\t\t ---- THE MAIN MENUE WILL BE SHORTLY DISPLAYED ----\n\n";
        continue;
    
        }
        
        if( choice>='0' && choice<='9' )
        {
        
            switch(choice)
            {
                case '1':
                {
                    cout<<"\n*** YOU CAN SEARCH AND ORDER FOOD FROM HERE. *****\n\n";
                    this->Search_Item();
                    
                break;
                }          
                case '2':
                {	
                    this->give_review();
                    
                break;
                }        
                case '3':
                {
                    cout<<"\n **** WELCOME TO THE SEARCH MENU **** \n\n";
                    cout<<" YOU CAN SEARCH ITEMS IN THE MENU FROM HERE. \n";
                    this->Search_Item();
                        
                break;
                }       
                case '4':
                {
                    cout<<"\n\t\t-----------------------------------\n";
                    cout<<"\t\t|   !!!!  PLACE ONLINE_ORDER  !!!!  |\n";
                    cout<<"\t\t-------------------------------------\n"; 

                   
                    this->ONLINE_ORDER();
                        
                    cout<<"\n\t\t--------------------------------------\n";
                    cout<<"\t\t|  HOPE SO YOUR EXPERIENCE WENT WELL.  |\n";
                    cout<<"\t\t|        THANKS FOR COMMING HERE.      |\n";
                    cout<<"\t\t----------------------------------------\n";
                        
                break;
                }
                case '5':
                {    	
                    this->CDS_NOTIFICATIONS();			// FOR INTERESTING NOTIFICATIONS.
                        
                break;    
                }
                case '6':
                {               	  	
                   Play_Games();            //no need of obj. Global function.

                break;
                }
                case '7':
                {
                    this->see_response();
                
                break;    
                }
                case '8':
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
                    cout<<"\n\t--------------------------------------\n";
                    cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                    cout<<"\t----------------------------------------\n";
                    break;
                }
            }

        }

    }while(1);

return;
}


