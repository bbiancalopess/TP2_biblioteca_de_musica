#include "User.hpp"

// contrutor
User::User(int id, string name, string email, string password, string userType) 
    : id(id), name(name), email(email), password(password), userType(userType){}

string User::checkUserType(){
    
    return this->userType;
}

// métodos
void User::logout(){

}

