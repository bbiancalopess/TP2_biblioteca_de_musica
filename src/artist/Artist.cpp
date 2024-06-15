#include "../../include/artist/Artist.hpp"

Artist::Artist(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}
    
void Artist::increaseCountFollowers() {
    this->count_followers += 1;
}

void Artist::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}
void Artist::publishsong(int id, string name, string genre, string lyrics, float duration, Album album) {
    Song* new_song = new song(id, name, *this, genre, lyrics, duration, album);
    this->songs.push_back(*new_song);
}