/////////////////////////////// *{ WHOLE CREDENTIALS CLASS DEFINED HERE. }* /////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "header.h"


//*I-STREAM FRIEND FUNCTION TO TAKE INPUT.*//
istream& operator >> (istream& in , Credentials& obj){
    cout<<"\n ENTER THE USERNAME : ";
    in>>obj.compare_1;
    cout<<"\n ENTER THE PASSWORD : ";
    in>>obj.compare_2;

return in;
}



//*ACCESS TO THE [FILES OF ADMIN NAME AND PASS DATA.]*//
int Credentials::ADMIN_VERIFICATION() 
{
    
    string admin;
    string password;
    bool login = false;
    static int count = 3 ;

    do{
        
        cout<<"\n\t\t---------------------------------------------------\n";
		cout<<"\t\t|   !!!! LET US MAKE SURE THAT WHO YOU ARE ?  !!!!  |\n";
        cout<<"\t\t|   BECAUSE THIS SITE IS MEANT ONLY FOR THE ADMIN.  |\n";
		cout<<"\t\t-----------------------------------------------------\n";
	
        cout<<"\n ENTER THE ADMIN NAME : ";
        cin>>compare_1;
        cout<<"\n ENTER THE ADMIN PASSWORD : ";
        cin>>compare_2;

        string decrypted_name = Xor_Cipher(compare_1, "key");
        string decrypted_password = Xor_Cipher(compare_2, "key");

        ifstream f("admin_pass.txt");				// OPENING FILE IN READING MODE.

        while(!f.eof() ){							// VERIFICATION PROCESS.

            f>>admin>>password;
            if( admin == decrypted_name && password == decrypted_password ){
                login = true;
                cout<<"\n ****** VERIFICATION COMPLETED ***** \n\n";
                break;
            }

        }
        
        f.close();					// CLOSING FILE TO PREVENT CORRUPTION.
        --count;					// DECRIMENTING THE COUNTER EACH TIME.
        
        if(count == 0 ){					// RESTRICTING TO ONLY THREE ATTEMPTS.
        	cout<<"n\t NO MORE CHANCE WILL BE ALLOCATED. \n\n";
        	return 0;
        }
        
        if(login==false){

            cout<<"\n WRONG CREDENTIALS PLEASE RE-ENTER THE ADMIN NAME AND PASSWORD.\n";
            cout<<"\n                      !!!  BE-AWARE !!!    \n";
            cout<<"\t YOU ARE LEFT WITH ONLY  [ "<<count<<" ]  CHANCES.  \n";
        }
        
    }while(!login);

return 1;
}



//*ACCESS TO THE [FILES OF ADMIN NAME AND PASS DATA.]*//
int Credentials::ADMIN_VERIFICATION_1() 
{
    bool login = ADMIN_VERIFICATION();
	
	if(login == true){

        cout<<"\n\t\t---------------------------------------------\n";
        cout<<"\t\t|   ### YOU NOW HAVE ACCESS TO THE DATA ####  |\n";
        cout<<"\t\t|   NOTE THAT THESE FILES ARE CONFIDENTIAL.   |\n";
        cout<<"\t\t-----------------------------------------------\n";
        
        chrono::seconds sleepDuration(2);
        // FOR MAKING THE PROGRAM SLEEP.
        Sleep(2000);         //WINDOWS API.

        const int size = 30;
        char name[20][size];				// FOR READING FILE DATA.
        char pass[20][size];
        
        int i=0;
        
        ifstream o("admin_pass.txt" );		// OPENING FILE IN READING MODE.
        if(!o){
            cout<<"\n FILE NOT FOUND. \n";
            cout<<" CHECK THE FILE NAME.";
        }
        
        cout<<"\n\n\t\t | "<<"-----------------"<<" | "<<endl;
        while( o>>name[i]>>pass[i] ){	 			// POPULATING THE ARRAY DATA.

            cout<<"\t\t | "<<name[i]<<"    "<<pass[i] <<endl;
            cout<<"\t\t | "<<"-----------------"<<" | "<<endl;
            i++ ;	
        }
        o.close();						// CLOSING FILE TO PREVENT CORRUPTION.

    }
    else{
        cout<<"\n ACCESS DENIED. \n";
        cout<<"\n PLEASE TRY AGAIN. \n";
        return 0;
    }

return 1;
}


//*ACCESS TO THE [FILES OF EMPLOYEE NAME AND PASS DATA.]*//
int Credentials::ADMIN_VERIFICATION_2() 
{
    bool login = ADMIN_VERIFICATION();
    
    if(login == true){

        cout<<"\n\t\t---------------------------------------------\n";
        cout<<"\t\t|   ### YOU NOW HAVE ACCESS TO THE DATA ####  |\n";
        cout<<"\t\t|   NOTE THAT THESE FILES ARE CONFIDENTIAL.   |\n";
        cout<<"\t\t-----------------------------------------------\n";
        
        // FOR MAKING THE PROGRAM SLEEP.
        Sleep(2000);         //WINDOWS API.

        const int size = 30;
        char name[20][size];				// FOR READING FILE DATA.
        char pass[20][size];
        
        int i=0;
        
        ifstream o("employee_pass.txt" );		// OPENING FILE IN READING MODE.
        if(!o){
            cout<<"\n FILE NOT FOUND. \n";
            cout<<" CHECK THE FILE NAME.";
        }
        
        cout<<"\n\n\t\t | "<<"-----------------"<<" | "<<endl;
        while( o>>name[i]>>pass[i] ){	 			// POPULATING THE ARRAY DATA.

            cout<<"\t\t | "<<name[i]<<"    "<<pass[i] <<endl;
            cout<<"\t\t | "<<"-----------------"<<" | "<<endl;
            i++ ;	
        }
        o.close();						// CLOSING FILE TO PREVENT CORRUPTION.

    }
    else{
        cout<<"\n ACCESS DENIED. \n";
        cout<<"\n PLEASE TRY AGAIN. \n";
        return 0;
    }

return 1;   
}


//*ACCESS TO THE [FILES OF CUSTOMER NAME AND PASS DATA.]*//
int Credentials::ADMIN_VERIFICATION_3() 
{
    bool login = ADMIN_VERIFICATION();
    
    if(login == true){

        cout<<"\n\t\t---------------------------------------------\n";
        cout<<"\t\t|   ### YOU NOW HAVE ACCESS TO THE DATA ####  |\n";
        cout<<"\t\t|   NOTE THAT THESE FILES ARE CONFIDENTIAL.   |\n";
        cout<<"\t\t-----------------------------------------------\n";
        
        // FOR MAKING THE PROGRAM SLEEP.
        Sleep(2000);         //WINDOWS API.

        const int size = 30;
        char name[20][size];				// FOR READING FILE DATA.
        char pass[20][size];
        
        int i=0;
        
        ifstream o("user_pass.txt" );		// OPENING FILE IN READING MODE.
        if(!o){
            cout<<"\n FILE NOT FOUND. \n";
            cout<<" CHECK THE FILE NAME.";
        }
        
        cout<<"\n\n\t\t | "<<"-----------------"<<" | "<<endl;
        while( o >> name[i] >> pass[i]  ){	 			// POPULATING THE ARRAY DATA.

            cout<<"\t\t | "<<name[i]<<"    "<<pass[i] <<endl;
            cout<<"\t\t | "<<"-----------------"<<" | "<<endl;
            i++ ;	
        }
        o.close();						// CLOSING FILE TO PREVENT CORRUPTION.

    }
    else{
        cout<<"\n ACCESS DENIED. \n";
        cout<<"\n PLEASE TRY AGAIN. \n";
        return 0;
    }

return 1;   
}


/////////// [* CHANGE CREDENTIALS-FOR ALL *] ////////////
void Credentials::Change_Credentials()
{
	char choice;
        	                
    buttons();				// CALLING THE BUTTONS FUNCTION.
                
    cout<<"\t\t -"<<setfill('-')<<setw(34)<<"-"<<setfill(' ')<<endl;
    cout<<"\t\t | "<<setw(33)<<left<<"[ WHAT DO YOU WANT TO CHANGE ? ] "<<"|\n";
    cout<<"\t\t | "<<setw(33)<<left<<" 1. YOUR OWN NAME/PASS. "<<"|\n";
    cout<<"\t\t | "<<setw(33)<<left<<" 2. EMPLOYEE NAME/PASS. "<<"|\n";
    cout<<"\t\t | "<<setw(33)<<left<<" 3. STUDENT_STAFF NAME/PASS . "<<"|\n";
    cout<<"\t\t | "<<setw(33)<<left<<" 4. EXIT. "<<"|\n";
    cout<<"\t\t -"<<setfill('-')<<setw(34)<<"-"<<setfill(' ')<<endl;
    cin>>choice;
        
    loading_line();				// CALLING THE LOADING LINE FUNCTION.

    switch(choice)
    {
        case '1':
        {    
            int x;
            x=ADMIN_VERIFICATION_1();
            
            if(x==1){
                
                Change_Admin_Credentials();
            }
            else{	
                
                cout<<"\n\t\t -------------------------";
                cout<<"\n\t\t| CANNOT GRANT ACCESS BCZ.|";
                cout<<"\n\t\t|  YOU ARE NOT THE ADMIN. |";
                cout<<"\n\t\t|_________________________|";
                return;
            }
        }                               
        break;
        case '2':
        {	
            int y;
            y=ADMIN_VERIFICATION_2();
            
            if(y==1){ 
                Change_Employee_Credentials();
            }
            else{
                
                cout<<"\n\t\t -------------------------";
                cout<<"\n\t\t| CANNOT GRANT ACCESS BCZ.|";
                cout<<"\n\t\t|  YOU ARE NOT THE ADMIN. |";
                cout<<"\n\t\t|_________________________|";
                
                return;
            }
        }	
        break;
        case '3':
        {	
            int z;
            z=ADMIN_VERIFICATION_3();
            
            if(z==1){
                
                Change_User_Credentials();
            }
            else{
                
                cout<<"\n\t\t -------------------------";
                cout<<"\n\t\t| CANNOT GRANT ACCESS BCZ.|";
                cout<<"\n\t\t|  YOU ARE NOT THE ADMIN. |";
                cout<<"\n\t\t|_________________________|";
                
            return;
            }
        }
        break;
        case '4':
        {	
            cout<< "\n\t\t-----------------------------------"; 
            cout<< "\n\t\t| >>   GOOD BYE FROM THIS SITE << |";
            cout<< "\n\t\t-----------------------------------\n\n";
        return;
        }
        break;
        default:
        {
            cout<<"\n\t\t--------------------------------------\n";
            cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
            cout<<"\t\t----------------------------------------\n";
            cout<<" DON'T BE WORRIED. WE ARE RE-DIRECTING YOU TO THE CHOICE MENU. \n";
            
            Change_Credentials();
            
        }

    }

return;
}


////////// {CHANGE ADMIN CREDENTIALS} ////////////
void Credentials::Change_Admin_Credentials()
{
	const int size = 30;	
	char* newPass = new char[size];
    char* newName = new char[size];
                
    char del;
    
    cout<<" DO YOU WANT TO CHANGE YOUR NAME AND PASSWORD ? \n";		// ASKING IF CHANGE DEMANDED.
    cout<<"\n ENTER [Y/y] FOR YES OR [N/n] FOR NO. \n";
    cin>>del;
                
    if(del=='Y' || del=='y'){

        //  RE-PLACING IT WITH THE NEW-NAME.    
        cin.ignore();
        cout<<"\n ENTER THE NEW ADMIN NAME >>> ";
        cin.getline( newName , size );

        cout<<"\n\n ENTER THE NEW ADMIN PASSWORD >>> ";
        cin.getline( newPass , size );
            
    
    }
    else if(del=='N' || del=='n'){

        cout<<"\n\n <<< YOU CAN DO THIS LATER AS WELL >>> \n";		// EXITTING WITHOUT CHANGING.
        return;
    }

    string decrypted_name = Xor_Cipher(newName , "key");
    string decrypted_password = Xor_Cipher(newPass , "key");

	ofstream write("admin_pass.txt", ios::out );			// WRITING THE SPECIFIC DATA BACK TO THE FILE.

    write<<decrypted_name<<" "<<decrypted_password<<endl;

    write.close();					// CLOSSING THE FILE TO PREVENT THE CORRUPTION.

    cout<< "\n\t\t----------------------------------------------"; 
    cout<< "\n\t\t| >> EITHER NAME OR PASSWORD WAS CHANGED. << |";
    cout<< "\n\t\t| >>   THE CHANGES HAVE ALSO BEEN SAVED.  << |";
    cout<< "\n\t\t----------------------------------------------\n\n";
    
    delete [] newPass;      //unallocate...
    delete [] newName;
    newPass = nullptr;      //undangle...
    newName = nullptr;
    
return;
}


////////// {CHANGE EMPLOYEE CREDENTIALS} /////////
void Credentials::Change_Employee_Credentials()
{
    
    const int size = 50;
    char employees[20][size];
    char passwords[20][size];
    
    bool login = false;
    
    char nameE[size];
    char passE[size];

    int n=0;

    ifstream read("employee_pass.txt" , ios::in );			// READING DATA FROM THE FILE AND STORING IT IN ARRAYS.
    
    while( read >> employees[n] >> passwords[n] ){
        read.ignore();
        n++;
    }
    
    read.close();				// CLOSING THE FILE TO PREVENT DATA CORRUPTION.

    do{
	
        cout<<"\n\n ENTER THE EMPLOYEE NAME: ";
        cin.ignore();
        cin.getline( nameE , size );
        
        cout<<" ENTER THE EMPLOYEE PASSWORD: ";
        cin.getline( passE , size );

        for(int i=0 ; i<n ; i++)			
        {
            if(strcmp(employees[i], nameE) == 0 && strcmp(passwords[i], passE) == 0)
            {
                login = true;
                
                cout<<"\n ****** VERIFICATI ON COMPLETED ***** \n\n";		// FLAG GREEN [PASSED].

                char newPass[size];
                char newName[size];
                
                char del;
                cout<<" DO YOU WANT TO CHANGE HIS/HER NAME AND PASSWORD ? \n";		// ASKING IF CHANGE DEMANDED.
                cout<<"\n ENTER [Y/y] FOR YES OR [N/n] FOR NO. \n";
                cin>>del;
                
                if(del=='Y' || del=='y'){

                	cin.ignore();
                	cout<<"\n ENTER THE NEW NAME OF THAT EMPLOYEE >>> ";
                	cin.getline( newName , size );

                	cout<<"\n\n ENTER THE NEW PASSWORD >>> ";
                	cin.getline( newPass , size );
	
                	strcpy(employees[i] , newName );		// COPYING THE DATA OF THE NEW ARRAY.
                	strcpy(passwords[i] , newPass );	// 1st ARRAY COPY THE DATA OF THE 2nd ARRAY.
                	
                	break;
                }
                else if(del=='N' || del=='n'){

                	cout<<"\n\n\t <<< YOU CAN DO THIS LATER AS WELL >>> \n";		// EXITTING WITHOUT CHANGING.
                	cout<<"\n\t          <<<<  خدا حافظ  >>>>  \n\n";
                	return;
                }
                else{

                	cout<<"\n\t\t--------------------------------------\n";
                    cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                    cout<<"\t\t----------------------------------------\n";
                	break;
                }

            }
        }
        if(!login){				// VALIDATING THE USERNAME - PASS.
            
            cout<<"\n WRONG CREDENTIALS. PLEASE RE-ENTER THE EMPLOYEE NAME AND PASSWORD.\n";
            cout<<"\n PRESS ANY KEY TO CONTINUE >>> \n";
        }

    }while(!login);					// FLAG.

    ofstream write("employee_pass.txt" );			// WRITING THE SPECIFIC DATA OF INDEX BACK TO THE FILE.

    for(int i=0 ; i<n-1 ; i++){
        write<<employees[i]<<" "<<passwords[i]<<endl;
    }

    write.close();					// CLOSSING THE FILE TO PREVENT THE CORRUPTION.
    
    cout<< "\n\t\t----------------------------------------------"; 
    cout<< "\n\t\t| >> EITHER NAME OR PASSWORD WAS CHANGED. << |";
    cout<< "\n\t\t| >>   THE CHANGES HAVE ALSO BEEN SAVED.  << |";
    cout<< "\n\t\t----------------------------------------------\n\n";
    
return; 
}


////////// {CHANGE USER CREDENTIALS} ////////////
void Credentials::Change_User_Credentials()
{
	const int size = 30;
	char name[20][size];				// FOR READING FILE DATA.
	char pass[20][size];
	
	char nameU[size];				// FOR USER INPUT.
	char passU[size];
	
	int i=0;
	bool login = false;				// FLAG [RED]
	
	ifstream read("user_pass.txt" );		// OPENING FILE IN READING MODE.
	
	if(!read){

		cout<<"\n FILE NOT FOUND. \n";
		cout<<" CHECK THE FILE NAME.";
	}
	
	while( !read.eof() ){			// POPULATING THE ARRAY DATA.

		read >> name[i] >> pass[i]; 	
	 	read.ignore();
	 	i++ ;	
	}
	read.close();						// CLOSING FILE TO PREVENT CORRUPTION.
	
	do{
	
		cout<<" ENTER THE USER-NAME ::  ";
		cin.ignore();
		cin.getline( nameU , size );
		
		cout<<" ENTER THE USER-PASSWORD ::  ";
		cin.getline( passU , size );
		
		for(int j=0 ; j<i ; ++j)
		{					// COMPARING THE INPUT WITH FILE DATA.
					
            if( ( strcmp( name[j], nameU ) == 0) && ( strcmp( pass[j] , passU ) == 0 ) )
            {
                
                // FLAG[GREEN]
                login = true;
                
                cout<<"\n ****** VERIFICATION COMPLETED ***** \n\n";		// FLAG GREEN [PASSED].
                
                char newPass[size];
                char newName[size];
                char del;
                cout<<" DO YOU WANT TO CHANGE HIS/HER NAME AND PASSWORD ? \n";		// ASKING IF CHANGE DEMANDED.
                cout<<"\n ENTER [Y/y] FOR YES OR [N/n] FOR NO. \n";
                cin>>del;
            
                if(del=='Y' || del=='y')
                {
                    //  RE-PLACING IT WITH THE NEW-NAME.
                    
                    cin.ignore();
                    cout<<"\n ENTER THE NEW NAME OF THAT USER >>> ";
                    cin.getline( newName , size );

                    cout<<"\n\n ENTER THE NEW PASSWORD >>> ";
                    cin.getline( newPass , size );

                    strcpy(name[j] , newName );		// COPYING THE DATA OF THE NEW ARRAY.
                    strcpy(pass[j] , newPass );	// 1st ARRAY COPY THE DATA OF THE 2nd ARRAY.
                    
                    break;
                }
                else if(del=='N' || del=='n')
                {
                    cout<<"\n\n <<< YOU CAN DO THIS LATER AS WELL >>> \n";		// EXITTING WITHOUT CHANGING.
                    return;
                }
                else
                {
                    cout<<"\n\t\t--------------------------------------\n";
                    cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                    cout<<"\t\t----------------------------------------\n";
                    break;
                }

            }
        
        }

        if(!login){				// VALIDATING THE USERNAME - PASS.

            cout<<"\n WRONG CREDENTIALS. PLEASE RE-ENTER THE EMPLOYEE NAME AND PASSWORD.\n";    
        }

    }while(!login);					// FLAG.

    
    ofstream write("user_pass.txt" );			// WRITING THE SPECIFIC DATA OF INDEX BACK TO THE FILE.
    
    for (int k=0 ; k<i-1 ; k++ ){
        write<< name[k] <<" "<<pass[k] <<endl;
    }
    
    write.close();					// CLOSSING THE FILE TO PREVENT THE CORRUPTION.
    
    cout<< "\n\t\t----------------------------------------------"; 
    cout<< "\n\t\t| >> EITHER NAME OR PASSWORD WAS CHANGED. << |";
    cout<< "\n\t\t| >>   THE CHANGES HAVE ALSO BEEN SAVED.  << |";
    cout<< "\n\t\t----------------------------------------------\n\n";
    
return;		
}

