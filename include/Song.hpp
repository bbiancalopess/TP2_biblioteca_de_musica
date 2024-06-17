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
        long views;         /** Total times that the song was played. */
        Album album;        /** (Optional) Album that the song is a part of. */
    public:
        /**
         * @brief Plays the song.
         * @details Simulates the playback of the song, incrementing the number of views.
         */
        void play();

        /**
         * @brief Increase the variable which counts the song's plays number.
         * @details Simulates a new play to the song.
         */
        void increaseViews();

        /**
         * @brief Constructor for the Song class.
         * @param id Unique identifier for the song.
         * @param name Name of the song.
         * @param artist Artist responsible for the song.
         * @param genre Song's genre.
         * @param lyrics Lyrics of the song, used to simulate the playback of the song..
         * @param duration Song's time duration in minutes.
         * @details Initializes an Song object with the provided id, name, artist, genre, lyrics and time duration.
         */
        Song(int id, string name, string artist, string genre, string lyrics, long views);

        

        /**
         * @brief Searches for a song in a CSV file.
         * @param filename Name of the CSV file to be read.
         * @param songName Name of the song to be searched.
         * @details Reads the CSV file and searches for the song with the provided name.
         */
        void findMusic(const string& filename, const string& songName);

        void playMusic(const string& filename, const string& songName);

        

        /**
         * @brief Publishes a song in a CSV file.
         * @param filename Name of the CSV file to be written.
         * @details Writes the song's information in the CSV file.
         */
        void publishMusic(const string &filename);
};

#endif