#ifndef ROCKMUSIC_H
#define ROCKMUSIC_H

#include "Music.hpp"

class RockMusic : public Music {
public:
    RockMusic(int id, const std::string& title, const std::string& lyrics);
    void display() const override; // Sobrescrita do método virtual
};

#endif // ROCKMUSIC_H
