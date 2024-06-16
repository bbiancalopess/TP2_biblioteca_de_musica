#include "Artist.hpp"
#include <iostream>

int Artist:: publishedSongs = 0;

Artist::Artist(int id, string name, string email, string password)
    : User(id, name, email, password) {
    }

