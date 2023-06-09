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
    entrada.open("DatosPeliculas.csv");
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
    entrada.close();
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
    //cout << "Tokens: " << numeroTokens << endl << endl;
    return tokens;
}
