# CasaDomotica++ - Semana 2
## Unidad 1: Uso dinámico de la memoria y proyectos multifile
### Objetivos de la clase

* Comprender la diferencia entre memoria automática (stack) y memoria dinámica (heap).
* Reservar y liberar memoria dinámicamente con new[] y delete[].
* Utilizar punteros para manejar arreglos dinámicos de datos.
* Guardar y cargar datos desde archivos de texto.
* Organizar el código en múltiples archivos (.h y .cpp) para mejorar la escalabilidad del proyecto.
* Segundo paso del proyecto CasaDomótica++: administrar un conjunto de lecturas de un sensor virtual de temperatura, almacenarlas dinámicamente y persistirlas en un archivo.

### Para compilar
### Para compilar y ejecutar
```bash
g++ -std=c++17 src/main.cpp src/readings.cpp -Iinclude -o semana2
```