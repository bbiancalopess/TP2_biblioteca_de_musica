#include "../../include/album/Album.hpp"

Album::Album(int id, string name, Artist artist)
    : id(id), name(name), artist(artist) {}

void Album::play() {
    for (int i = 0; i < this->musics.size(); i++) {
        this->musics[i].play();
    }
}