#pragma once
#ifndef ARTIST
#define ARTIST

#include <vector>
#include "User.hpp"
#include "Album.hpp"
#include "Song.hpp"

using std::vector;

/**
 * @class Artist
 * @brief Represents an user that is an artist.
 * @details This class contains informations about an user that is an artist, including its albums, songs, total views, followers and count of followers.
 */
class Artist : public User {

    private:
        static int publishedSongs;

    public:
        static int getpublishedSongs();

    private: 
        static int publishedSongs;

    public:
        static int getpublishedSongs();

    private: 
        vector<Album*> albums;       /** Albums of the artist. */
        vector<Song*> songs;         /** Songs of the artist. */
        long views;                 /** Total number of views in the artist songs. */
    public:
        /**
         * @brief Plays all the songs of the artist.
         * @details Simulates the playback of the songs, incrementing the number of views in each one.
         */
        void play();

        /**
         * @brief Publish a new single song in the artist name.
         * @details Let the artist publish a new single song, a song that isn't in an album.
         * @param id Unique identifier for the song.
         * @param name Name of the song.
         * @param genre Song's genre.
         * @param lyrics The lyric of the song, the one used to simulate the playback.
         * @param duration Time duration of the song in minutes.
         */
        void publishSong(int id, string name, string genre, string lyrics, float duration);
        
        /**
         * @brief Deletes a song.
         * @details Removes a song from the artist's discography.
         * @param song The song that should be deleted.
         */
        void deleteSong(Song* song);
        
        /**
         * @brief Adds a new album in the artist name.
         * @details Let the artist publish a new album to its discography.
         * @param name The name of the album that should be published.
         */
        void publishAlbum(string name);
        
        /**
         * @brief Adds an existing song to an existing album.
         * @details Lets the artist add a song to one of its albums. 
         * @param song The song that should be added to the album.
         * @param album The album in which the song will be added.
         */
        void addSongToAlbum(Song* song, Album* album);
        
        /**
         * @brief Deletes an album.
         * @details Removes an album from the artist discography.
         * @param album The album that should be deleted.
         */
        void deleteAlbum(Album* album);

        /**
         * @brief Constructor for the Artist class.
         * @param id Unique identifier for the artist.
         * @param name Name of the artist.
         * @param email Email used to login into the system.
         * @param password Password used to login into the system.
         * @details Initializes an Artist object with the provided id, name, email and password.
         */
        Artist(int id, string name, string email, string password, string userType);
};

#endif
