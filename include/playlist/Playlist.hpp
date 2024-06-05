#ifndef PLAYLIST
#define PLAYLIST

#include <string>
#include <vector>
#include "../usuario/Usuario.hpp"
#include "../musica/Musica.hpp"

using std::string;
using std::vector;

class Playlist {
    private:
        int id;
        string nome;
        vector<Musica> musicas;
        Usuario criador;
    public:
        //  métodos
        void adicionarMusica(Musica musica);
        void removerMusica(Musica musica);
        void play();

        //  construtor
        Playlist(int id, string nome, Usuario criador);

        //  getters and setters
        string getNome();
        vector<Musica> getMusicas();
        Usuario getCriador();
        void setNome(string nome);
};

#endif