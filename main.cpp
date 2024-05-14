/////////////////////////////// *{ DRIVER CODE IS AVAILABE HERE. }* ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"

const char* color = ANSI_COLOR_RESET;

/////// **[ MAIN FUNCTION ]** //////////
int main(){

    Users **s = new Users*[3];
    s[0] = new Admin();
    s[1] = new Employee();
    s[2] = new Customer();

    char role;			// Taking the role in CHARACTER data-type to manage input in character.
    char exit;
	
    cout<< "\n\t\t---------------------------------------";
    cout<< "\n\t\t| ----------------------------------- |"; 
    cout<< ANSI_COLOR_ORANGE<< "\n\t\t| |   >>   [ WELCOME SIR ]    <<    | |"<<ANSI_COLOR_RESET;
    cout<< "\n\t\t| ----------------------------------- |";
    cout<< "\n\t\t---------------------------------------\n";

    Sleep(3000);
    do{
  	    cout<< "\n\t\t------------------------------------------"; 
        cout<<color<<ANSI_COLOR_PURPLE<< "\n\t\t| >>>   PLEASE DEFINE YOUR ROLE    <<<   |"<<ANSI_COLOR_RESET;
        cout<< "\n\t\t------------------------------------------\n";
        
        Sleep(2000);
        clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
	
	    buttons();
	
        cout<<"\n\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
        cout<<"\t\t | "<<setw(48)<<left<<"<< ENTER THE CORRESPONDING NUMBER TO PROCEED >> "<<"|\n";
        cout<<"\t\t | "<<setfill('-')<<setw(48)<<""<<setfill(' ')<<"|\n";
        cout<<"\t\t | "<<setw(48)<<left<<"1. ADMIN OF THE CAFE DISPLAY SYSTEM "<<"|\n";
        cout<<"\t\t | "<<setw(48)<<left<<"2. EMPLOYEES OF THE CAFE DISPLAY SYSTEM "<<"|\n";
        cout<<"\t\t | "<<setw(48)<<left<<"3. STUDENTS / STAFF OF THE CAFE DISPLAY SYSTEM "<<"|\n";
        cout<<"\t\t | "<<setw(48)<<left<<"4. EXIT THE CAFE DISPLAY SYSTEM "<<"|\n";
        cout<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
        cin>>role;
        
        clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
    
        if( role<='0' || role>='9' ){

            cout<<"\n\t #################   WARNING    ###################\n"; 
            cout<<"\n\t !!!!!!!! KINDLY AVOID ENTERING CHARACTRES !!!!!!!! \n\n";
            cout<<"\t ------- RE-ENTER THE CASE ------- \n";
            cout<<"\n\t ------- THE MAIN MENUE WILL BE SHORTLY DISPLAYED -------\n\n";
            continue;
                
        }
        
        if( role>='0' && role<='9' )
        {
        
            cout<< "\n\t\t--------------------------------------------------"; 
            cout<< "\n\t\t|    ** [ THANKS FOR YOUR COOPERATION ] **       |";
            cout<< "\n\t\t| GRANTING YOU ACCESS ACCORDING TO YOUR CHOICE > |";
            cout<< "\n\t\t--------------------------------------------------\n\n";
            
            loading_line();				// CALLING THE LOADING LINE FUNCTION.
          

            ///////////////////////////////// [ ENTERING THE RELEVANT CASE USING SWITCH ] ////////////////////////////////////

            switch(role)
            {
                case '1':
                {
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------"; 
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|     >>>  WELCOME BACK! ESTEEMED ADMIN  <<<     |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|    <<<  FIRST LET US VERIFY YOUR IDENITY >>>   |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------\n\n"<<ANSI_COLOR_RESET;
                    
                    bool verify = false;
                    static int count=3;
                    do{
                        
                        verify = s[0]->LOGIN_VERIFY(); 				// CALLING THE EMPLOYEE LOGIN FUNCTION.
                        --count;					// DECRIMENTING THE COUNT BY 1.
                        
                        if(verify){
                            break;
                        }
                        
                        if(verify==false){
                            cout<<"\n WRONG CREDENTIALS PLEASE RE-ENTER THE USER NAME AND PASSWORD.\n";
                            cout<<"\n                      !!!  BE-AWARE !!!    \n";
                            cout<<"\t YOU ARE LEFT WITH ONLY  [ "<<count<<" ]  CHANCES.  \n\n";
                        }
                        
                        if(count == 0){				// RESTRICTING TO ONLY THREE ATTEMPTS.
                            cout<<"n\t NO MORE CHANCE WILL BE ALLOCATED. \n\n";
                            break;
                        }
                        
                    }while(count>0);

                    if(verify){
                        s[0]->MAIN_MENU();
                    }
                    else{
                        cout<<"\n\t\t------------------------------------------"; 
                        cout<<"\n\t\t|     >>>  VERIFICATION FAILED   <<<     |";
                        cout<<"\n\t\t------------------------------------------\n\n";
                    
                    break;
                    }
                }
                break;
                case '2':
                { 
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------"; 
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|     >>>  WELCOME BACK! DEAR EMPLOYEE   <<<     |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|    <<<  FIRST LET US VERIFY YOUR IDENITY >>>   |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------\n\n"<<ANSI_COLOR_RESET;

                    bool verify = false;
                    static int count=3;
                    do{

                        verify = s[1]->LOGIN_VERIFY(); 				// CALLING THE EMPLOYEE LOGIN FUNCTION.
                        --count;					            // DECRIMENTING THE COUNT BY 1.
                        
                        if(verify==true){
                            break;
                        }
                        else if(verify==false){
                            cout<<"\n WRONG CREDENTIALS PLEASE RE-ENTER THE USER NAME AND PASSWORD.\n";
                            cout<<"\n                      !!!  BE-AWARE !!!    \n";
                            cout<<"\t YOU ARE LEFT WITH ONLY  [ "<<count<<" ]  CHANCES.  \n\n";
                        }
                        if(count == 0){				// RESTRICTING TO ONLY THREE ATTEMPTS.
                            cout<<"n\t NO MORE CHANCE WILL BE ALLOCATED. \n\n";
                            break;
                        }
                        
                    }while(count>0);

                    if(verify){
                        s[1]->MAIN_MENU();
                    }
                    else{
                        cout<<"\n\t\t------------------------------------------"; 
                        cout<<"\n\t\t|     >>>  VERIFICATION FAILED   <<<     |";
                        cout<<"\n\t\t------------------------------------------\n\n";
                    
                    break;
                    }
                }
                break;
                case '3':
                {
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------"; 
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|     >>>  WELCOME BACK! ESTEEMED USER   <<<     |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t|    <<<  FIRST LET US VERIFY YOUR IDENITY >>>   |";
                    cout<<ANSI_COLOR_PURPLE<< "\n\t\t--------------------------------------------------\n\n"<<ANSI_COLOR_RESET;

                    bool verify = false;
                    static int count=3;
                    
                    do{
                        
                        verify = s[2]->LOGIN_VERIFY(); 				// CALLING THE EMPLOYEE LOGIN FUNCTION.
                        --count;					// DECRIMENTING THE COUNT BY 1.
                        
                        if(verify==true){
                            break;
                        }
                        else if(verify==false){
                            cout<<"\n WRONG CREDENTIALS PLEASE RE-ENTER THE USER NAME AND PASSWORD.\n";
                            cout<<"\n                      !!!  BE-AWARE !!!    \n";
                            cout<<"\t YOU ARE LEFT WITH ONLY  [ "<<count<<" ]  CHANCES.  \n\n";
                        }
                        if(count == 0){				// RESTRICTING TO ONLY THREE ATTEMPTS.
                            cout<<"n\t NO MORE CHANCE WILL BE ALLOCATED. \n\n";
                            break;
                        }
                        
                    }while(count>0);

                    if(verify){
                        s[2]->MAIN_MENU();
                    }
                    else{
                        cout<<"\n\t\t------------------------------------------"; 
                        cout<<"\n\t\t|     >>>  VERIFICATION FAILED   <<<     |";
                        cout<<"\n\t\t------------------------------------------\n\n";
                    
                    break;
                    }
                }
                break;
                case '4':
                {       	
                    // loading_line();				// CALLING THE LOADING LINE FUNCTION.
                    
                    cout<< ANSI_COLOR_ORANGE<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
                    cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"          ** TERMINATING THE PROGRAM ** "<<"|\n";
                    cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"             && THANKS FOR COMING && "<<"|\n";
                    cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"                     GOOD_BYE"<<"|\n";
                    cout<< ANSI_COLOR_ORANGE<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET<<endl<<endl;
                
                    return 0;
                }
                break;
                default:
                {
                    cout<<"\t -"<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
                    cout<<"\n\t !!!!!!!  ENTER A VALID INPUT  !!!!!!! \n";
                    cout<<"\t -"<<setfill('-')<<setw(40)<<"-"<<setfill(' ')<<endl;
                }
                break;

            }
        
    
            cout<< "\n\t\t--------------------------------------------------"; 
            cout<< "\n\t\t|  DO YOU WANT TO TERMINATE THE PROGRAM [ Y/N ]  |";
            cout<< "\n\t\t--------------------------------------------------\n\n";
        
            cin>>exit;

            if(exit=='y' || exit=='Y')
            {
                cout<< ANSI_COLOR_ORANGE<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<endl;
                cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"          ** TERMINATING THE PROGRAM ** "<<"|\n";
                cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"             && THANKS FOR COMING && "<<"|\n";
                cout<< ANSI_COLOR_ORANGE<<"\t\t | "<<setw(48)<<left<<"                     GOOD_BYE"<<"|\n";
                cout<< ANSI_COLOR_ORANGE<<"\t\t -"<<setfill('-')<<setw(50)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET<<endl<<endl;
                
                
                return 0;
            }
            else if(exit=='n' || exit=='N'){
                cout<<"\n ******* SELECT THE FUNCTION YOU WANT TO PERFORM AGAIN ******* \n\n";
            }
            
        }
	
    }while(1);


    //*DELETE THE ALLOCATED MEMORY.*//
    delete[] s;


return 0;
}

