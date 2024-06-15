#include "Listener.hpp"



Listener::Listener(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}



void Listener::follow(Artist artist) {
    this->followed_artists.push_back(artist);
}

void Listener::unfollow(Artist artist) {
    for (int i = 0; i < this->followed_artists.size(); i++) {
        if (this->followed_artists[i].getId() == artist.getId()) {
            this->followed_artists.erase(this->followed_artists.begin() + i);
            break;
        }
    }
}

void Listener::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}

void Listener::addSong(Song song) {
    this->songs.push_back(song);
}

void Listener::removeSong(Song song) {
    for (int i = 0; i < this->songs.size(); i++) {
        if (this->songs[i].getId() == song.getId()) {
            this->songs.erase(this->songs.begin() + i);
            break;
        }
    }
}

void Listener::addPlaylist(Playlist playlist) {
    this->playlists.push_back(playlist);
}

void Listener::removePlaylist(Playlist playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i].getId() == playlist.getId()) {
            this->playlists.erase(this->playlists.begin() + i);
            break;
        }
    }
}

void Listener::createPlaylist(string name) {
    Playlist* new_playlist = new Playlist(this->playlists.size(), name);
    this->playlists.push_back(*new_playlist);
}

void Listener::addSongToPlaylist(Song song, Playlist playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i].getId() == playlist.getId()) {
            this->playlists[i].addSong(song);
            break;
        }
    }
}

void Listener::removeSongFromPlaylist(Song song, Playlist playlist) {
    for (int i = 0; i < this->playlists.size(); i++) {
        if (this->playlists[i].getId() == playlist.getId()) {
            this->playlists[i].removeSong(song);
            break;
        }
    }
}

