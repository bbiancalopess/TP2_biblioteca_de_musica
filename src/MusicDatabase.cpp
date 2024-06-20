#include "MusicDatabase.hpp"
#include "MusicNotFoundException.hpp"
#include <algorithm>
#include <iostream>
#include <string>

MusicDatabase::~MusicDatabase() {
    for (Music* music : musics) {
        delete music;
    }
}

void MusicDatabase::addMusic(Music* music) {
    musics.push_back(music);
}

void MusicDatabase::removeMusicById(int id) {
    auto it = std::find_if(musics.begin(), musics.end(), [id](Music* music) {
        return music->getId() == id;
    });

    if (it != musics.end()) {
        delete *it;
        musics.erase(it);
    } else {
        throw MusicNotFoundException("Música com ID " + std::to_string(id) + " não encontrada.");
    }
}

Music* MusicDatabase::searchMusicById(int id) const {
    for (Music* music : musics) {
        if (music->getId() == id) {
            return music;
        }
    }
    throw MusicNotFoundException("Música com ID " + std::to_string(id) + " não encontrada.");
}

void MusicDatabase::displayAllMusics() const {
    if (musics.empty()) {
        std::cout << "Nenhuma música disponível." << std::endl;
        return;
    }

    for (Music* music : musics) {
        music->display();
        std::cout << "---------------------------" << std::endl;
    }
}
