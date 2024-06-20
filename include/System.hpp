#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <limits>
#include "MusicDatabase.hpp"
#include "popMusic.hpp"
#include "RockMusic.hpp"
#include "ClassicalMusic.hpp"
#include "MusicNotFoundException.hpp"

class System {
private:
    MusicDatabase database;

    void addMusic();
    void removeMusic();
    void viewMusics();
    void searchMusic();

public:
    void startTheSystem();
};

#endif // SYSTEM_HPP
