#include "Artist.hpp"
#include <iostream>

int Artist :: publishedSongs = 0;

Artist::Artist(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}



void Artist::publishSong(int id, string name, string genre, string lyrics, double duration) {
    Song* new_song = new_song(id, name, *this, genre, lyrics, duration, song);
        this->songs.push_back(*new_song);
        publishedSongs++;
}

void Artist::deleteSong(string song) {
        for (int i = 0; i < this->song.size(); i++) {
            if (this->song[i].getId() == song.getId()) {
                this->song.erase(this->song.begin() + i);
            }
        }    
        publishedSongs--;
}

void Artist:: publishAlbum(string name) {
    Album* new_album = new_album(id, name, genre, lyrics, duration, album);
         this->albun.push_back(*new_albun);   
} 

void Artist:: addSongToAlbum(string song, string albun) {
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == albun.getId()) {
            this->albun[i].addSong(song);
            break;
        }
    }
}

void Artist:: deleteAlbum(string albun) {
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == playlist.getId()) {
            this->albun.erase(this->albun.begin() + i);
            break;
        }
    }    
}

void Artist::publishSong(int id, string name, string genre, string lyrics, float duration) {
    Song* new_song = new song(id, name, *this, genre, lyrics, duration, song);
        this->songs.push_back(*new_song);
        publishedSongs++;
}

void Artist::deletesong(Song song) {
        for (int i = 0; i < this->song.size(); i++) {
            if (this->song[i].getId() == song.getId()) {
                this->song.erase(this->song.begin() + i);
            }
        }    
        publishedSongs--;
}

void Artist::publishAlbum(string name) {
    Album* new_album = new album(id, name, genre, lyrics, duration, album);
        this->album.push_back(*new_albun);   
} 

void Artist:: addSongToAlbum(Song* song, Album* albun) {
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == albun.getId()) {
            this->albun[i].addSong(song);
            break;
        }
    }        
}

void Artist:: deleteAlbum(Album album) {
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == playlist.getId()) {
            this->albun.erase(this->albun.begin() + i);
            break;
        }
    }        
}