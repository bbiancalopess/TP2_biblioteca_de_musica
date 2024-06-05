#include "../../include/musica/Musica.hpp"
#include <iostream>

using namespace std;

Musica::Musica(int id, string nome, Artista artista, string genero, string letra, float duracao)
    : id(id), nome(nome), artista(artista), genero(genero), letra(letra), duracao(duracao), views(0) {}

Musica::Musica(int id, string nome, Artista artista, string genero, string letra, float duracao, Album album)
    : id(id), nome(nome), artista(artista), genero(genero), letra(letra), duracao(duracao), album(album), views(0) {}

string Musica::getNome() {
    return this->nome;
}

string Musica::getLetra() {
    return this->letra;
}

Artista Musica::getArtista() {
    return this->artista;
}

string Musica::getGenero(){
    return this->genero;
}

float Musica::getDuracao() {
    return this->duracao;
}

long Musica::getViews() {
    return this->views;
}

Album Musica::getAlbum() {
    return this->album;
}

void Musica::play() {
    cout << this->letra << endl;
    this->increaseViews();
}
void Musica::increaseViews() {
    this->views += 1;
}
