#include "header.h"


//*CONSTRUCTOR.*//
Users :: Users(string user_name , string user_password){
    this->user_name = user_name;
    this->user_password = user_password;
}


//*I-STREAM VIRTUAL FRIEND FUNCTION.*//
istream& operator>>(istream& is, Users& obj){

    cout<<"\n ENTER YOUR [NAME]  =  ";
    is>>obj.user_name;
    cout<<"\n ENTER YOUR [PASSWORD]  =  ";
    is>>obj.user_password;

return is;
}