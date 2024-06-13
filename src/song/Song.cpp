#include "../../include/song/Song.hpp"
#include "../../include/artist/Artist.hpp"
#include <iostream>

using namespace std;

Song::Song(int id, string name, Artist artist, string genre, string lyrics, float duration)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), duration(duration), views(0) {}

Song::Song(int id, string name, Artist artist, string genre, string lyrics, float duration, Album album)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), duration(duration), album(album), views(0) {}

string Song::getName() {
    return this->name;
}

string Song::getLyrics() {
    return this->lyrics;
}

Artist Song::getArtist() {
    return this->artist;
}

string Song::getGenre(){
    return this->genre;
}

float Song::getDuration() {
    return this->duration;
}

long Song::getViews() {
    return this->views;
}

Album Song::getAlbum() {
    return this->album;
}

void Song::play() {
    cout << this->lyrics << endl;
    this->increaseViews();
}
void Song::increaseViews() {
    this->views += 1;
}
