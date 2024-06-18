#include "Listener.hpp"

Listener::Listener(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}

void Listener::createPlaylist(int id, string name) {
    this->playlists.push_back(new Playlist(id, name, this));
}



void Listener::FollowArtist(Artist* artist) {
    this->artist.push_back(artist);
}