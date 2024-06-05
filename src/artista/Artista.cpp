#include "../../include/artista/Artista.hpp"

Artista::Artista(int id, string nome, string email, string senha)
    : Usuario(id, nome, email, senha) {}
void Artista::increaseSeguidores() {
    this->quantidade_seguidores += 1;
}

void Artista::play() {
    for (int i = 0; i < this->musicas.size(); i++) {
        this->musicas[i].play();
    }
}
void Artista::publicarMusica(int id, string nome, string genero, string letra, float duracao, Album album) {
    Musica* musica_nova = new Musica(id, nome, *this, genero, letra, duracao, album);
    this->musicas.push_back(*musica_nova);
}