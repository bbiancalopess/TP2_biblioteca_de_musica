#include "auxiliares.hpp"

#include <iostream>


using std::cout;
using std::cin;

string getInput(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

void clearScreen() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}