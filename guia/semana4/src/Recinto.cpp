#include "Recinto.h"
#include <iostream>

Recinto::Recinto(std::string nombre, int nSensores){
    this->nombre = nombre;
    this->nSensores = nSensores;
    this->sensores = new Sensor*[nSensores];
    for(int i=0; i<nSensores; i++) {
        this->sensores[i] = nullptr;
    }
}

Recinto::~Recinto(){
    delete[] sensores;
}

std::string Recinto::getNombre(){
    return nombre;
}

int Recinto::getCantSensores(){
    return nSensores;
}

void Recinto::setNombre(std::string nombreNuevo){
    this->nombre = nombreNuevo;
}

// ------------------ RECURSIVOS ------------------

float Recinto::_suma(Sensor** v, int n, std::string unidad){
    //TODO
}

int Recinto::_maximo(Sensor** v, int n, std::string unidad, int mejorPos){
    //TODO
}

int Recinto::_buscar(Sensor** v, int n, const std::string& key){
    //TODO
}

Sensor* Recinto::_getSensor(Sensor** v, int n, int posBuscada){
    //TODO
}
