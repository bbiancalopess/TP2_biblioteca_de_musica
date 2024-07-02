#ifndef MUSIC_H
#define MUSIC_H

#include <string>

/**
 * @brief Classe que representa uma música.
 * 
 * A classe Music armazena informações sobre uma música, como o seu ID, título e letras.
 * Ela possui métodos para obter essas informações e um método virtual puro para exibir a música.
 */
class Music {
private:
    int id; /**< O ID da música. */
    std::string title; /**< O título da música. */
    std::string lyrics; /**< As letras da música. */

public:
    /**
     * @brief Construtor da classe Music.
     * 
     * @param id O ID da música.
     * @param title O título da música.
     * @param lyrics As letras da música.
     */
    Music(int id, const std::string& title, const std::string& lyrics);

    /**
     * @brief Destrutor virtual da classe Music.
     */
    virtual ~Music() = default;

    /**
     * @brief Método virtual puro para exibir a música.
     */
    virtual void display() const = 0;

    /**
     * @brief Obtém o ID da música.
     * 
     * @return O ID da música.
     */
    int getId() const;

    /**
     * @brief Obtém o título da música.
     * 
     * @return O título da música.
     */
    std::string getTitle() const;

    /**
     * @brief Obtém as letras da música.
     * 
     * @return As letras da música.
     */
    std::string getLyrics() const;
};

#endif // MUSIC_H



