#include "Listener.hpp"

Listener::Listener(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}

void Listener::createPlaylist(int id, string name) {
    this->playlists.push_back(new Playlist(id, name, this));
}

void Listener::deletePlaylist(Playlist* playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i]->getId() == playlist->getId()) {
            this->playlists.erase(this->playlists.begin() + i);
            break;
        }
    }
}

void Listener::createPlaylist(int id, string name) {
    Playlist* new_playlist = new Playlist(id, name, this);
    this->playlists.push_back(new_playlist);
}

void Listener::addToPlaylist(Song* song, Playlist* playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i]->getId() == playlist->getId()) {
            this->playlists[i]->addSong(song);
            break;
        }
    }
}

void Listener::addToPlaylist(Album* album, Playlist* playlist) {
    for(int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i])
    }
}

void Listener::removeSongFromPlaylist(Song* song, Playlist* playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i]->getId() == playlist->getId()) {
            this->playlists[i]->removeSong(song);
            break;
        }
    }
}