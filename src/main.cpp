#include <iostream>
#include <string>
#include <User.hpp>
#include <Artist.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::string;


string get_input(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}




int main() {

    string entrada = get_input("Digite algo: ");
    int W = 0;
    try {
        W = stoi(entrada); // string to int
    } catch (...) {
        cout << "Invalid input. Please enter a number.\n";
    }
    



    while (true) {
        
        try {
            
            switch (W)
            {
            case 1: //criar usuario
            
                
                    int id = 0;
                    string nome;
                    string email;
                    string senha;
            
                    nome = get_input("Digite seu nome: ");
                    email = get_input("Digite seu email: ");
                    senha = get_input("Digite sua senha: ");
            
                    User user(id, nome, email, senha);
                    addUser(user);
                
            
                break;

            case 2: //remover usuario

                string nome = get_input("Digite o nome do usuario que deseja remover: ");
                removeUser(nome);
                break;

            case 3: //listar usuarios
                listUsers();
                break;
            
            case 4: //remover todos os usuarios
                removeAllUsers();
                break;
            
            case 5: //criar artista

                

            
                


            default:
                break;
            }
        }
    }

    return 0;
}