#ifndef ALBUM
#define ALBUM

#include <string>
#include <vector>
#include "../artist/Artist.hpp"
#include "../song/Song.hpp"

using std::string;

class Album {
    private:
        int id;
        string name;
        Artist artist;
        vector<Song> songs;
        long views;
        float duration;
    public:
        // métodos
        void play();

        // construtor
        Album(int id, string name, Artist artist);
};

#endif