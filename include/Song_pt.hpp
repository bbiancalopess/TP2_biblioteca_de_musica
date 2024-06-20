#ifndef SONG_PT
#define SONG_PT

#include "Song.hpp"

using std::string;

class Song_pt : public Song {
public:
    Song_pt(const string &title, const string &artist, const string &lyrics_pt);
    string getLyrics() const override;

private:
    string lyrics;
};

#endif