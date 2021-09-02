/*
 * Grupo 2, Sistemas operativos
 *
 * Luisdany Israel Pernillo Gonzalez  7690-13-12063
 * Brya André Recinos Mejía 7690-19-18053
 *
 *
 *
 */



#include <iostream>
#include <string>
#include "Proceso.h"
#include "Bitacora.h"
#include <vector>

vector<string> getProcessByLine();

vector<Proceso> armarProcesos(vector<string> vector1);

using namespace std;

string ESTADO_INICIAL {"nuevo"};
string ESTADO2 {"listo"};

int main() {


    /*
     * Paso1
     * leer el archivo uno a uno
     * y crear un vector con el total de lineas
     */

    vector<string> lineas = getProcessByLine();

    /*
     * Paso 2
     * Procesar cada linea para armar los objetos de los Proceso
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

//METODO YA REMPLAZADO PARA LEER EL ARCHIVO DESDE LA RUTA ESPESIFICADA POR EL USUARIO EN CONSOLA
vector<string> getProcessByLine()
{        
    string ruta;
    cout << "Ingresa la ruta de su archivo: ";
    cin >> ruta;
    string linea, texto;
    ifstream archivo(ruta);
    vector<string> lineas;
    while (getline(archivo, linea)){
    texto = linea;
    lineas.push_back(texto);   
    }
    archivo.close();
    return lineas;
}

/**
 * Metodo de ejemplo para la bitacora
 * @param bitacora
 */
void pintarBitacora(Bitacora bitacora){

    cout << bitacora.nombreProceso << endl;
    cout << bitacora.id << endl;

}




