#include "MusicDatabase.hpp"
#include "MusicNotFoundException.hpp"

MusicDatabase::~MusicDatabase() {
    for (Music* music : musics) {
        delete music;
    }
}

void MusicDatabase::addMusic(Music* music) {
    musics.push_back(music);
}

Music* MusicDatabase::searchMusicById(int id) const {
    for (Music* music : musics) {
        if (music->getId() == id) {
            return music;
        }
    }
    throw MusicNotFoundException("Music with ID " + std::to_string(id) + " not found.");
}
