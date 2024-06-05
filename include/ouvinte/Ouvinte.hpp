#ifndef OUVINTE
#define OUVINTE

#include <vector>
#include "../usuario/Usuario.hpp"
#include "../playlist/Playlist.hpp"
#include "../musica/Musica.hpp"
#include "../artista/Artista.hpp"
#include "../album/Album.hpp"

using std::vector;

class Ouvinte : public Usuario {
    private: 
        vector<Playlist> playlists;
    public:
        // metodos
        void criaPlaylist(string nome);
        void excluirPlaylist(Playlist playlist);
        void adicionarNaPlaylist(Musica musica, Playlist playlist);
        void adiconarNaPlaylist(Album album, Playlist playlist);
        void removerDaPlaylist(Musica musica, Playlist playlist);
        string follow(Artista artista);

        // construtor
        Ouvinte(int id, string nome, string email, string senha);

        // getters and setters
        
};

#endif