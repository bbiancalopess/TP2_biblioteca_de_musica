#include "popMusic.hpp"
#include <iostream>

PopMusic::PopMusic(int id, const std::string& title, const std::string& lyrics)
    : Music(id, title, lyrics) {}

void PopMusic::display() const {
    std::cout << "Pop Music - ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Lyrics: " << getLyrics() << std::endl;
}
