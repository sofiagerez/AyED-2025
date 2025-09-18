#include "Sensor.h"
#include <cmath>   // std::fabs

Sensor::Sensor(std::string n, std::string u)
: nombre(n), valor(0.0f), unidad(u), ventana(nullptr), K(0), sumaVentana(0.0f) {}

Sensor::~Sensor() {
    if (ventana) delete ventana;
}

void Sensor::configurarVentana(int k) {
    if(this->ventana) {
        delete this->ventana;
        this->ventana = nullptr;
    }
    this->ventana = new Cola<float>();
    if(k>0){
        this->K=k;
    }else {
        this->K=0;
    }
    // this->K = (k>0) ? k:0; uso de operador ternario para asignacion
    // es equivalente al if-else anterior
}

void Sensor::agregarLectura(float x) {
    if(!ventana || K<=0) return;
    this->ventana->enqueue(x);
    this->sumaVentana += x;
    if(this->ventana->size()>K){
        float val_viejo = ventana->dequeue();
        this->sumaVentana-=val_viejo;
    }
}

void Sensor::setValor(float nuevo) {
    //TODO
}

float Sensor::promedioMovil() const {
    //TODO
}

bool Sensor::estable(float umbral) const {
    //TODO
}
