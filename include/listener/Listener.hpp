#ifndef LISTENER
#define LISTENER

#include <vector>
#include "../user/User.hpp"
#include "../playlist/Playlist.hpp"
#include "../song/Song.hpp"
#include "../artist/Artist.hpp"
#include "../album/Album.hpp"

using std::vector;

/**
 * @class Listener
 * @brief Represents an listener user.
 * @details This class contains informations about an listener user, including its playlists.
 */
class Listener : public User {
    private: 
        vector<Playlist> playlists;         /** List with all the playlist created by the listener. */
        vector<Artist> favoriteArtists;     /** List with the favorite artists of the listener */
    public:
        /**
         * @brief Creates a new playlist.
         * @details Creates a new playlist with the given name and the creator's name being the listener's name.
         */
        void createPlaylist(string name);

        /**
         * @brief Deletes a playlist.
         * @details Deletes the playlist from the system.
         */
        void deletePlaylist(Playlist playlist);
        
        /**
         * @brief Adds a song to the playlist.
         * @details Adds an exisitng song to an existing playlist.
         */
        void addToPlaylist(Song song, Playlist playlist);
        
        /**
         * @brief Adds an album to a playlist.
         * @details Adds all the songs of an album to a playlist.
         */
        void addToPlaylist(Album album, Playlist playlist);
        
        /**
         * @brief Removes a song from the playlist.
         * @details Removes a song from the playlist.
         */
        void removeFromPlaylist(Song song, Playlist playlist);
        
        /**
         * @brief Follows an artist.
         * @details Follows an artist and add the artist to the list of favorites artists of the listener.
         */
        string follow(Artist artist);

        /**
         * @brief Constructor for the Listener class.
         * @param id Unique identifier for the listener.
         * @param name Name of the listener.
         * @param email Email used to login.
         * @param password Password used to login.
         * @details Initializes an Listener object with the provided id, name, email and password.
         */
        Listener(int id, string name, string email, string password, string userType);
};

#endif