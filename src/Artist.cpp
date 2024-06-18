#include "Artist.hpp"
#include <iostream>

Artist::Artist(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}