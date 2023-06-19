#include "Video.h"
using namespace std;

Video::Video(const string &id, const string &nombre, const string &genero, int calificacion, int duracion, const string &fechaEstreno)
    : id(id), nombre(nombre), genero(genero), calificacion(calificacion), duracion(duracion), fechaEstreno(fechaEstreno) 
    {

    }

Video::~Video() 
{

}

string Video::getID() const
{
    return id;
}

string Video::getNombre() const
{
    return nombre;
}

string Video::getGenero() const
{
    return genero;
}

int Video::getCalificacion() const
{
    return calificacion;
}

int Video::getDuracion() const
{
    return duracion;
}

string Video::getFechaEstreno() const
{
    return fechaEstreno;
}

void Video::setCalificacion(int calificacion)
{
    this->calificacion = calificacion;
}
