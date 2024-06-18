#include "Album.hpp"

string fileName = "albums.csv";

Album::Album(int id, string name, string artist)
    : id(id), name(name), artist(artist) {}

void Album::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}

void Album::addSong(const Song& song) {
    this->songs.push_back(song);
}


