#include "Song.hpp"

#include <iostream>


using namespace std;

string filename = "songs.csv";

Song::Song(int id, string name, string artist, string genre, string lyrics, long views)
    : id(id), name(name), artist(artist), genre(genre), lyrics(lyrics), views(0) {}

void Song::play() {
    
    cout << this->lyrics << endl;
    this->increaseViews();
}

void Song::findMusic(const string& songName) {
    
    vector<vector<string>> data = readCSV(filename);
    bool found = false;

    
    for (const auto& row : data) {
        if (row.size() > 0 && row[1] == songName) {
            found = true;
            break;
        }
    }

    if (!found) {
        throw runtime_error("Song not found: " + songName);
    }
    
}

void returnMusic() {
    vector<vector<string>> data = readCSV(filename);
}

void someFunction() {
    string musica = "musicaa";
    findMusic(musica);
}

void Song::playMusic(const string& songName) {
    vector<vector<string >> data = readCSV(filename);

    for (const auto& row : data) {
        if (row.size() > 0 && row[0] == songName) {
            cout << row[4] << endl;
            break;
        }
    }
    increaseViews(songName);
}

void Song::increaseViews(string& songName) {
    vector<vector<string>> data = readCSV(filename);
    vector<vector<string>> newData;

    for (const auto& row : data) {
        if (row.size() > 0 && row[1] == songName) {
            int views = stoi(row[5]);
            views++;
            row[5]= to_string(views);
        }
        newData.push_back(row);
    }

    writeCSV(filename, newData);
}





