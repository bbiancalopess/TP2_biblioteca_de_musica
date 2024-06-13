#ifndef SONG
#define SONG

#include <string>
#include "../artist/Artist.hpp"
#include "../album/Album.hpp"
using std::string;

class Song {
    private:
        int id;
        string name;
        Artist artist;
        string genre;
        string lyrics;
        float duration;
        long views;
        Album album;
    public:
        // métodos
        void play();
        void increaseViews();

        // construtor
        Song(int id, string name, Artist artist, string genre, string lyrics, float duration);
        Song(int id, string name, Artist artist, string genre, string lyrics, float duration, Album album);

        // getters and setters
        string getName();
        string getLyrics();
        Artist getArtist();
        string getGenre();
        float getDuration();
        long getViews();
        Album getAlbum();
};

#endif