#include <iostream>
#include "Sensor.h"

using namespace std;

int main() {
    // Instancia un objeto de la clase Sensor
    Sensor* s1 = new Sensor("Temp Cocina", 22.6, "C");
    // s1->nombre = "Temp Cocina";
    cout << s1->getNombre() << endl;
    // cout << s1->nombre << endl;
    return 0;
}
