#include <iostream>
#include "Lista.h"
using namespace std;

// Imprime sin modificar la lista: hace una copia y poppea de la copia.
template <class T>
void imprimir(const Lista<T>* L, const char* etiqueta = "") {
    cout << etiqueta;
    Lista<T>* tmp = L->copy();
    cout << "[";
    bool first = true;
    while (!tmp->isEmpty()) {
        if (!first) cout << ", ";
        first = false;
        cout << tmp->pop_front();
    }
    cout << "]\n";
    delete tmp;
}

// Carga elementos usando push_back
void cargar(Lista<int>* L, const int* a, int n) {
    for (int i = 0; i < n; ++i) L->push_back(a[i]);
}

int main() {
    // Mismo conjunto de datos para comparar métodos
    int datos[] = { 7, 3, 9, 1, 5, 2, 8, 5, 4 };
    int n = sizeof(datos) / sizeof(datos[0]);

    // Dos listas idénticas
    Lista<int>* L_datos   = new Lista<int>();
    // Lista<int>* L_enlaces = new Lista<int>();
    cargar(L_datos, datos, n);
    // cargar(L_enlaces, datos, n);

    // Caso 1: Bubble sort swappeando DATOS
    cout << "=== Bubble (swap de datos) ===\n";
    imprimir(L_datos,   "Antes : ");
    L_datos->bubble_sort(true);            // ascendente
    imprimir(L_datos,   "Despues: ");

    cout << "\n";

    // // Caso 2: Bubble sort re-enlazando NODOS
    // cout << "=== Bubble (swap de punteros) ===\n";
    // imprimir(L_enlaces, "Antes : ");
    // L_enlaces->bubble_sort_links(true);    // ascendente
    // imprimir(L_enlaces, "Despues: ");

    // Limpieza
    delete L_datos;
    // delete L_enlaces;

    return 0;
}
