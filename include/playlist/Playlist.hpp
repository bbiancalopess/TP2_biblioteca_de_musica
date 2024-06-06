#ifndef PLAYLIST
#define PLAYLIST

#include <string>
#include <vector>
#include "../user/User.hpp"
#include "../song/Song.hpp"

using std::string;
using std::vector;

class Playlist {
    private:
        int id;
        string name;
        vector<Song> songs;
        User creator;
    public:
        //  métodos
        void addSong(Song song);
        void removeSong(Song song);
        void play();

        //  construtor
        Playlist(int id, string name, User creator);

        //  getters and setters
        string getName();
        vector<Song> getSongs();
        User getCreator();
        void setName(string name);
};

#endif