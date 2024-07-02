#ifndef POPMUSIC_H
#define POPMUSIC_H

#include "Music.hpp"

/**
 * @brief Classe que representa uma música pop.
 * 
 * Esta classe herda da classe Music e adiciona funcionalidades específicas para músicas pop.
 */
class PopMusic : public Music {
public:
    /**
     * @brief Construtor da classe PopMusic.
     * 
     * @param id O ID da música.
     * @param title O título da música.
     * @param lyrics A letra da música.
     */
    PopMusic(int id, const std::string& title, const std::string& lyrics);

    /**
     * @brief Método que exibe as informações da música.
     * 
     * Este método sobrescreve o método display da classe base Music.
     */
    void display() const override; // Sobrescrita do método virtual
};

#endif // POPMUSIC_H
