//
// Created by luisdany on 27/08/21.
//

#ifndef TEST_PROCESO_H
#define TEST_PROCESO_H

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Proceso {

public:
    int procesoId{0};
    string tema;
    string prioridad;
    int paternidad{0};
    int tiempoEjecucion{0};
    string estado;


    void toString() const {
        cout << "Proceso: " << procesoId << endl;
        cout << "tema: " + tema << endl;
        cout << "paternidad: " << paternidad << endl;
        cout << "tiempo: " << tiempoEjecucion << endl;
        cout << "prioridad: " + prioridad << endl;
        cout << "estado: " + estado << endl;
        cout << "-------------------------" << endl;
    }

    static Proceso parseProcess(vector<string> procesos) {
        Proceso proceso;
        proceso.procesoId = std::stoi(procesos[0]);
        proceso.tema = procesos[1];
        proceso.prioridad = procesos[2];
        if (isNumber(procesos[3])) {
            proceso.paternidad = std::stoi(procesos[3]);
        }else{
            proceso.paternidad = 0;
        }

        if(isNumber(procesos[4])){
            proceso.tiempoEjecucion = std::stoi(procesos[4]);
        } else {
            proceso.tiempoEjecucion = 0;
        }

        return proceso;
    }

    static bool isNumber(const std::string &s) {
        return !s.empty() && std::find_if(s.begin(),
                                          s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
    }

};


#endif //TEST_PROCESO_H
