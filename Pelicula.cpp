#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula(const string& id, const string& nombre, const string& genero, int calificacion, int duracion, const string& fechaEstreno)
    : Video(id, nombre, genero, calificacion, duracion, fechaEstreno) {}

Pelicula::~Pelicula() {}
