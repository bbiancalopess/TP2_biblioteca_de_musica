#ifndef MUSICA
#define MUSICA

#include <string>
#include "../artista/Artista.hpp"
using std::string;

class Musica {
    private:
        int id;
        string nome;
        Artista artista;
        string genero;
        string letra;
        float duracao;
        long views;
        Album album;
    public:
        // métodos
        void play();
        void increaseViews();

        // construtor
        Musica(int id, string nome, Artista artista, string genero, string letra, float duracao);
        Musica(int id, string nome, Artista artista, string genero, string letra, float duracao, Album album);

        // getters and setters
        string getNome();
        string getLetra();
        Artista getArtista();
        string getGenero();
        float getDuracao();
        long getViews();
        Album getAlbum();
};

#endif