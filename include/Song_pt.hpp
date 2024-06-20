#ifndef SONG_PT
#define SONG_PT

#include "Song.hpp"

class Song_pt : public Song {
    private:
        string pt_lyrics;      /** Song's lyrics in portuguese, used to simulate the playback. */

    public:
        Song_pt(int id, string name, string artist, string genre, string pt_lyrics);
        void getLyrics() override;
        
}










#endif