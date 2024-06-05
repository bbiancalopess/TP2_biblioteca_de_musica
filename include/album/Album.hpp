#ifndef ALBUM
#define ALBUM

#include <string>
#include <vector>
#include "../artista/Artista.hpp"
#include "../musica/Musica.hpp"

using std::string;

class Album {
    private:
        int id;
        string nome;
        Artista artista;
        vector<Musica> musicas;
        long views;
        float duracao;
    public:
        // métodos
        void play();

        // construtor
        Album(int id, string nome, Artista artista);
};

#endif