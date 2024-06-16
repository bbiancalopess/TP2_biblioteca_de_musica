#include "Artist.hpp"
#include <iostream>

int Artist:: publishedSongs = 0;

Artist::Artist(int id, string name, string email, string password)
    : User(id, name, email, password) {
    }

void Listener::loginArtista() {
    string email = getInput("Digite seu email: ");
    string password = getInput("Digite sua senha: ");
    string result = login(email, password);
    if (result == "loged") {
        cout << "Logado com sucesso!" << endl;
    } else if (result == "wrong password") {
        cout << "Senha incorreta!" << endl;
    } else if (result == "not registered") {
        cout << "Usuário não cadastrado!" << endl;
    }
}

void Artist::publishsong(Id id, Name name, Genre genre, Lyrics lyrics, Duration duration) {
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

void Artist:: publishAlbum(Name name); {
    Album* new_album = new album(id, name, genre, lyrics, duration, album);
         this->albun.push_back(*new_albun);   
} 

void Artist:: addSongToAlbum(Song song, Albun albun);{
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == albun.getId()) {
            this->albun[i].addSong(song);
            break;
}

void Artist:: deleteAlbum(Album album); {
    for (int i = 0; i < this->albun.size(); i++) {
        if (this->albun[i].getId() == playlist.getId()) {
            this->albun.erase(this->albun.begin() + i);
            break;
}

void Artist::increaseCountFollowers() {
    this->count_followers += 1;
}

