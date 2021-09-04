//
// Created by luisdany on 31/08/21.
//

#include <iostream>
#include <ctime>

#ifndef TEST_BITACORA_H
#define TEST_BITACORA_H

using namespace std;

class Bitacora {

public:

    int id{0};
    string nombreProceso;
    string accion;
    string estado;
    time_t fecha {time(0)};


    string print(){

        if(id != 0){
            return "Proceso: " + to_string(id) + "-" + nombreProceso + "-" + accion + "-" +  estado + "-" + ctime(&fecha) ;
        } else {
            return nombreProceso + "-" + accion + "-" +  estado + "-" + ctime(&fecha) ;
        }
    }
};


#endif //TEST_BITACORA_H
