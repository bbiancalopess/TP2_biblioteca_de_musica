#include "Playlist.hpp"

Playlist::Playlist(int id, string name, Listener* creator)
    : id(id), name(name), creator(creator) {}

void Playlist::addSong(Song* song) {
    this->songs.push_back(song);
}

void Playlist::removeSong(Song* song) {
    for(int i = 0; i < this->songs.size(); i++) {
        if (this->songs[i]->getId() == song->getId()) {
            this->songs.erase(this->songs[i]);
        }
    }
}

void Playlist::play() {
    for (Song* song: this->songs) {
        song->play();
    }
}


void Playlist::getName(){
    return this->name;
}

void addToPlaylist(Song* song, Playlist* playlist) {
    // 1. Ler o conteúdo atual do arquivo CSV
    vector<vector<string>> data = readCSV("playlists.csv");

    // 2. Encontrar a playlist correta pelo nome e adicionar a música
    bool found = false;
        for (int i = 0; i < data.size(); i++) {
            if (row(2) == playlist->getName()) { 
                data[i].push_back(song->getName() + "," + song->getArtist()); // Adiciona a música à playlist
                found = true;
                break;
            }
        }

    // 3. Escrever de volta para o arquivo CSV
    writeCSV(data, "playlists.csv");
}

