#include "Reglas.h"
#include <cstdlib>   // std::strtof
#include <iostream>

// utilitario: ¿es operador aritmético/relacional?
static bool esOpNum(const std::string& t) {
    return (t == ">" || t == "<" || t == "==" );
}
static bool esOpBool(const std::string& t) {
    return (t == "&&" || t == "||");
}

bool Reglas::evaluarRPN(Habitacion* h, Lista<std::string>* tokens) {
    Pila<std::string> pila;
    Lista<std::string>* aux = tokens->copy();
    while(!aux->isEmpty()){
        std::string elem = aux->pop_front();
        if(esOpNum(elem)){
            // es un operador numerico
            float b = std::stof(pila.pop(), nullptr);
            float a = std::strtof(pila.pop().c_str(), nullptr);
            if(elem == ">") pila.push((a>b ? "1":"0"));

        }else if (esOpBool(elem)){
            //es un operador booleano
            //sacar de la pila los operandos
            // resolver
            // apilar el resultado
        }else if(elem.rfind("ACT:", 0)==0){
            // es una accion

        } else {
            // es un operando
            Sensor* s = h->obtenerSensor(elem);
            if (s) pila.push(std::to_string(s->getValor()));
            else pila.push(elem);
        }
        int a = 2.3;
    }
}
