/////////////////////////////// *{ ALL GAME FUNCTIONS DEFINED HERE. }* //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "header.h"

//*EXTRA FUNCTION.*//
void Play_Games()
{

	char choice;
	srand(time(NULL));
	
    do{
        
        cout<<"\n\t\t------------------------------------------"; 
        cout<<"\n\t\t|   ** [ WELCOME TO THE GAME BAR. ] **   |";
        cout<<"\n\t\t------------------------------------------\n\n";
        
        buttons();				// CALLING THE BUTTONS FUNCTION.
        
        cout<<"\t -"<<setfill('-')<<setw(36)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(34)<<left<<" >>> [ SELECT THE GAME ] <<< "<<"|\n";
        cout<<"\t | "<<setw(34)<<left<<" [1]. PLAY TIK-TAK-TOE. "<<"|\n";
        cout<<"\t | "<<setw(34)<<left<<" [2]. PLAY WHACK THE MOLE. "<<"|\n";
        cout<<"\t | "<<setw(34)<<left<<" [3]. GUESS THE NUMBER. "<<"|\n";
        cout<<"\t | "<<setw(34)<<left<<" [4]. QUIT. "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(36)<<"-"<<setfill(' ')<<endl;
        
        cin>>choice;
        
        loading_line();				// CALLING THE LOADING LINE FUNCTION.

        switch(choice)
        {      
            case '1':
            {
                TIK_TAK_TOE();
            
            break;
            }       
            case '2':
            {
                whack_a_mole();
            
            break;
            }     
            case '3':  
            {  
                Guess_The_NUM();
            break;
            }
            default:
            {    
                cout<<"\n\t\t-------------------------------------------"; 
                cout<<"\n\t\t|  >>  RE-DIRECTING TO THE GAME BAR  <<   |";
                cout<<"\n\t\t-------------------------------------------\n\n";
                
                //Play_Games(); 		// CALLING THE GAME FUNCTION.[ip validation]
            }
        
        }
            
        char exit;
        
        cout<<"\n\t\t------------------------------------------"; 
        cout<<"\n\t\t|  DO YOU WANT TO PLAY AGAIN ?  [ Y/N ]  |";
        cout<<"\n\t\t------------------------------------------\n\n";
        
        cin>>exit;
        if(exit=='n' || exit=='N'){

            cout<<"\t -"<<setfill('-')<<setw(37)<<"-"<<setfill(' ')<<endl;
            cout<<"\t | "<<setw(35)<<left<<"   [ ****** GAME ENDED ****** ] "<<"|\n";
            cout<<"\t | "<<setw(35)<<left<<" REDIRECTING TO THE SELECTION MENU "<<"|\n";
            cout<<"\t | "<<setw(35)<<left<<"            GOOD BYE ! "<<"|\n";
            cout<<"\t -"<<setfill('-')<<setw(37)<<"-"<<setfill(' ')<<endl;
        
        break;
        }
        else if(exit=='y' || exit=='Y'){

            cout<<"\n ******* SELECT THE GAME YOU WANT TO PLAY AGAIN ******* \n";	
        }

    }while(1);

return;
}

//////////////////////////////////////////[*WHACK-THE MOLE GAME FUNCTION.*]///////////////////////////////////////

//*FUNCTION TO GENERATE RANDOM POSITION FOR THE MOLE.*//
void random_mole_position(int& moleRow, int& moleCol , int ROWS , int COLS){
    moleRow = rand() % ROWS;
    moleCol = rand() % COLS;
}

//*DISPLAY THE BOARD FUNCTION.*//
void Display(char board[][4], int moleRow, int moleCol , int ROWS , int COLS) {
    for(int i=0 ; i<ROWS ; i++){
        cout<<"\t";
        for(int j=0 ; j<COLS ; j++)
        {
            if(i == moleRow && j == moleCol){
                cout<<"  "<<"M";
            }else{
                cout<<"  "<<board[i][j];
            }
        }
        cout<<endl;
    }
}


//*WHACK-THE MOLE GAME FUNCTION.*//
void whack_a_mole()
{

    cout<<"\n\t\t---------------------------------------------"; 
    cout<<"\n\t\t|  ** [ WELCOME TO TICK-TACK-TOE GAME ] **  |";
    cout<<"\n\t\t---------------------------------------------\n\n";

    cout<<"\n\t\t----------------------------------------------"; 
    cout<<"\n\t\t|  ** [ WELCOME TO WHACK-THE-MOLE GAME ] **  |";
    cout<<"\n\t\t----------------------------------------------\n\n";

    srand(time(NULL)); // seed random number generator.

    const int ROWS = 4, COLS = 4;
    const int MAX_ATTEMPTS = 5;
    int chance = 2;

    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){

            board[i][j] = '-';
        }
    }

    int mole_Row, mole_Col;
    random_mole_position(mole_Row, mole_Col, ROWS, COLS);

    int score = 0;
    int round = 0;

    cout<<"\n WELCOME TO { WHACK-A-MOLE!! } \n\n";

    while(chance && round < MAX_ATTEMPTS)
    {

        cout<<"\n ATTEMPT =   [" << round + 1 << "]  &  SCORE  =  [" << score << "]  \n";
        cout<<" REMAINING FAILED CHANCES  =  [" << chance << "]\n\n";

        Display(board, mole_Row, mole_Col, ROWS, COLS); //*CALLING THE DISLAY FUNCTION.*//

        int row, col;
        cout << "\nENTER THE ROW = ";
        cin >> row;
        row -= 1;
        while (row < 0 || row > ROWS){      //*validating input*//

            cout << "\nINVALID ROW ENTERED. TRY AGAIN: ";
            cin >> row;
        }

        cout << "\nENTER THE COL = ";
        cin >> col;
        col -= 1;
        while (col < 0 || col > COLS){      //*validating input*//
            cout << "\nINVALID COL ENTERED. TRY AGAIN: ";
            cin >> col;
        }

        if(row == mole_Row && col == mole_Col){

            cout << "\n $${ YOU HIT THE MOLE! }$$ \n";
            ++score;
            random_mole_position(mole_Row, mole_Col, ROWS, COLS); //*generating new random position for the mole.*//
        }
        else{

            cout << "\n ##{ YOU MISSED THE MOLE! }## \n";
            --score;
            --chance;
        }

        ++round; // incrimenting the rounds.
    }

    cout << "\n [GAME OVER]. YOUR FINAL SCORE IS  =  [" << score << "] \n";
}

///////////////////////////////////[[*GUESS THE NUMBER GAME FUNCTION.*]]///////////////////////////////////

void Guess_The_NUM(){
    cout<<"\n\t\t------------------------------------------------"; 
    cout<<"\n\t\t|  ** [ WELCOME TO GUESS THE NUMBER GAME ] **  |";
    cout<<"\n\t\t------------------------------------------------\n\n";

    int num1= (rand()%10);
    int num2= (rand()%10);
    int num3= (rand()%10);
    int a, b, c;

    cout<<"\n * GUESS THE FIRST NUMBER BETWEEN   [ 1-9 ]  >>> ::  ";
    cin>>a;
    cout<<"\n * GUESS THE SECOND NUMBER BETWEEN  [ 1-9 ]  >>> ::  ";
    cin>>b;
    cout<<"\n * GUESS THE THIRD NUMBER BETWEEN   [ 1-9 ]  >>> ::  ";
    cin>>c;

    if( (a>=0 && a<=9) && (b>=0 && b<=9) && (c>=0 && c<=9) )
    {
        if( (a==num1)&&(b==num2)&&(c==num3) ){

            cout<<"\n\t\t---------------------------------------------------------------------"; 
            cout<<"\n\t\t|  * [ ALL THE NUMBERS ARE MATCHING IN EXACTALLY THE SAME ORDER.] * |";
            cout<<"\n\t\t---------------------------------------------------------------------\n\n";
        }
        else if( ( (a==num2) && (b==num3) && (c==num1) ) ||
                ( (a==num3) && (b==num1) && (c==num2) )    ){

            cout<<"\n\t\t-------------------------------------------------------------------"; 
            cout<<"\n\t\t|  * [ ALL THE NUMBERS ARE MATCHING BUT NOT IN THE SAME ORDER.] * |";
            cout<<"\n\t\t-------------------------------------------------------------------\n\n";
        }
        else if( ( (a==num1) && (b==num2) ) ||
                ( (a==num2) && (b==num1) ) ||
                ( (a==num1) && (c==num3) ) ||
                ( (a==num3) && (c==num1) ) ||
                ( (b==num3) && (c==num3) ) ||
                ( (b==num3) && (c==num2) ) ||
                ( (b==num1) && (c==num3) ) ||
                ( (b==num2) && (c==num1) ) ||
                ( (b==num2) && (c==num3) )    ){

            cout<<"\n\t\t-------------------------------------------------"; 
            cout<<"\n\t\t|  * [ ANY OF THE TWO NUMBERS ARE MATCHING. ] * |";
            cout<<"\n\t\t-------------------------------------------------\n\n";
        }
        else if( (a==num1) || (b==num1) || (c==num1) ||
                (a==num2) || (b==num2) || (c==num2) ||
                (a==num3) || (b==num3) || (c==num3)    ){

            cout<<"\n\t\t-----------------------------------------"; 
            cout<<"\n\t\t|  * [ ONLY ONE NUMBER IS MATCHING. ] * |";
            cout<<"\n\t\t-----------------------------------------\n\n";
        }
        else{

            cout<<"\n\t\t-------------------------------------------------------------"; 
            cout<<"\n\t\t|  * [ NO MATCH FOUND. POOR LUCK. BTW YOU CAN TRY AGAIN.] * |";
            cout<<"\n\t\t-------------------------------------------------------------\n\n";
        }

    }
    else{
        cout<<"\n\t\t--------------------------------------\n";
        cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
        cout<<"\t\t----------------------------------------\n";
    }

return;
}


///////////////////////// *[[TIK-TAK-TOE SUB FUNCTIONS.]]* ////////////////////////////////


//*PRINT_BOARD FUNCTION*//
void Print_Board(char board[3][3]);

//*CHECK IF THE PLAYER_WIN FUNCTION*//
bool Check_Win(char board[3][3], char player);

//*CHECK IF THE BOARD IS FULL FUNCTION*//
bool CHECK_BOARD(char board[3][3]);


//*[MAIN GAME FUNCTION {TIK-TAK-TOE}]*//
void TIK_TAK_TOE(){

    char board[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';          //FILL THE BOARD WITH SPACES.
        }
    }

    char player = 'A';

    char exit;
    bool yes = true;

    while(yes){

    while(true){
    
        Print_Board(board);     //PRINT THE BOARD SITUATION.

        // Get the player's move
        int row, col;
        cout<<" PLAYER =  { "<<player<<" } \n >> ENTER YOUR MOVE [ROW & COLUMN ] \n";

        int arr[3][3] = {0};
        int count = 0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                cout<<" [ "<<i<<","<<j<<"]    ";
            }
            cout<<endl;
        }
        cout<<"\n\t ENTER THE ROW = "<<endl;
        cin>>row;
        cout<<"\n\t ENTER THE COLUMN = "<<endl;
        cin>>col;

        // Check if the chosen cell is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout<<"\n INVALID MOVE.... ENTER THE CORRECT MOVE. "<< endl;
            continue;
        }

        board[row][col] = player;    // place the player id to that position.

        if (Check_Win(board, player)){      //CHECK IF THERE IS A MATCH FOR [3 ROWS & COLS]

            Print_Board(board);
            cout<<"\n  ------------------------";
            cout<<"\n | PLAYER  { "<<player<<" } WINS. |";
            cout<<"\n  ------------------------\n";
        
        break;
        }

        if(CHECK_BOARD(board)){     //IF THE BOARD IS FULL AND NO MATCH IS FOUND...

            Print_Board(board);
            cout<<"\n  -------------";
            cout<<"\n | IT'S A TIE. |"<<endl;
            cout<<"\n  -------------\n";
            break;
        }

        player = (player == 'A') ? 'B' : 'A';       //SWITCH THE ROLE[PLAYER]
    }

    cout<<"\n DO YOU WISH TO PLAY AGAIN? (Y/N) ";
    cin>>exit;
        cout<<"--------------------------------"<<endl;
        if(exit == 'Y' || exit == 'y'){
            yes = true;

            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    board[i][j] =' ';
                }
            }
        }else{
            yes = false;
        }
    
    }

return;
}

///////*[ DEFINITIONS OF FUNCTIONS. ]* ////////

//*PRINT_BOARD FUNCTION*//
void Print_Board(char board[3][3]){

    cout<<"\n\t GAME BOARD ::>> "<<endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<"\t"<<board[i][j]<<"  |  ";
        }
        cout<<endl;
        cout<<"\t----------------------\n";
    }
    cout<<endl;

return;
}

//*CHECK IF THE PLAYER_WIN FUNCTION*//
bool Check_Win(char board[3][3], char player) {
    
    //  CHECKING ROWS AND COLONNS FOR A MATCH.
    for(int i = 0; i<3 ; ++i)
    {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }

    // CHECKING FOR DIAGONALS [] LEFT TO RIGHT ... RIGHT TO LEFT ...
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

return false;
}

///////*[ FUNCTION TO CHECK IF THE BOARD IS FULL. IF FULL ** TIE ** ] * //////
bool CHECK_BOARD(char board[3][3])
{
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(board[i][j] == ' '){

                return false;
            }
        }
    }

return true;
}


