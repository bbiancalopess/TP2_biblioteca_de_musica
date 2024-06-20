#include "../include/Song_pt.hpp"

#include <iostream>

using namespace std;

Song_pt::Song_pt(const string &title, const string &artist, const string &lyrics_pt)
    : Song(title, artist) {}

string Song_pt::getLyrics() const {
    return lyrics_pt;
}
