#ifndef POPMUSIC_H
#define POPMUSIC_H

#include "Music.hpp"

class PopMusic : public Music {
public:
    PopMusic(int id, const std::string& title, const std::string& lyrics);
    void display() const override; // Sobrescrita do método virtual
};

#endif // POPMUSIC_H
