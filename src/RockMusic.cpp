#include "RockMusic.hpp"
#include <iostream>

RockMusic::RockMusic(int id, const std::string& title, const std::string& lyrics)
    : Music(id, title, lyrics) {}

void RockMusic::display() const {
    std::cout << "Rock Music - ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Lyrics: " << getLyrics() << std::endl;
}
