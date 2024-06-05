#ifndef ARTISTA
#define ARTISTA

#include <vector>
#include "../usuario/Usuario.hpp"
#include "../album/Album.hpp"
#include "../musica/Musica.hpp"

using std::vector;

class Artista : public Usuario {
    private: 
        vector<Album> albuns;
        vector<Musica> musicas;
        long views;
        vector<Usuario> seguidores;
    public:
        // métodos
        long contarSeguidores();
        void play();
        void publicarMusica(string nome, string genero, string letra, float duracao, Album album);
        void publicarMusica(string nome, string genero, string letra, float duracao);
        void excluirMusica(Musica musica);
        void publicarAlbum(string nome);
        void adicionarMusicaAoAlbum(Musica musica, Album album);
        void excluirAlbum(Album album);

        // construtor
        Artista(int id, string nome, string email, string senha);
};

#endif