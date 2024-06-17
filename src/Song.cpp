#include "Song.hpp"

#include <iostream>


using namespace std;

Song::Song(int id, string name, string artist, string genre, string lyrics, long views)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), views(0) {}

void Song::play() {
    
    cout << this->lyrics << endl;
    this->increaseViews();
}

void Song::increaseViews() {
    this->views += 1;
}



void Song::findMusic(const string& filename, const string& songName) {
    vector<vector<string>> data = readCSV(filename);
    bool found = false;

    
    for (const auto& row : data) {
        if (row.size() > 0 && row[0] == songName) {
            found = true;
            break;
        }
    }

    if (!found) {
        throw runtime_error("Song not found: " + songName);
    }
    
}

void Song::playMusic(const string& filename, const string& songName) {
    vector<vector<string >> data = readCSV(filename);

    for (const auto& row : data) {
        if (row.size() > 0 && row[0] == songName) {
            cout << row[4] << endl;
            break;
        }
    }
}



void Song::publishMusic(const string &filename) {
    vector<vector<string>> data = readCSV(filename);
    vector<string> songData = {
        to_string(this->id),
        this->name,
        this->artist,
        this->genre,
        this->lyrics,
        to_string(this->views)
    };

    data.push_back(songData);
    writeCSV(filename, data);
}