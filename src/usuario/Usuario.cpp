#include "../../include/usuario/Usuario.hpp"

// contrutor
Usuario::Usuario(int id, string nome, string email, string senha) 
    : id(id), nome(nome), email(email), senha(senha) {}

// getters e setter
int Usuario::getId() {
    return this->id;
}

string Usuario::getNome() {
    return this->nome;
}

void Usuario::setNome(string nome) {
    this->nome = nome;
}

string Usuario::getEmail() {
    return this->nome;
}

void Usuario::setEmail(string email) {
    this->email = email;
}

string Usuario::getSenha() {
    return this->senha;
}

void Usuario::setSenha(string senha) {
    this->senha = senha;
}

// métodos
void Usuario::logout(){

}