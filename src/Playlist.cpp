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

int Playlist::getId(){
    return this->id;
}