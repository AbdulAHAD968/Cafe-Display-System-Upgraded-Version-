///////////////////////////////////// [ ACCESS TO BUILT-IN LIBRARIES ] //////////////////////////////////////////////////////

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cmath>
#include <chrono>
#include <thread>
#include <string>

/////////////////////////////////////

using namespace std;

//////////////////////////////////// [ ACCESS TO LOCAL-HEADERS DEFINED BY ME ] //////////////////////////////////////// 


#include "sales_header.h"
#include "GAMES.h"
#include "track_sales_header.h"
#include "inventory_header.h"

////////////////////////////////////////// *[ LINUX-LIBRARIES FOR COLORS ]* //////////////////////////////////////////


#define ANSI_COLOR_RESET        "\x1b[0m "
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BLUE         "\033[34m"
#define ANSI_COLOR_ORANGE       "\033[38;5;208m"
#define ANSI_COLOR_PINK         "\033[38;5;205m"
#define ANSI_COLOR_PURPLE       "\033[38;5;165m"
#define ANSI_COLOR_DARK_GREEN   "\033[38;5;22m"
#define CLEAR_SCREEN            "\x1B[2J\x1B[H"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void loading_line();			// LOADING LINE FUNCTION. [ IN main.CPP]

void clearScreen();			    // CLEAR SCREEN FUNCTION

void update_Product(char** iT_Name, double Price[], int No_Items[], double Total_Price[], int index,
                   const char* newName, double newPrice, int newQuantity, double newTotalPrice);

void new_user();                // unsigned user.


//*FOR ENCRYPTION AND DECRYPTION OF ADMIN PASSWORD.*//
string Xor_Cipher(const string& text, const string& key);