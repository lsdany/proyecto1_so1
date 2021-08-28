//
// Created by luisdany on 27/08/21.
//

#ifndef TEST_PROCESO_H
#define TEST_PROCESO_H

#include<iostream>

using namespace std;

class Proceso {

public:
    string procesoId;
    string tema;
    string prioridad;
    string paternidad;
    string tiempoEjecucion;


    void toString(){
        cout << procesoId;
        cout << tema;
        cout << paternidad;
        cout << tiempoEjecucion;
    }

};


#endif //TEST_PROCESO_H
