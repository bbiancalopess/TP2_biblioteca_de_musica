#include "Artist.hpp"
#include <iostream>

Artist::Artist(int id, string name, string email, string password, string userType)
    : User(id, name, email, password, userType) {}



void Artist::publishAlbum(const string& albumName) {
    vector<vector<string>> data = readCSV(fileName);
    vector<string> albumData = {
        std::to_string(this->id),
        this->name,
        this->artist,
    };

    data.push_back(albumData);
    writeCSV("albums.csv", data);
}

void Artist::deleteAlbum(const string& albumName) {
    vector<vector<string>> data = readCSV(fileName);
    vector<vector<string>> newData;

    for (const auto& row : data) {
        if (row.size() > 0 && row[1] != albumName) {
            newData.push_back(row);
        }
    }

    writeCSV(fileName, newData);
} 



void Artist::addMusicToAlbum(Song* song, Album& album) {
    // find the music to be added to the album
    vector<vector<string>> data = readCSV(fileName);
    vector<string> songData;
    
    // Add the song data to the vector
    songData.push_back(to_string(song->getId()));
    songData.push_back(song->getTitle());
    songData.push_back(song->getArtist());
    
    data.push_back(songData);
    writeCSV(fileName, data);
}


