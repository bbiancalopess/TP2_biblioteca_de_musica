#include <iostream>
#include "System.hpp"
#include "csv.hpp"
#include "User.hpp"
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <System.hpp>
#include "auxiliares.hpp"
#include "Song.hpp"

using std::vector;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;
using std::cerr;
using std::endl;
using std::cout;
using std::cin;



void System::getAllUsers() {
    try {    
        vector<vector<string>> data = readCSV("../csv/users.csv");

        for (const auto& row : data) {
            this->users.push_back(new User(stoi(row[0]), row[1], row[2], row[3], row[4]));
        }
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }   
}

string getLyrics(int song_id) {
    
}

void System::getAllSongs() {
    try {    
        vector<vector<string>> data = readCSV("../csv/songs.csv");

        for (const auto& row : data) {
            this->songs.push_back(new Song());
        }
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }  
}

string System::login(string email, string password) {
    this->getAllUsers();

    for (User* u : this->users) { // passa pelos usuários do sistema
        if (email == u->email) { // verifica se o email é igual ao da linha, se não for, passa para a linha seguinte e faz o mesmo
            if (password == u->password) { // se o email for igual, verifica se a senha é igual
                return "logged"; // se a senha for a certa, o usuário está logado
            } else {
                return "wrong password"; // se a senha for diferente, a senha digitada está errada
            }
        }
    }

    return "not registered"; // caso o email não esteja no arquivo, o usuário não está cadastrado
}

string getNextUserId(){
    try {
        vector<vector<string>> users = readCSV("../csv/users.csv"); // lê o arquivo

        return to_string(stoi(users[users.size() - 1][0]) + 1); // pega o id da última linha do arquivo, sendo esse, o último cadastro
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

string System::signUp(string name, string email, string password, string userType) {
    try {    
        vector<vector<string>> data = readCSV("../csv/users.csv");

        vector<string> newData = {getNextUserId(), name, email, password, userType};

        data.push_back(newData);

        writeCSV("../csv/users.csv", data);

        return "cadastrado";
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

void signUpInfo(System* sistema) {
    string name = getInput("Digite seu nome: ");
    string email = getInput("Digite seu email: ");
    string password = getInput("Digite sua senha: ");
    string userType = getInput("Digite o tipo de usuário (ouvinte ou artista): ");
    while(userType != "ouvinte" && userType != "artista"){
        userType = getInput("Digite o tipo de usuário (ouvinte ou artista): ");
    }
    string result = sistema->signUp(name, email, password, userType);
    if (result == "cadastrado") {
        cout << "Cadastrado com sucesso!" << endl;
    }

}

void System::startTheSystem() {

    

    string inicio = "--------------------------------------------------\n";
    inicio += "-------- ESSA É SUA BIBLIOTECA DE MÚSICAS --------\n";
    inicio += "--------------------------------------------------\n\n";
    inicio += "-------------- VOCÊ JÁ É UM USUÁRIO? -------------\n\n";
    inicio += "1. Não, quero me cadastrar!\n";
    inicio += "2. Sim, quero fazer log-in!\n";
    cout << inicio << endl;
    
    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    while (true) {
        try {
            if (W == 1) {
                signUpInfo(this);
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

    void checkUSerType(string userType){
        for (User* u : this->users) {
            if (userType == Artist) {
                return artist;
            }
            else if (userType == Ouvinte) {
                return ouvinte;
            }
            else {
                cout << "Erro ao definir o tipo de usuario"
                exit (1);
             }
        }
    }
    
    if (checkUserType() == "ouvinte") {
        showListenerOptions();
    } else if (checkUserType() == "artista") {
        showArtistOptions();
    }
}

void System::showListenerOptions() {
    string inicio = "--------------------------------------------------\n\n";
    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Pesquisar uma música!\n";
    inicio += "2. Pesquisar álbum\n";
    inicio += "3. Pesquisar artista!\n";
    inicio += "4. Ver suas Playlists!\n";
    inicio += "5. Ver artistas seguidos!\n";

    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    try {
        string album;
        string artista;
        string musica;
        string playlist;

        switch (W) {
            case 1:
                musica = getInput("Digite o nome da música: ");
                showMusicOptions();
                break;
            case 2:
                album = getInput("Digite o nome do álbum: ");
                showAlbumOptions();
                break;
            case 3:
                artista = getInput("Digite o nome do artista: ");
                showArtistOptions();
                break;
            case 4:
                showPlaylistOptions();
                break;
            case 5:
                showFollowedArtistsOptions();
                break;
            default:
                cout << "Entrada inválida \n";
                break;
        }
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

void System::showMusicOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Tocar música!\n";
    inicio += "2. Adicionar música na playlist!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }
    
    string musica = getInput("Digite o nome da música: ");
    
    findMusic(musica);
    
    switch (W) {
        case 1:
            playMusic(musica);
            break;
        case 2:
            addMusicToPlaylist(musica);
            break;
        default:
            cout << "Entrada inválida \n";
            break;
    }
}

void System::showAlbumOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Tocar álbum inteiro!\n";
    inicio += "2. Adicionar álbum na playlist!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    string album = getInput("Digite o nome do álbum");

    findAlbum();

    switch (W) {
        case 1:
            playAlbum(album)
            break;
        case 2:
            addAlbumToPlaylist(album)
            break;
        default:
            cout << "Entrada inválida \n";
            break;
    }
}

void System::showPlaylistOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Tocar Playlist desejada!\n";
    inicio += "2. Remover música da Playlist desejada!\n";
    inicio += "3. Renomear Playlist desejada!\n";
    inicio += "4. Remover Playlist desejada!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    string playlist = getInput("Digite o nome da Playlist: ");

    findPlaylist(playlist);

    string musica;
    string novoNome;

    switch (W) {
        case 1:
            playPlaylist(playlist);
            break;
        case 2:
            musica = getInput("Digite o nome da música a ser removida da Playlist: ");
            removeMusicFromPlaylist(musica, playlist);
            break;
        case 3:
            novoNome = getInput("Digite o novo nome da Playlist: ");
            renamePlaylist(playlist, novoNome);
            break;
        case 4:
            removePlaylist(playlist);
            break;
        default:
            cout << "Entrada inválida \n";
            break;
    }
}

void System::showFollowedArtistsOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Ver músicas do artista!\n";
    inicio += "2. Ouvir o artista desejado!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    string artista = getInput("Digite a opção de sua escolha: ");
    
    findArtist(artista);

    if (W == 1) {
        getArtistMusics(artista);
    } else if (W == 2) {
        listenArtist(artista);
    } else {
        cout << "Entrada inválida \n";
    }
}

        
void System::showArtistOptions() {
    string inicio = "--------------------------------------------------\n\n";
    inicio += "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Ver suas músicas!\n";
    inicio += "2. Ver seus álbuns!\n";
    inicio += "3. Publicar música!\n";
    inicio += "4. Publicar álbum!\n";
    inicio += "5. Ver número de ouvintes que ouviram suas músicas!\n";

    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    try {
        string album;
        string artista;
        string musica;
        string playlist;
        string genre;
        string lyrics; 
        string duration; 

        switch (W) {
            case 1:
                showArtistMusicOptions();
                break;
            case 2:
                showArtistAlbumOptions();
                break;
            case 3:
                createMusic();
                
                break;
            case 4:
                
                createAlbum();
                break;
            case 5:
                listenersNumber();
                break;
            default:
                cout << "Entrada inválida \n";
                break;
        }
    } catch (const runtime_error& err) {
        cerr << err.what() << endl;
    }
}

void System::showArtistMusicOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Ouvir música desejada!\n";
    inicio += "2. Apagar música!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    string musica = getInput("Digite o nome da música: ");

    findMusic(musica);

    if (W == 1) {
        playMusic(musica);
    } else if (W == 2) {
        deleteMusic(musica);
    } else {
        cout << "Entrada inválida \n";
    }
}

void System::showArtistAlbumOptions() {
    string inicio = "-------------- DIGITE A AÇÃO DESEJADA -------------\n\n";
    inicio += "1. Adicionar música no álbum!\n";
    inicio += "2. Excluir álbum!\n";
    cout << inicio << endl;

    string opcao = getInput("Digite a opção de sua escolha: ");
    clearScreen();

    int W = 0;
    try {
        W = stoi(opcao); // string to int
    } catch (...) {
        cout << "Entrada inválida \n";
    }

    string album = getInput("Digite o nome do álbum: ");
    
    findAlbum(album);

    if (W == 1) {
        string musica = getInput("Digite o nome da música a ser adicionada no álbum: ");
        addMusicToAlbum(musica, album);
    } else if (W == 2) {
        deleteAlbum(album);
    } else {
        cout << "Entrada inválida \n";
    }
}
