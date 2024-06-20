#ifndef CLASSICALMUSIC_H
#define CLASSICALMUSIC_H

#include "Music.hpp"

class ClassicalMusic : public Music {
public:
    ClassicalMusic(int id, const std::string& title, const std::string& lyrics);
    void display() const override; // Sobrescrita do método virtual
};

#endif // CLASSICALMUSIC_H
