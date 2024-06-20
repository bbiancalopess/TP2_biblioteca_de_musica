#include <iostream>
#include <vector>
#include <string>


#include "System.hpp"

void System::addMusic() {
    int type, id;
    std::string title, lyrics;

    std::cout << "Digite o tipo de música (1: Pop, 2: Rock, 3: Clássica): ";
    std::cin >> type;
    std::cout << "Digite o ID: ";
    std::cin >> id;
    std::cout << "Digite o título: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Digite a letra: ";
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
            std::cout << "Tipo inválido!" << std::endl;
            return;
    }

    database.addMusic(music);
    std::cout << "Música adicionada com sucesso!" << std::endl;
}

void System::removeMusic() {
    int id;
    std::cout << "Digite o ID da música a ser removida: ";
    std::cin >> id;

    try {
        database.removeMusicById(id);
        std::cout << "Música removida com sucesso!" << std::endl;
    } catch (const MusicNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
}

void System::viewMusics() {
    database.displayAllMusics();
}

void System::searchMusic() {
    int id;
    std::cout << "Digite o ID da música a ser pesquisada: ";
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
        std::cout << "1. Adicionar Música\n";
        std::cout << "2. Remover Música\n";
        std::cout << "3. Visualizar Todas as Músicas\n";
        std::cout << "4. Pesquisar Música por ID\n";
        std::cout << "5. Sair\n";
        std::cout << "Digite sua escolha: ";
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
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Escolha inválida! Por favor, tente novamente." << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 5);
}

