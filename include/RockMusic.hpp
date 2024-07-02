#ifndef ROCKMUSIC_H
#define ROCKMUSIC_H

#include "Music.hpp"

/**
 * @brief Classe que representa uma música de rock.
 * 
 * A classe RockMusic é uma subclasse da classe Music e representa uma música de rock.
 * Ela herda os atributos e métodos da classe Music e adiciona funcionalidades específicas
 * para músicas de rock.
 */
class RockMusic : public Music {
public:
    /**
     * @brief Construtor da classe RockMusic.
     * 
     * @param id O ID da música.
     * @param title O título da música.
     * @param lyrics A letra da música.
     */
    RockMusic(int id, const std::string& title, const std::string& lyrics);

    /**
     * @brief Método para exibir as informações da música de rock.
     * 
     * Este método sobrescreve o método display() da classe base Music e exibe as informações
     * específicas de uma música de rock, como o estilo musical.
     */
    void display() const override; // Sobrescrita do método virtual
};

#endif // ROCKMUSIC_H
