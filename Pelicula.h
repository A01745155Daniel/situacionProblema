#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
using namespace std;

class Pelicula : public Video {
public:
    Pelicula(const string& id, const string& nombre, const string& genero, int calificacion, int duracion, const string& fechaEstreno);
    ~Pelicula();
};

#endif
