#include "../../include/artist/Artist.hpp"

Artist::Artist(int id, string name, string email, string password)
    : User(id, name, email, password) {}
void Artist::increaseCountFollowers() {
    this->count_followers += 1;
}

void Artist::play() {
    for (int i = 0; i < this->musics.size(); i++) {
        this->musics[i].play();
    }
}
void Artist::publishmusic(int id, string name, string genre, string lyrics, float duration, Album album) {
    Music* new_music = new music(id, name, *this, genre, lyrics, duration, album);
    this->musics.push_back(*new_music);
}