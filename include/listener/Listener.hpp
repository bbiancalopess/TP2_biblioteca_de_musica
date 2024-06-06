#ifndef LISTENER
#define LISTENER

#include <vector>
#include "../user/User.hpp"
#include "../playlist/Playlist.hpp"
#include "../song/Song.hpp"
#include "../artist/Artist.hpp"
#include "../album/Album.hpp"

using std::vector;

class Listener : public User {
    private: 
        vector<Playlist> playlists;
    public:
        // metodos
        void createPlaylist(string name);
        void deletePlaylist(Playlist playlist);
        void addToPlaylist(Music music, Playlist playlist);
        void addToPlaylist(Album album, Playlist playlist);
        void removeFromPlaylist(Music music, Playlist playlist);
        string follow(Artist artist);

        // construtor
        Listener(int id, string name, string email, string password);

        // getters and setters
        
};

#endif