#ifndef CLASSICALMUSIC_H
#define CLASSICALMUSIC_H

#include "Music.hpp"

/**
 * @brief Classe que representa uma música clássica.
 * 
 * A classe ClassicalMusic é uma subclasse da classe Music e representa uma música clássica.
 * Ela herda os atributos e métodos da classe Music e adiciona a funcionalidade de exibição específica para músicas clássicas.
 */
class ClassicalMusic : public Music {
public:
    /**
     * @brief Construtor da classe ClassicalMusic.
     * 
     * @param id O ID da música clássica.
     * @param title O título da música clássica.
     * @param lyrics A letra da música clássica.
     */
    ClassicalMusic(int id, const std::string& title, const std::string& lyrics);

    /**
     * @brief Método para exibir as informações da música clássica.
     * 
     * Este método sobrescreve o método display() da classe base Music.
     * Ele exibe as informações específicas da música clássica, como o ID, título e letra.
     */
    void display() const override; // Sobrescrita do método virtual
};

#endif // CLASSICALMUSIC_H
