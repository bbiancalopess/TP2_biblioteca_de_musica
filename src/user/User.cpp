#include "../../include/user/User.hpp"

// contrutor
User::User(int id, string name, string email, string password, string userType) 
    : id(id), name(name), email(email), password(password), userType(userType){}

// getters e setter
int User::getId() {
    return ;
}

string User::getName() {
    return this->name;
}

void User::setName(string name) {
    this->name = name;
}

string User::getEmail() {
    return this->email;
}

void User::setEmail(string email) {
    this->email = email;
}

string User::getPassword() {
    return this->password;
}

void User::setPassword(string password) {
    this->password = password;
}

// métodos
void User::logout(){

}

