#include "auxiliares.hpp"
#include "Song.hpp"

#include <iostream>


using std::cout;
using std::cin;

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

int getId(string caminho) {
    vector<vector<string>> data = readCSV(caminho);
    if (data.empty()) {
        return 1;
    } else {
        int lastId = stoi(data.back()[0]);
        return lastId + 1;
    }
}


void createMusic() {
    int id = getId("data/songs.csv");
    string name = getInput("Digite o nome da música: ");
    string artist = getInput("Digite o nome do artista: ");
    string genre = getInput("Digite o gênero da música: ");
    string lyrics = getInput("Digite a letra da música: ");
    
    Song song(id, name, artist, genre, lyrics, 0);

}