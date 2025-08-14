#include <iostream>
#include <string>
#include "readings.h"

using namespace std;

int main() {
    int N;
    cout << "Ingrese cantidad de lecturas: ";
    if (!(cin >> N) || N <= 0) {
        cout << "Cantidad invalida.\n";
        return 1;
    }

    // 1) Reservar memoria
    float* lecturas = crear_arreglo(N);
    if (!lecturas) {
        cout << "Error: no se pudo reservar memoria.\n";
        return 1;
    }

    // 2) Leer desde archivo
    string archivoEntrada;
    cout << "Ingrese nombre de archivo para leer: ";
    cin >> archivoEntrada;

    int leidos = cargar_desde_archivo(archivoEntrada, lecturas, N);
    cout << "Se leyeron " << leidos << " valores desde '" << archivoEntrada << "'.\n";

    // 3) Mostrar por pantalla
    imprimir(lecturas, leidos);

    // 4) Guardar en archivo
    string archivoSalida;
    cout << "Ingrese nombre de archivo para guardar: ";
    cin >> archivoSalida;

    if (guardar_en_archivo(archivoSalida, lecturas, leidos)) {
        cout << "Datos guardados en '" << archivoSalida << "'.\n";
    } else {
        cout << "Error al guardar los datos.\n";
    }

    // 5) Liberar memoria
    liberar_arreglo(lecturas);

    return 0;
}
