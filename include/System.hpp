#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <limits>
#include "MusicDatabase.hpp"
#include "popMusic.hpp"
#include "RockMusic.hpp"
#include "ClassicalMusic.hpp"
#include "MusicNotFoundException.hpp"

/**
 * @brief Classe que representa o sistema de biblioteca de música.
 * 
 * Esta classe é responsável por gerenciar as operações do sistema de biblioteca de música,
 * como adicionar música, remover música, visualizar músicas e pesquisar música.
 */
class System {
private:
    MusicDatabase database; // Objeto que representa o banco de dados de músicas

    /**
     * @brief Função para adicionar uma música ao banco de dados.
     */
    void addMusic();

    /**
     * @brief Função para remover uma música do banco de dados.
     */
    void removeMusic();

    /**
     * @brief Função para visualizar todas as músicas do banco de dados.
     */
    void viewMusics();

    /**
     * @brief Função para pesquisar uma música no banco de dados.
     */
    void searchMusic();

public:
    /**
     * @brief Função para iniciar o sistema de biblioteca de música.
     */
    void startTheSystem();
};

#endif // SYSTEM_HPP
