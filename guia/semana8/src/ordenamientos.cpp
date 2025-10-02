// clase_ordenamientos.cpp
// Plantilla simple para comparar algoritmos de ordenamiento
// SIN lambdas. Se quita la medición de tiempo y se agrega un contador de
// comparaciones (COMP). N se toma por argumento de línea de comandos.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXV = 1000000;

/* ===========================
   Contador de comparaciones
   =========================== */
long long COMP = 0;
inline void resetComp(){ COMP = 0; }

/* ===========================
   Utilidades generales
   =========================== */

void copiar(int dst[], const int src[], int n){
    for(int i=0; i<n; ++i) dst[i] = src[i];
}

bool ordenadoAsc(const int a[], int n){
    for(int i=1; i<n; ++i) if (a[i] < a[i-1]) return false;
    return true;
}

void llenarAleatorio(int a[], int n){
    for(int i=0; i<n; ++i) a[i] = rand() % MAXV;
}

void llenarInverso(int a[], int n){
    for(int i=0; i<n; ++i) a[i] = n - i;
}

void llenarCasiOrdenado(int a[], int n){
    for(int i=0; i<n; ++i) a[i] = i;
    // pocos desórdenes (~1%)
    int cambios = (n > 100) ? (n / 100) : 1;
    for(int k=0; k<cambios; ++k){
        int i = rand() % n, j = rand() % n;
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }
}

/* ===========================
   Algoritmos O(n^2) con COMP
   =========================== */

void bubbleSort(int a[], int n){
    bool cambio = true;
    for(int i=0; i<n-1 && cambio; ++i){
        cambio = false;
        for(int j=0; j<n-1-i; ++j){
            COMP++; // comparar a[j] > a[j+1]
            if(a[j] > a[j+1]){
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                cambio = true;
            }
        }
    }
}

void insertionSort(int a[], int n){
    for(int i=1; i<n; ++i){
        int key = a[i];
        int j = i - 1;
        // Contamos SOLO comparaciones de clave (a[j] > key)
        while(j >= 0){
            COMP++;                 // comparación a[j] > key
            if(a[j] > key){
                a[j+1] = a[j];
                --j;
            } else {
                break;
            }
        }
        a[j+1] = key;
    }
}

void selectionSort(int a[], int n){
    for(int i=0; i<n-1; ++i){
        int minIdx = i;
        for(int j=i+1; j<n; ++j){
            COMP++; // comparar a[j] < a[minIdx]
            if(a[j] < a[minIdx]) minIdx = j;
        }
        if(minIdx != i){
            int t = a[i]; a[i] = a[minIdx]; a[minIdx] = t;
        }
    }
}

/* ===========================
   MergeSort (O(n log n)) con COMP
   =========================== */

void merge(int a[], int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i=0; i<n1; ++i) L[i] = a[l + i];
    for(int j=0; j<n2; ++j) R[j] = a[m + 1 + j];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        COMP++; // comparar L[i] <= R[j]
        if(L[i] <= R[j]) a[k++] = L[i++];
        else             a[k++] = R[j++];
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Wrapper para correr como void f(int[],int)
void runMerge(int a[], int n){
    if(n > 0) mergeSort(a, 0, n - 1);
}

/* ===========================
   QuickSort (O(n log n) prom.) con COMP
   =========================== */

int particionar(int a[], int l, int r){ // pivote: a[r]
    int p = a[r];
    int i = l - 1;
    for(int j=l; j<r; ++j){
        COMP++; // comparar a[j] <= p
        if(a[j] <= p){
            ++i;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i+1]; a[i+1] = a[r]; a[r] = t;
    return i + 1;
}

void quickSort(int a[], int l, int r){
    if(l < r){
        int q = particionar(a, l, r);
        quickSort(a, l, q - 1);
        quickSort(a, q + 1, r);
    }
}

void runQuick(int a[], int n){
    if(n > 0) quickSort(a, 0, n - 1);
}

/* ===========================
   HeapSort (O(n log n)) con COMP
   =========================== */

void heapify(int a[], int n, int i){
    int largest = i;
    int L = 2*i + 1;
    int R = 2*i + 2;
    if(L < n){ COMP++; if(a[L] > a[largest]) largest = L; }
    if(R < n){ COMP++; if(a[R] > a[largest]) largest = R; }
    if(largest != i){
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    for(int i=n/2 - 1; i>=0; --i) heapify(a, n, i);
    for(int i=n-1; i>0; --i){
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

/* ===========================
   Impresión de resultados COMP
   =========================== */

void imprimirCOMP(const char* nombre, bool ok){
    cout << "  " << nombre
         << "   OK=" << (ok ? "SI" : "NO")
         << "   COMP=" << COMP
         << "\n";
}

/* ===========================
   Runner por dataset (función normal)
   =========================== */

void correrDataset(const char* titulo,
                   void (*inicializar)(int[],int),
                   int base[], int N){
    cout << "\n== " << titulo << " ==\n";
    inicializar(base, N);

    // buffer de trabajo para no ordenar "base" directo
    int* b = new int[N];
    bool ok;

    copiar(b, base, N); resetComp(); bubbleSort(b, N);    ok = ordenadoAsc(b, N); imprimirCOMP("Bubble   ", ok);
    copiar(b, base, N); resetComp(); insertionSort(b, N); ok = ordenadoAsc(b, N); imprimirCOMP("Insertion", ok);
    copiar(b, base, N); resetComp(); selectionSort(b, N); ok = ordenadoAsc(b, N); imprimirCOMP("Selection", ok);
    copiar(b, base, N); resetComp(); runMerge(b, N);      ok = ordenadoAsc(b, N); imprimirCOMP("Merge    ", ok);
    copiar(b, base, N); resetComp(); runQuick(b, N);      ok = ordenadoAsc(b, N); imprimirCOMP("Quick    ", ok);
    copiar(b, base, N); resetComp(); heapSort(b, N);      ok = ordenadoAsc(b, N); imprimirCOMP("Heap     ", ok);

    delete[] b;
}

/* ===========================
   Main de comparación
   =========================== */

int main(int argc, char* argv[]){
    srand((unsigned)time(nullptr));

    int N = 1000; // por defecto
    if(argc >= 2){
        int narg = atoi(argv[1]);
        if(narg > 0) N = narg;
        else {
            cout << "[Aviso] N invalido en argumento. Se usa N=1000 por defecto.\n";
        }
    } else {
        cout << "[Uso] " << argv[0] << " <N>\n";
        cout << "[Info] No se paso N. Usando N=1000 por defecto.\n";
    }

    int* base = new int[N];
    cout << "N = " << N << "\n";

    // correrDataset("Casi ordenado", llenarCasiOrdenado, base, N);
    correrDataset("Aleatorio    ", llenarAleatorio,    base, N);
    // correrDataset("Inverso      ", llenarInverso,      base, N);

    delete[] base;
    return 0;
}
