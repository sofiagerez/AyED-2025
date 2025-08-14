#ifndef READINGS_H
#define READINGS_H

#include <string>

// Crea un arreglo dinámico de 'size' floats y devuelve el puntero.
// Retorna nullptr si size <= 0 o si falla la reserva.
float* crear_arreglo(int size);

// Libera memoria reservada y pone el puntero en nullptr.
void liberar_arreglo(float*& arr);

// Carga hasta 'size' valores desde archivo de texto en 'arr'.
// Retorna la cantidad de valores leídos correctamente.
int cargar_desde_archivo(const std::string& ruta, float* arr, int size);

// Guarda 'size' valores de 'arr' en archivo de texto (uno por línea).
// Retorna true si se guardó con éxito, false si hubo error.
bool guardar_en_archivo(const std::string& ruta, const float* arr, int size);

// Imprime las lecturas por pantalla.
void imprimir(const float* arr, int size);

#endif // READINGS_H
