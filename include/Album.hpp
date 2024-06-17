#pragma once
#ifndef ALBUM
#define ALBUM

#include <string>
#include <vector>
#include "Artist.hpp"
#include "Song.hpp"
#include "csv.hpp"
#include "auxiliares.hpp"

using std::string;

/**
 * @class Album
 * @brief Represents an music album.
 * @details This class contains informations about an music album, including its id, name, artist owner, music list, views and time duration.
 */
class Album {
    private:
        int id;                 /** Unique identifier for the album. */
        string name;            /** Name of the album. */
        string artist;          /** Artist responsible for the album. */
        vector<Song> songs;     /** List of songs in the album. */
        long views;             /** Number of views of the album. */
        
    public:
        /**
         * @brief Plays all the songs of the album.
         * @details Simulates the playback of the album, incrementing the number of views.
         */
        void play();

        /**
         * @brief Constructor for the Album class.
         * @param id Unique identifier for the album.
         * @param name Name of the album.
         * @param artist Artist responsible for the album.
         * @details Initializes an Album object with the provided id, name, and artist.
         */
        Album(int id, string name, string artist);


        /**
         * @brief Publishes the album to a CSV file.
         * @details Writes the album's information to a CSV file.
         */
        void publishAlbum();

        /**
         * @brief Adds a song to the album.
         * @param song Song to be added to the album.
         * @details Adds a song to the album's song list.
         */
        void addSong(Song song);


};

#endif
