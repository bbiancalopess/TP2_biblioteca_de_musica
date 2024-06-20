#include "Music.hpp"

Music::Music(int id, const std::string& title, const std::string& lyrics)
    : id(id), title(title), lyrics(lyrics) {}

int Music::getId() const {
    return id;
}

std::string Music::getTitle() const {
    return title;
}

std::string Music::getLyrics() const {
    return lyrics;
}






