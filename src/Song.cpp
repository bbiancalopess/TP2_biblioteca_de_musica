#include "Song.hpp"
#include "Artist.hpp"
#include <iostream>

using namespace std;

Song::Song(int id, string name, Artist artist, string genre, string lyrics, float duration)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), duration(duration), views(0) {}

void Song::play() {
    
    cout << this->lyrics << endl;
    this->increaseViews();
}

void Song::increaseViews() {
    this->views += 1;
}

int Song::getId() {
    return this->id;
}