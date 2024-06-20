#ifndef SONG
#define SONG

#include <string>
#include "Artist.hpp"
#include "Album.hpp"
#include "csv.hpp"
#include "auxiliares.hpp"

using std::string;

/**
 * @class Song
 * @brief Represents a song.
 * @details This class contains informations about a song, including its id, name, artist, genre, lyrics, duration, views and album.
 */
class Song {
    private:
        int id;             /** Unique identifier for the song. */
        string name;        /** Name of the song. */
        string artist;      /** Artist who published the song. */
        string genre;       /** Genre of the song. */
        string lyrics;      /** Song's lyrics, used to simulate the playback. */
        Album album;        /** (Optional) Album that the song is a part of. */
    public:
        /**
         * @brief Plays the song.
         * @details Simulates the playback of the song, incrementing the number of views.
         */
        void play();

        /**
         * @brief Increase the variable which counts the song's plays number.
         * @param songName Name of the song to be played.
         * @details Simulates a new play to the song.
         */
        void increaseViews(string songName);

        /**
         * @brief Constructor for the Song class.
         * @param id Unique identifier for the song.
         * @param name Name of the song.
         * @param artist Artist who published the song.
         * @param genre Genre of the song.
         * @param lyrics Lyrics of the song.
         * @param views Number of views of the song.
         * @details Initializes a Song object with the provided id, name, artist, genre, lyrics, and views.
         */
        Song(int id, string name, string artist, string genre, string lyrics);

        virtual void getLyrics();

        

        /**
         * @brief Searches for a song in a CSV file.
         * @param songName Name of the song to be searched.
         * @details Reads the CSV file and searches for the song with the provided name.
         */
        void findMusic(const string& songName);



        void playMusic(const string& songName);

        

        /**
         * @brief Publishes a song in a CSV file.
         * @details Writes the song's information in the CSV file.
         */
        void publishMusic();

        void playMusic(const string& songName);

        void deleteMusic(const string& songName);

        friend class System;
};

#endif