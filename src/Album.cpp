#include "Album.hpp"

string fileName = "albums.csv";

Album::Album(int id, string name, string artist)
    : id(id), name(name), artist(artist) {}

void Album::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}

void Album::addSong(const Song& song) {
    this->songs.push_back(song);
}

void Album::publishAlbum() {
    vector<vector<string>> data = readCSV(fileName);
    vector<string> albumData = {
        std::to_string(this->id),
        this->name,
        this->artist,
    };

    data.push_back(albumData);
    writeCSV("albums.csv", data);
}

void Album::deleteAlbum(const string& albumName) {
    vector<vector<string>> data = readCSV(fileName);
    vector<vector<string>> newData;

    for (const auto& row : data) {
        if (row.size() > 0 && row[1] != albumName) {
            newData.push_back(row);
        }
    }

    writeCSV(fileName, newData);
} 



void Album::addMusicToAlbum(Song* song, Album& album) {
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
