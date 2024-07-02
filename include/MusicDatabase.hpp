#ifndef MUSICDATABASE_H
#define MUSICDATABASE_H

#include <vector>
#include "Music.hpp"
#include <string>

/**
 * @brief Classe que representa um banco de dados de músicas.
 * 
 * Esta classe é responsável por armazenar e gerenciar um conjunto de músicas.
 */
class MusicDatabase {
private:
    std::vector<Music*> musics; /**< Vetor de ponteiros para objetos Music armazenados no banco de dados. */

public:
    /**
     * @brief Destrutor da classe MusicDatabase.
     * 
     * Libera a memória alocada para os objetos Music armazenados no banco de dados.
     */
    ~MusicDatabase();

    /**
     * @brief Adiciona uma música ao banco de dados.
     * 
     * @param music Ponteiro para o objeto Music a ser adicionado.
     */
    void addMusic(Music* music);

    /**
     * @brief Remove uma música do banco de dados pelo seu ID.
     * 
     * @param id ID da música a ser removida.
     */
    void removeMusicById(int id);

    /**
     * @brief Procura uma música no banco de dados pelo seu ID.
     * 
     * @param id ID da música a ser procurada.
     * @return Ponteiro para o objeto Music encontrado ou nullptr se não encontrado.
     */
    Music* searchMusicById(int id) const;

    /**
     * @brief Exibe todas as músicas armazenadas no banco de dados.
     */
    void displayAllMusics() const;
};

#endif // MUSICDATABASE_H

