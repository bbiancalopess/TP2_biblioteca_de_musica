#include "Artist.hpp"
#include <iostream>

int Artist :: publishedSongs = 0;

Artist::Artist(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {

    }



void Artist::publishSong(int id, string name, string genre, string lyrics, float duration) {
    Song* new_song = new song(id, name, *this, genre, lyrics, duration);
        this->songs.push_back(*new_song);
        publishedSongs++;
}

void Artist::deleteSong(Song* song) {
        for (int i = 0; i < this->song.size(); i++) {
            if (this->song[i].getId() == song.getId()) {
                this->song.erase(this->song.begin() + i);
            }
        }    
        publishedSongs--;
}

void Artist:: publishAlbum(string name) {
    Album* new_album = new album(id, name, genre, lyrics, duration, album);
         this->album.push_back(*new_album);   
} 

void Artist:: addSongToAlbum(Song* song, Album* album) {
    for (int i = 0; i < this->album.size(); i++) {
        if (this->album[i].getId() == album.getId()) {
            this->album[i].addSong(song);
            break;
        }
    }
}

void Artist:: deleteAlbum(Album* album) {
    for (int i = 0; i < this->album.size(); i++) {
        if (this->album[i].getId() == playlist.getId()) {
            this->album.erase(this->album.begin() + i);
            break;
        }
    }    
}

void Artist::publishSong(int id, string name, string genre, string lyrics, float duration) {
    Song* new_song = new song(id, name, *this, genre, lyrics, duration);
        this->songs.push_back(*new_song);
        publishedSongs++;
}

void Artist::deleteSong(Song* song) {
        for (int i = 0; i < this->song.size(); i++) {
            if (this->song[i].getId() == song.getId()) {
                this->song.erase(this->song.begin() + i);
            }
        }    
        publishedSongs--;
}

void Artist::publishAlbum(string name) {
    Album* new_album = new album(id, name, genre, lyrics, album);
        this->album.push_back(*new_album);   
} 

void Artist:: addSongToAlbum(Song* song, Album* album) {
    for (int i = 0; i < this->album.size(); i++) {
        if (this->album[i].getId() == album.getId()) {
            this->album[i].addSong(song);
            break;
        }
    }        
}

void Artist:: deleteAlbum(Album* album) {
    for (int i = 0; i < this->album.size(); i++) {
        if (this->album[i].getId() == album.getId()) {
            this->album.erase(this->album.begin() + i);
            break;
        }
    }        
}

int Artist :: getpublishedSongs() {
    return publishedSongs;
}

void Artist::publishSong(int id, string name, string genre, string lyrics) {
    this->song.push_back(new song(id, name, this));
}

void Artist::publishAlbum(string name) {
    this->album.push_back(new Album(id, name, this));
}
