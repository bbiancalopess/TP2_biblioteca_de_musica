#include <iostream>
#include "../../include/system/System.hpp"
#include "../../include/system/csv.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <System.hpp>

using std::vector;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;
using std::cerr;
using std::endl;
using std::cout;
using std::cin;

string System::login(string email, string password) {
    try {
        Csv* file = new Csv();
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        for (const auto& row : data) {
            if (row[2] == email) {
                if (row[3] == password) {
                    return "loged";
                } else {
                    return "wrong password";
                }
            }
        }

        return "not registered";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }

}

                
                

string getNextId(){
    try {
        Csv* arquivo = new Csv();

        vector<vector<string>> users = arquivo->readCSV("../csv/users.csv");

        return to_string(stoi(users[users.size() - 1][0]) + 1);
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }

}

string signUp(string name, string email, string password, string userType) {
    try {
        Csv* file = new Csv();
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        vector<string> newData = {getNextId(), name, email, password, userType};

        data.push_back(newData);

        file->writeCSV("../csv/users.csv", data);

        return "cadastrado";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }   

}

string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}





void signUpInfo() {
    string name = getInput("Digite seu nome: ");
    string email = getInput("Digite seu email: ");
    string password = getInput("Digite sua senha: ");
    string userType;
    while(userType != "ouvinte" && userType != "artista"){
        userType = getInput("Digite o tipo de usuário (ouvinte ou artista): ");
    }
    string result = signUp(name, email, password, userType);
    if (result == "cadastrado") {
        cout << "Cadastrado com sucesso!" << endl;
    }

}

void System::startTheSystem() {
    string opcao;

    string inicio = "--------------------------------------------------\n";
    inicio += "-------- ESSA É SUA BIBLIOTECA DE MÚSICAS --------\n";
    inicio += "--------------------------------------------------\n\n";
    inicio += "-------------- VOCÊ JÁ É UM USUÁRIO? -------------\n\n";
    inicio += "1. Sim, quero fazer log-in!\n";
    inicio += "2. Não, quero me cadastrar!\n";
    cout << inicio << endl;
    
    opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();
    // PRECISA VERIFICAR SE A OPÇÃO DIGITADA EXISTE, SE NÃO EXISTIR DEIXAR UM ALERTA DE QUE NÃO EXISTE E VOLTAR COM O DISPLAY INICIAL
    

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    while (true) {
        try {
            if (W == 1) {
                signUpInfo();
            } else if (W == 2) {
                string email = getInput("Digite seu email: ");
                string password = getInput("Digite sua senha: ");
                string result = login(email, password);
            }
        } catch (const runtime_error& err) {
            cerr << err.what() << endl;
        }
    } // Add this closing brace

    inicio += "-------- BEM-VINDO/A! --------\n";
    inicio += "--------------------------------------------------\n\n";
    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Pesquisar uma musica!\n";
    inicio += "2. Pesquisar álbum\n";
    inicio += "2. Pesquisar artista!\n";
    inicio += "2. Ver suas Playlists!\n";
    inicio += "2. Ver artistas seguidos!\n";

    cout << inicio << endl;
    
    opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    try {
            int W = 0;
            string album;
            string artista;
            string musica;
            string playlist;

            switch (W) {

                try {
                    W = stoi(opcao); // string to int
                } catch (...) {
                    cout << "Entrada inválida \n";
                }

                case 1:
                    
                    musica = getInput("Digite o nome da música: ");

                    // Pesquisar uma musica
                    
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Tocar música!\n";
                    inicio += "2. Adicionar música na playlist!\n";
                    cout << inicio << endl;

                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }

                    switch (W) {
                        case 1:
                            // Tocar música
                            break;
                        case 2:
                            // Adicionar música na playlist
                            break;
                        default:
                            cout << "Entrada inválida \n";
                            break;
                    }
                    
                    break;
                case 2:
                    
                    album = getInput("Digite o nome do álbum: ");

                    // Pesquisar álbum

                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Tocar álbum inteiro!\n";
                    inicio += "2. Adicionar álbum na playlist!\n";
                    cout << inicio << endl;

                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }

                    switch (W) {
                        case 1:
                            // Tocar álbum inteiro
                            break;
                        case 2:
                            // Adicionar álbum na playlist
                            break;
                        default:
                            cout << "Entrada inválida \n";
                            break;
                    }
                    break;
                case 3:

                    
                    artista = getInput("Digite o nome do artista: ");
                    // Pesquisar artista
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Tocar todas as músicas do artista!\n";
                    inicio += "2. Seguir artista!\n";
                    cout << inicio << endl;
    
                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }

                    switch (W) {
                        
                        case 1:
                            // Tocar todas as músicas do artista
                            break;
                        case 2:
                            // Seguir artista
                            break;
                        default:
                            cout << "Entrada inválida \n";
                            break;
                    }

                    break;
                case 4:
                
                    // Ver suas Playlists
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Tocar Playlist desejada!\n";
                    inicio += "2. Remover musica da Playlist desejada!\n";
                    inicio += "3. Renomear Playlist desejada!\n";
                    inicio += "4. Remover Playlist desejada!\n";
                    
                    cout << inicio << endl;
    
                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }

                    switch (W) {
                        case 1:
                            // Tocar Playlist desejada
                            break;
                        case 2:
                            // Remover musica da Playlist desejada
                            break;
                        case 3:
                            // Renomear Playlist desejada
                            break;
                        case 4:
                            // Remover Playlist desejada
                            break;
                        default:
                            cout << "Entrada inválida \n";
                            break;
                    }

                    break;
                case 5:
                    // Ver artistas seguidos
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Ouvir artista desejado!\n";
                    inicio += "2. Deixar de seguir artista desejado!\n";
                    
                    cout << inicio << endl;
    
                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }
                    break;

                    if (W == 1) {
                        // Ouvir artista desejado
                    } else if (W == 2) {
                        // Deixar de seguir artista desejado
                    } else {
                        cout << "Entrada inválida \n";
                    }
                    break;
                    
                default:
                    cout << "Entrada inválida \n";
                    break;
            }
        } catch (const runtime_error& err) {
            cerr << err.what() << endl;
    }
}

        
    
