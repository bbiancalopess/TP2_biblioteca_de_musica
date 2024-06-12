#include "../../include/music/Music.hpp"
#include "../../include/artist/Artist.hpp"
#include <iostream>

using namespace std;

Music::Music(int id, string name, Artist artist, string genre, string lyrics, float duration)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), duration(duration), views(0) {}

Music::Music(int id, string name, Artist artist, string genre, string lyrics, float duration, Album album)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), duration(duration), album(album), views(0) {}

string Music::getName() {
    return this->name;
}

string Music::getLyrics() {
    return this->lyrics;
}

Artist Music::getArtist() {
    return this->artist;
}

string Music::getGenre(){
    return this->genre;
}

float Music::getDuration() {
    return this->duration;
}

long Music::getViews() {
    return this->views;
}

Album Music::getAlbum() {
    return this->album;
}

void Music::play() {
    cout << this->lyrics << endl;
    this->increaseViews();
}
void Music::increaseViews() {
    this->views += 1;
}
