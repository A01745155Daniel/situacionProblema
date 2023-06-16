/*
Daniel Guerrero González
Leer el archivo de texto en c++
*/
#include <fstream>
#include <iostream>
#include <sstream> //Para string stream
#include <vector>
using namespace std;

vector<string> separar(string linea);

int main(int argc, char const *argv[])
{
    ifstream entrada;
    //Excepcions
    entrada.flags(ios_base::failbit);
    entrada.exceptions(ios_base::failbit);
    try
    {
        entrada.open("DatosPeliculas.csv");
    }
    catch(ifstream::failure &e)
    {
        cout << "ERROR excepcion al abrir el archivo" << endl;
        return -1;
    }
    //entrada.open("DatosPeliculas.csv");
    /*if (entrada.fail())
    {
        cout << "error, no puedo leer el archivo" << endl;
        return -1; //Error
    }*/
    string linea;
    int numeroLinea = 1;
    while (getline(entrada, linea))
    {
        // cout << (numeroLinea++) << ": " << linea << endl;
        vector<string> datos = separar(linea);
        cout << (numeroLinea++);
        if (datos.size()==6)
        {
            cout << " Pelicula ";
            //new Pelicula(datos);
        }else{
            cout << " Episodio ";
            //new Episodio(datos);
        }
        cout << endl;
    }
    try
    {
        entrada.close();
    }
    catch(ifstream::failure &e)
    {

    }
    return 0;
}
vector<string> separar(string linea)
{
    vector<string> tokens;       // Componentes de la linea
    stringstream entrada(linea); // Flujo de datos
    string dato;                 // Token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato!="" && dato!= "\n" && dato!="\r")
        {
            cout << dato << numeroTokens <<endl;
            tokens.push_back(dato); //Guarda en el vector
            numeroTokens++;
        }
    }
    bool incorrecto = true;
    while (incorrecto)
    {
        try
        {
            cout << "tokens: " << tokens.at(tokens.size())<<endl;
            incorrecto = false;
        }
        catch (out_of_range &e)
        {
            cout << "indice incorrecto";
            incorrecto = true;
        }
    }
    //cout << "Tokens: " << numeroTokens << endl << endl;
    return tokens;
}
