/*
 * Grupo 2, Sistemas operativos
 *
 * Luisdany Israel Pernillo Gonzalez  7690-13-12063
 *
 *
 *
 */



#include <iostream>
#include <fstream>
#include <string>
#include "proceso.h"
#include <vector>

vector<string> getProcessByLine();

vector<Proceso> armarProcesos(vector<string> vector1);

using namespace std;

int main() {


    /*
     * Paso1
     * leer el archivo uno a uno
     * y crear un vector con el total de lineas
     */

    vector<string> lineas = getProcessByLine();

    /*
     * Paso 2
     * Procesar cada linea para armar los objetos de los proceso
     */

    vector<Proceso> procesos = armarProcesos(lineas);

    /*
     * Paso 3
     * crear la logica de los procesos
     */


    /**
     * Paso 4
     * Guardar bitacora, esto se puede ir haciendo durante el paso 3
     * solo se debe tener lista una funcion que requiera un objeto o parametros
     * que se van a escribir en el archivo
     */


    /**
     * Paso 5
     * pintar los procesos
     */


    return 0;

}

vector<Proceso> armarProcesos(vector<string> vector1) {
    size_t posicion = 0;
    vector<Proceso> procesos;

    for (string cadena: vector1){
        cout << "Cadena original: " +cadena << endl;
        string token;
        string delimitador = "|";

        vector<string> v;


        while ((posicion = cadena.find(delimitador)) != std::string::npos) {
            token = cadena.substr(0, posicion);
            cout << token << endl;
            v.push_back(token);
            cadena.erase(0, posicion + delimitador.length());
        }

        cout << v.size() << endl;

        Proceso proceso = Proceso::parseProcess(v);
        proceso.toString();

        //TODO array to object Proceso by index
        /*
         * |0| -> procesoId
         * |1| -> Tema (descripcion)
         * |2| -> Prioridad
         * |3| -> Paternidad
         * |4| -> tiempo de ejecucion
         *
         */

        procesos.push_back(proceso);
    }

    return procesos;
}

//METODO TEMPORAL, VA A SER REEMPLAZADO POR EL METODO DE LECTURA
vector<string> getProcessByLine() {
    vector<string> lineas {"4|Java|1|1|10|"};
    return lineas;
}




