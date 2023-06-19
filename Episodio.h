#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
using namespace std;

class Episodio : public Video {
private:
    string nombreSerie;
    int temporada;
    int numeroEpisodio;

public:
    Episodio(const string& id, const string& nombre, const string& genero, int calificacion, int duracion, const string& fechaEstreno, const string& nombreSerie, int temporada, int numeroEpisodio);
    ~Episodio();

    string getNombreSerie() const;
    int getTemporada() const;
    int getNumeroEpisodio() const;
};

#endif
