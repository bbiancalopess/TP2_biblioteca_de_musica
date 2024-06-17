#include "Album.hpp"

Album::Album(int id, string name, string artist)
    : id(id), name(name), artist(artist) {}

void Album::play() {
    for (int i = 0; i < this->songs.size(); i++) {
        this->songs[i].play();
    }
}

void publishAlbum() {
    vector<vector<string>> data = readCSV("albums.csv");
    vector<string> albumData = {
        std::to_string(this->id),
        this->name,
        this->artist,
    };

    data.push_back(albumData);
    writeCSV("albums.csv", data);
}