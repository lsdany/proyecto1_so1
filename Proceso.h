//
// Created by luisdany on 27/08/21.
// Created by Bryan Recinos on 03/09/2021. 
//

#ifndef TEST_PROCESO_H
#define TEST_PROCESO_H

#include<iostream>
#include <vector>

using namespace std;

class Proceso {

public:
    string procesoId;
    string tema;
    string prioridad;
    string paternidad;
    string tiempoEjecucion;
    string estado;


    void toString(){
        cout << "Proceso: " + procesoId + "\n";
        cout << "tema: " +tema  + "\n";
        cout << "paternidad: " + paternidad  + "\n";
        cout << "tiempo: " + tiempoEjecucion  + "\n";
        cout << "prioridad: " + prioridad + "\n";
    }

    static Proceso parseProcess(vector<string> procesos){
        Proceso proceso;
        proceso.procesoId = procesos[0];
        proceso.tema = procesos[1];
        proceso.prioridad = procesos[2];
        proceso.paternidad = procesos[3];
        proceso.tiempoEjecucion = procesos[4];
        return proceso;
    }

};


#endif //TEST_PROCESO_H
