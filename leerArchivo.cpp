/*
Daniel Guerrero González
Leer el archivo de texto en c++
*/
#include <fstream>
#include <iostream>
#include <sstream> //Para string stream
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "Pelicula.h"
#include "Episodio.h"


// Función para separar una línea en elementos
vector<string> separar(const string& linea) {
    vector<string> elementos;
    stringstream ss(linea);
    string elemento;
    while (getline(ss, elemento, ',')) {
        elementos.push_back(elemento);
    }
    return elementos;
}

// Función para leer el archivo CSV y devolver los datos en una matriz
vector<vector<string>> leerArchivo(const string& nombreArchivo) {
    vector<vector<string>> datos;

    ifstream archivo(nombreArchivo);
    if (archivo) {
        string linea;
        while (getline(archivo, linea)) {
            vector<string> datosLinea = separar(linea);
            datos.push_back(datosLinea);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return datos;
}
int convertirEntero(const string& texto) {
    int resultado;
    stringstream ss(texto);
    return resultado;
}

int main(int argc, char const* argv[]) {
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");
    string linea;
    int numeroLinea = 1;
    vector<Video*> videos;

    while (getline(entrada, linea)) {
        vector<string> datos = separar(linea);
        cout << (numeroLinea++) << " ";
        if (datos.size() == 6) {
            cout << "Pelicula ";
            try {
                videos.push_back(new Pelicula(datos[0], datos[1], datos[2], convertirEntero(datos[3]), convertirEntero(datos[4]), datos[5]));
            } catch (const invalid_argument& e) {
                cout << "Error de conversión en datos[3] o datos[4]: " << e.what() << endl;
            } catch (const out_of_range& e) {
                cout << "Error de rango en datos[3] o datos[4]: " << e.what() << endl;
            }
        } else if (datos.size() == 9) {
            cout << "Episodio ";
            try {
                videos.push_back(new Episodio(datos[0], datos[1], datos[2], convertirEntero(datos[3]), convertirEntero(datos[4]), datos[5], datos[6], convertirEntero(datos[7]), convertirEntero(datos[8])));
            } catch (const invalid_argument& e) {
                cout << "Error de conversión en datos[3], datos[4], datos[7] o datos[8]: " << e.what() << endl;
            } catch (const out_of_range& e) {
                cout << "Error de rango en datos[3], datos[4], datos[7] o datos[8]: " << e.what() << endl;
            }
        } else {
            cout << "Error: El número de campos no es válido." << endl;
        }
        cout << endl;
    }

    entrada.close();


    // Menú
    int opcion = 0;
    while (opcion != 8) {
        cout << "Menu:" << endl;
        cout << "1. Cargar el archivo de datos en formato csv." << endl;
        cout << "2. Mostrar los videos en general con una calificación mayor o igual a un valor." << endl;
        cout << "3. Mostrar los videos en general de un género específico." << endl;
        cout << "4. Mostrar todos los episodios de una determinada serie." << endl;
        cout << "5. Mostrar las películas con una calificación mayor a un número." << endl;
        cout << "6. Calificar un video." << endl;
        cout << "7. Calcular el promedio de la calificación de una serie." << endl;
        cout << "8. Salir." << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Cargar el archivo de datos en formato csv
                string archivo;
                cout << "Ingrese el nombre del archivo csv: ";
                cin.ignore();
                getline(cin, archivo);

                ifstream entradaArchivo;
                entradaArchivo.open(archivo);
                if (!entradaArchivo) {
                    cout << "No se pudo abrir el archivo." << endl;
                    break;
                }

                string lineaArchivo;
                int numeroLineaArchivo = 1;

                while (getline(entradaArchivo, lineaArchivo)) {
                    vector<string> datosArchivo = separar(lineaArchivo);
                    cout << (numeroLineaArchivo++);
                    if (datosArchivo.size() == 6) {
                        cout << " Pelicula ";
                        try {
                            videos.push_back(new Pelicula(datosArchivo[0], datosArchivo[1], datosArchivo[2], stoi(datosArchivo[3]), stoi(datosArchivo[4]), datosArchivo[5]));
                        } catch (const invalid_argument& e) {
                            cout << "Error de conversión en datosArchivo[3] o datosArchivo[4]: " << e.what() << endl;
                        } catch (const out_of_range& e) {
                            cout << "Error de rango en datosArchivo[3] o datosArchivo[4]: " << e.what() << endl;
                        }
                    } else {
                        cout << " Episodio ";
                        try {
                            videos.push_back(new Episodio(datosArchivo[0], datosArchivo[1], datosArchivo[2], stoi(datosArchivo[3]), stoi(datosArchivo[4]), datosArchivo[5], datosArchivo[6], stoi(datosArchivo[7]), stoi(datosArchivo[8])));
                        } catch (const invalid_argument& e) {
                            cout << "Error de conversión en datosArchivo[3], datosArchivo[4], datosArchivo[7] o datosArchivo[8]: " << e.what() << endl;
                        } catch (const out_of_range& e) {
                            cout << "Error de rango en datosArchivo[3], datosArchivo[4], datosArchivo[7] o datosArchivo[8]: " << e.what() << endl;
                        }
                    }
                    cout << endl;
                }

                entradaArchivo.close();

                cout << "Archivo cargado exitosamente." << endl;
                break;
            }
            case 2: {
                // Mostrar los videos en general con una calificación mayor o igual a un valor
                int calificacionMinima;
                cout << "Ingrese la calificación mínima: ";
                cin >> calificacionMinima;

                cout << "Videos con calificación mayor o igual a " << calificacionMinima << ":" << endl;
                for (const auto& video : videos) {
                    if (video->getCalificacion() >= calificacionMinima) {
                        cout << "- " << video->getNombre() << " (Calificación: " << video->getCalificacion() << ")" << endl;
                    }
                }
                break;
            }
            case 3: {
                // Mostrar los videos en general de un género específico
                string genero;
                cout << "Ingrese el género: ";
                cin >> genero;

                cout << "Videos del género " << genero << ":" << endl;
                for (const auto& video : videos) {
                    string videoGenero = video->getGenero();
                    if (videoGenero.find(genero) != string::npos) {
                        cout << "- " << video->getNombre() << " (Género: " << videoGenero << ")" << endl;
                    }
                }
                break;
            }
            case 4: {
                // Mostrar todos los episodios de una determinada serie
                string nombreSerie;
                cout << "Ingrese el nombre de la serie: ";
                cin.ignore();
                getline(cin, nombreSerie);

                cout << "Episodios de la serie " << nombreSerie << ":" << endl;
                for (const auto& video : videos) {
                    if (dynamic_cast<Episodio*>(video) != nullptr) {
                        Episodio* episodio = dynamic_cast<Episodio*>(video);
                        if (episodio->getNombreSerie() == nombreSerie) {
                            cout << "- " << episodio->getNombre() << " (Temporada: " << episodio->getTemporada() << ", Episodio: " << episodio->getNumeroEpisodio() << ")" << endl;
                        }
                    }
                }
                break;
            }
            case 5: {
                // Mostrar las películas con una calificación mayor a un número
                int calificacionMinima;
                cout << "Ingrese la calificación mínima: ";
                cin >> calificacionMinima;

                cout << "Películas con calificación mayor a " << calificacionMinima << ":" << endl;
                for (const auto& video : videos) {
                    if (dynamic_cast<Pelicula*>(video) != nullptr && video->getCalificacion() > calificacionMinima) {
                        cout << "- " << video->getNombre() << " (Calificación: " << video->getCalificacion() << ")" << endl;
                    }
                }
                break;
            }
            case 6: {
                // Calificar un video
                string titulo;
                int calificacion;
                cout << "Ingrese el título de la película o nombre del capítulo de la serie a calificar: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el valor de calificación: ";
                cin >> calificacion;

                bool videoEncontrado = false;
                for (auto& video : videos) {
                    if (video->getNombre() == titulo) {
                        video->setCalificacion(calificacion);
                        cout << "Calificación asignada exitosamente." << endl;
                        videoEncontrado = true;
                        break;
                    }
                }

                if (!videoEncontrado) {
                    cout << "No se encontró ningún video con el título especificado." << endl;
                }
                break;
            }
            case 7: {
                // Calcular el promedio de la calificación de una serie
                string nombreSerie;
                cout << "Ingrese el nombre de la serie: ";
                cin.ignore();
                getline(cin, nombreSerie);

                int totalEpisodios = 0;
                int sumaCalificaciones = 0;

                for (const auto& video : videos) {
                    if (dynamic_cast<Episodio*>(video) != nullptr) {
                        Episodio* episodio = dynamic_cast<Episodio*>(video);
                        if (episodio->getNombreSerie() == nombreSerie) {
                            totalEpisodios++;
                            sumaCalificaciones += episodio->getCalificacion();
                        }
                    }
                }

                if (totalEpisodios > 0) {
                    float promedio = static_cast<float>(sumaCalificaciones) / totalEpisodios;
                    cout << "El promedio de calificación de la serie " << nombreSerie << " es: " << promedio << endl;
                } else {
                    cout << "No se encontró ninguna serie con el nombre especificado." << endl;
                }
                break;
            }
            case 8: {
                // Salir
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Por favor, ingrese un número válido." << endl;
                break;
            }
        }

        cout << endl;
    }

    // Liberar la memoria de los videos
    for (auto& video : videos) {
        delete video;
    }

    return 0;
}
