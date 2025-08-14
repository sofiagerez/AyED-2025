#include "readings.h"
#include <iostream>
#include <fstream>
#include <new>        // std::nothrow
#include <iomanip>    // std::setprecision

float* crear_arreglo(int size) {
    if (size <= 0) return nullptr;
    return new (std::nothrow) float[size];
}

void liberar_arreglo(float*& arr) {
    delete[] arr;
    arr = nullptr;
}

int cargar_desde_archivo(const std::string& ruta, float* arr, int size) {
    if (!arr || size <= 0) return 0;

    std::ifstream in(ruta);
    if (!in) {
        std::cerr << "Error: no se pudo abrir el archivo '" << ruta << "' para lectura.\n";
        return 0;
    }

    int count = 0;
    while (count < size && (in >> arr[count])) {
        count++;
    }
    return count;
}

bool guardar_en_archivo(const std::string& ruta, const float* arr, int size) {
    if (!arr || size <= 0) return false;

    std::ofstream out(ruta);
    if (!out) {
        std::cerr << "Error: no se pudo abrir el archivo '" << ruta << "' para escritura.\n";
        return false;
    }

    out << std::fixed << std::setprecision(2);
    for (int i = 0; i < size; i++) {
        out << arr[i] << "\n";
    }
    return true;
}

void imprimir(const float* arr, int size) {
    if (!arr || size <= 0) {
        std::cout << "[sin lecturas]\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < size; i++) {
        std::cout << "Lectura[" << i << "] = " << arr[i] << "\n";
    }
}
