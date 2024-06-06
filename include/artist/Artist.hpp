#ifndef ARTIST
#define ARTIST

#include <vector>
#include "../user/User.hpp"
#include "../album/Album.hpp"
#include "../song/Song.hpp"

using std::vector;

class Artist : public User {
    private: 
        vector<Album> albuns;
        vector<Song> songs;
        long views;
        vector<User> followers;
        long count_followers;
    public:
        // métodos
        void play();
        void publishSong(int id, string name, string genre, string lyrics, float duration, Album album);
        void publishSong(int id, string name, string genre, string lyrics, float duration);
        void deleteSong(Song song);
        void publishAlbum(string name);
        void addSongToAlbum(Song song, Album album);
        void deleteAlbum(Album album);
        void increaseCountFollowers();

        // construtor
        Artist(int id, string name, string email, string password);
};

#endif