#ifndef MUSICDATABASE_H
#define MUSICDATABASE_H

#include <vector>
#include "Music.hpp"
#include <string>

class MusicDatabase {
private:
    std::vector<Music*> musics;

public:
    ~MusicDatabase();
    void addMusic(Music* music);
    void removeMusicById(int id);
    Music* searchMusicById(int id) const;
    void displayAllMusics() const;
};

#endif // MUSICDATABASE_H

