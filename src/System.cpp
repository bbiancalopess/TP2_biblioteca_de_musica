using std::vector;
using std::string;
using std::stoi;
using std::to_string;
using std::runtime_error;
using std::cerr;
using std::endl;
using std::cout;
using std::cin;



#include "System.hpp"

void System::addMusic() {
    int type, id;
    std::string title, lyrics;

    std::cout << "Enter the type of music (1: Pop, 2: Rock, 3: Classical): ";
    std::cin >> type;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter lyrics: ";
    std::getline(std::cin, lyrics);

    Music* music = nullptr;
    switch (type) {
        case 1:
            music = new PopMusic(id, title, lyrics);
            break;
        case 2:
            music = new RockMusic(id, title, lyrics);
            break;
        case 3:
            music = new ClassicalMusic(id, title, lyrics);
            break;
        default:
            std::cout << "Invalid type!" << std::endl;
            return;
    }

    database.addMusic(music);
    std::cout << "Music added successfully!" << std::endl;
}

void System::removeMusic() {
    int id;
    std::cout << "Enter ID of the music to remove: ";
    std::cin >> id;

    try {
        database.removeMusicById(id);
        std::cout << "Music removed successfully!" << std::endl;
    } catch (const MusicNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
}

void System::viewMusics() {
    database.displayAllMusics();
}

void System::searchMusic() {
    int id;
    std::cout << "Enter ID of the music to search: ";
    std::cin >> id;

    try {
        Music* music = database.searchMusicById(id);
        music->display();
    } catch (const MusicNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
}

void System::startTheSystem() {
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Music\n";
        std::cout << "2. Remove Music\n";
        std::cout << "3. View All Musics\n";
        std::cout << "4. Search Music by ID\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMusic();
                break;
            case 2:
                removeMusic();
                break;
            case 3:
                viewMusics();
                break;
            case 4:
                searchMusic();
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 5);
}

