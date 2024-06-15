#include <iostream>
#include "../../include/system/System.hpp"
#include "../../include/system/csv.hpp"
#include "../../include/user/User.hpp"
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
        Csv* file; // instancia a classe CSV
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv"); // abre o arquivo

        for (const auto& row : data) { // pega linha a linha do arquivo
            if (row[2] == email) { // verifica se o email é igual ao da linha, se não for, passa para a linha seguinte e faz o mesmo
                if (row[3] == password) { // se o email for igual, verifica se a senha é igual
                    return "loged"; // se a senha for a certa, o usuário está logado
                } else {
                    return "wrong password"; // se a senha for diferente, a senha digitada está errada
                }
            }
        }

        return "not registered"; // caso o email não esteja no arquivo, o usuário não está cadastrado
    } catch (const runtime_error& err) {
        cerr << err.what() << endl; 
    }
}

string getNextId(){
    try {
        Csv* file; // instancia a classe CSV

        vector<vector<string>> users = file->readCSV("../csv/users.csv"); // lê o arquivo

        return to_string(stoi(users[users.size() - 1][0]) + 1); // pega o id da última linha do arquivo, sendo esse, o último cadastro
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

string signUp(string name, string email, string password, string userType) {
    try {
        Csv* file;
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        vector<string> newData = {getNextId(), name, email, password, userType};

        data.push_back(newData);

        file->writeCSV("../csv/users.csv", data);

        return "cadastrado";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }   

}

void System::getAllUsers() {
    try {
        Csv* file;
    
        vector<vector<string>> data = file->readCSV("../csv/users.csv");

        for (const auto& row : data) {
            this->users.push_back(new User(stoi(row[0]), row[1], row[2], row[3]));
        }
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

    this->getAllUsers();

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
    } 

    inicio += "-------- BEM-VINDO/A! --------\n";

    if (checkUserType() == "ouvinte" ){

    


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
    //artista ve as musicas que ele postou, ve os albuns que ele postou, publica musica, publica album, ve o numero de seguidores dele, ve o numero de ouvintes que ouviram suas musicas

    } else if (checkUserType() == "artista") {
        inicio += "--------------------------------------------------\n\n";
        inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
        inicio += "1. Ver suas músicas!\n";
        inicio += "2. Ver seus álbuns!\n";
        inicio += "3. Publicar música!\n";
        inicio += "4. Publicar álbum!\n";
        inicio += "5. Ver número de seguidores!\n";
        inicio += "6. Ver número de ouvintes que ouviram suas músicas!\n";

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
            string genre;
            string lyrics; 
            string duration; 

            switch (W) {

                try {
                    W = stoi(opcao); // string to int
                } catch (...) {
                    cout << "Entrada inválida \n";
                }

                case 1:
                    
                    // Ver suas músicas
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Ouvir música desejada!\n";
                    inicio += "2. Apagar música!\n";
                    
                    cout << inicio << endl;

                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }
                    
                    musica = getInput("Digite o nome da música: ");

                    try {
                        if (checkMusica(musica) == false) {
                            throw runtime_error("Música não encontrada");
                        }
                    } catch (const runtime_error& err) {
                        cerr << err.what() << endl;
                    }

                    if (W == 1) {

                        // ouvir musica desejada
                    } else if (W == 2) {
                        // Apagar música
                    } else {
                        cout << "Entrada inválida \n";
                    }
                    break;

                    
                case 2:
                    
                    // Ver seus álbuns
                    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
                    inicio += "1. Adicionar música no álbum!\n";
                    inicio += "2. Excluir álbum!\n";
                    
                    cout << inicio << endl;

                    opcao = getInput("Digite a opção de sua escolha: ");
                    clearScreen();

                    try {
                        int W = stoi(opcao); // string to int
                    } catch (...) {
                        cout << "Entrada inválida \n";
                    }
                    
                    album = getInput("Digite o nome do álbum: ");

                    try {
                        if (checkAlbum(album) == false) {
                            throw runtime_error("Álbum não encontrado");
                        }
                    } catch (const runtime_error& err) {
                        cerr << err.what() << endl;
                    }

                    if (W == 1) {

                        // Adicionar música no álbum
                    } else if (W == 2) {
                        // Excluir álbum
                    } else {
                        cout << "Entrada inválida \n";
                    }
                    break;
                    
                case 3:

                    musica = getInput("Digite o nome da música: ");
                    genre = getInput("Digite o gênero da música: ");
                    lyrics = getInput("Digite a letra da música: ");
                    duration = getInput("Digite a duração da música: ");
                    // Publicar música
                    break;
                case 4:
                    
                    album = getInput("Digite o nome do álbum: ");
                    // Publicar álbum
                    break;
                case 5:
                    // Ver número de seguidores
                    break;
                case 6:
                    // Ver número de ouvintes que ouviram suas músicas
                    break;
                default:
                    cout << "Entrada inválida \n";
                    break;
            }
        } catch (const runtime_error& err) {
            cerr << err.what() << endl;
        }
    }

        
    
