#ifndef MUSICDATABASE_H
#define MUSICDATABASE_H

#include <vector>
#include "Music.hpp"

class MusicDatabase {
private:
    std::vector<Music*> musics;

public:
    ~MusicDatabase();
    void addMusic(Music* music);
    Music* searchMusicById(int id) const;
};

#endif // MUSICDATABASE_H
