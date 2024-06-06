#include "../../include/user/User.hpp"

// contrutor
User::User(int id, string name, string email, string password) 
    : id(id), name(name), email(email), password(password) {}

// getters e setter
int User::getId() {
    return this->id;
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