#include "../../include/album/Album.hpp"

Album::Album(int id, string nome, Artista artista)
    : id(id), nome(nome), artista(artista) {}

Album::play() {
    for (int i = 0; i < this->musicas.size(); i++) {
        this->musicas[i].play();
    }
}