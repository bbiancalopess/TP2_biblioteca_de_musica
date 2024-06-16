#include "Album.hpp"

Album::Album(int id, string name, Artist artist)
    : id(id), name(name), artist(artist) {}

void Album::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}