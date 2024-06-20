#include "../include/Song_pt.hpp"

#include <iostream>


Song_pt::Song_pt(int id, string name, string artist, string genre, string pt_lyrics)
    : Song(id, name, artist, genre), pt_lyrics(pt_lyrics) {}