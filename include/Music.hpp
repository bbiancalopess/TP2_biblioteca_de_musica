#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music {
private:
    int id;
    std::string title;
    std::string lyrics;

public:
    Music(int id, const std::string& title, const std::string& lyrics);
    virtual ~Music() = default;
    virtual void display() const = 0; // Função virtual pura
    int getId() const;
    std::string getTitle() const;
    std::string getLyrics() const;
};

#endif // MUSIC_H



