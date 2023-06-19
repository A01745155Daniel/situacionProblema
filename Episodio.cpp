#include "Episodio.h"
using namespace std;

Episodio::Episodio(const string& id, const string& nombre, const string& genero, int calificacion, int duracion, const string& fechaEstreno, const string& nombreSerie, int temporada, int numeroEpisodio)
    : Video(id, nombre, genero, calificacion, duracion, fechaEstreno), nombreSerie(nombreSerie), temporada(temporada), numeroEpisodio(numeroEpisodio) {}

Episodio::~Episodio() {}

std::string Episodio::getNombreSerie() const {
    return nombreSerie;
}

int Episodio::getTemporada() const {
    return temporada;
}

int Episodio::getNumeroEpisodio() const {
    return numeroEpisodio;
}
