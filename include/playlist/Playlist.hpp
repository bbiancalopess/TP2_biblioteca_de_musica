#ifndef PLAYLIST
#define PLAYLIST

#include <string>
#include <vector>
#include "../user/User.hpp"
#include "../song/Song.hpp"

using std::string;
using std::vector;

/**
 * @class Playlist
 * @brief Represents an playlist.
 * @details This class contains informations about an playlist, including its id, name, list of songs and creator.
 */
class Playlist {
    private:
        int id;                 /** Unique identifier ofr the playlist. */
        string name;            /** Playlist's name. */
        vector<Song> songs;     /** List of songs in the playlist. */
        User creator;           /** User that created the playlist. */
    public:
        /**
         * @brief Adds a song to the playlist.
         * @details Adds a new existing song to the playlist.
         * @param song The song that must be added.
         */
        void addSong(Song song);

        /**
         * @brief Removes a song from the playlist.
         * @details Deletes a song that was in the playlist.
         * @param song The song that must be removed.
         */
        void removeSong(Song song);

        /**
         * @brief Plays all the songs in the playlist.
         * @details Simulates the playback of the playlist, incrementing the number of plays in each song.
         */
        void play();

        /**
         * @brief Constructor for the Playlist class.
         * @param id Unique identifier for the playlist.
         * @param name Name of the playlist.
         * @param creator User that created the playlist.
         * @details Initializes an Playlist object with the provided id, name and creator.
         */
        Playlist(int id, string name, User creator);
};

#endif