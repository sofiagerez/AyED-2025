#include "Sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>


Sensor::Sensor() {
    
}
Sensor::Sensor(std::string nombre, float valor, std::string unidad) {
    this->nombre = nombre;
    this->valor = valor;
    this->unidad = unidad;
}

std::string Sensor::getNombre(){
    return nombre;
}

void Sensor::setNombre(std::string nombreNuevo){
    nombre = nombreNuevo;
}