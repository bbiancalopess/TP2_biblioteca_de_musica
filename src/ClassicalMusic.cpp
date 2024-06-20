#include "ClassicalMusic.hpp"
#include <iostream>

ClassicalMusic::ClassicalMusic(int id, const std::string& title, const std::string& lyrics)
    : Music(id, title, lyrics) {}

void ClassicalMusic::display() const {
    std::cout << "Classical Music - ID: " << getId() << std::endl;
    std::cout << "Title: " << getTitle() << std::endl;
    std::cout << "Lyrics: " << getLyrics() << std::endl;
}
