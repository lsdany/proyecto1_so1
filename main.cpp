/*
 * Grupo 2, Sistemas operativos
 *
 * Luisdany Israel Pernillo Gonzalez  7690-13-12063
 * Brya André Recinos Mejía 7690-19-18053
 *
 *


         * |0| -> procesoId
         * |1| -> Tema (descripcion)
         * |2| -> Prioridad
         * |3| -> Paternidad
         * |4| -> tiempo de ejecucion
         *

 *
 *
 */



#include <iostream>
#include <string>
#include "Proceso.h"
#include "Bitacora.h"
#include <vector>
#include <fstream>
#include <unistd.h>

vector<string> getProcessByLine();

vector<Proceso> armarProcesos(vector<string> vector1);

void pintarBitacora(Bitacora bitacora);

vector<Proceso> generarProcesoHijos(vector<Proceso> procesosOriginales);

void procesar(vector<Proceso> vector1);

vector<Proceso> getHijos(vector<Proceso> procesos, int idPadre);

void pintarProcesos(Proceso proceso);

Bitacora getBitacoraByProcess(Proceso proceso);

using namespace std;

string ESTADO_NUEVO{"NUEVO"};
string ESTADO_LISTO{"LISTO"};
string ESTADO_EJECUCION{"EJECUCION"};
string ESTADO_TERMINADO{"TERMINADO"};
string ESTADO_BLOQUEADO{"BLOQUEADO"};

int main() {

    cout << "Proyecto Numero 1 de Sistemas Operativos" << endl;
    cout << "Simulador PCB" << endl;

    /*
     * Paso1
     * leer el archivo uno a uno
     * y crear un vector con el total de lineas
     */

    vector<string> lineas = getProcessByLine();

    /**
     * Paso 2
     * Procesar cada linea para armar los objetos de los Proceso
     */

    vector<Proceso> procesos = armarProcesos(lineas);



    /**
     * Paso 3.1
     * crear procesos hijos
     */

    vector<Proceso> procesosFinal = generarProcesoHijos(procesos);

    /**
     * paso 3.2 procesamiento
     */

    procesar(procesosFinal);

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

void procesar(vector<Proceso> procesos) {

    for (Proceso p: procesos) {

        Bitacora bitacora = getBitacoraByProcess(p);


        // buscar si el proceso tiene hijos
        int idPadre = p.procesoId;
        bitacora.estado = p.estado;
        pintarBitacora(bitacora);

        if (p.paternidad == 0) {
            pintarProcesos(p);

            vector<Proceso> procesosHijos = getHijos(procesos, idPadre);
            if(!procesosHijos.empty()){

                p.estado = ESTADO_BLOQUEADO;
                pintarProcesos(p);
                bitacora.estado = p.estado;
                pintarBitacora(bitacora);

                for (Proceso pHijo: procesosHijos) {

                    Bitacora bitacoraHijo = getBitacoraByProcess(pHijo);

                    pintarProcesos(pHijo);

                    pHijo.estado = ESTADO_LISTO;
                    bitacoraHijo.estado = pHijo.estado;
                    pintarBitacora(bitacoraHijo);
                    pintarProcesos(pHijo);

                    pHijo.estado = ESTADO_EJECUCION;
                    bitacoraHijo.estado = pHijo.estado;
                    pintarBitacora(bitacoraHijo);
                    pintarProcesos(pHijo);

                    sleep(pHijo.tiempoEjecucion);

                    pHijo.estado = ESTADO_TERMINADO;
                    pintarProcesos(pHijo);
                    bitacoraHijo.estado = pHijo.estado;
                    pintarBitacora(bitacoraHijo);
                }
            }

            p.estado = ESTADO_LISTO;
            pintarProcesos(p);
            bitacora.estado = p.estado;
            pintarBitacora(bitacora);

            p.estado = ESTADO_EJECUCION;
            pintarProcesos(p);
            bitacora.estado = p.estado;
            pintarBitacora(bitacora);

            sleep(p.tiempoEjecucion);

            p.estado = ESTADO_TERMINADO;
            pintarProcesos(p);
            bitacora.estado = p.estado;
            pintarBitacora(bitacora);

        }

    }


}

Bitacora getBitacoraByProcess(Proceso proceso) {
    Bitacora bitacora;
    bitacora.id = proceso.procesoId;
    bitacora.accion = "Cambia de estado";
    bitacora.nombreProceso = proceso.tema;
    return bitacora;
}

vector<Proceso> getHijos(vector<Proceso> procesos, int idPadre) {
    vector<Proceso> hijos;
    for (Proceso p: procesos) {
        if (p.paternidad == idPadre) {
            hijos.push_back(p);
        }
    }

    Bitacora bitacora;
    bitacora.accion = "Buscando procesos hijos para el proceso " + to_string(idPadre);
    bitacora.estado = ESTADO_TERMINADO;
    pintarBitacora(bitacora);
    return hijos;
}

vector<Proceso> generarProcesoHijos(vector<Proceso> procesosOriginales) {
    size_t tP = procesosOriginales.size();
    int totalProcesos = static_cast<int>(tP);

    vector<Proceso> procesosConHijos;
    int contadorProcesos{1};
    for (int i = 0; i < procesosOriginales.size(); i++) {
        Proceso p = procesosOriginales[i];

        p.estado = ESTADO_NUEVO;
        procesosConHijos.push_back(p);

        int contadorHijos{1};

        for (int j = 0; j <= contadorProcesos; j++) {
            Proceso pHijo;
            pHijo.procesoId = totalProcesos++;
            pHijo.tema = p.tema + "_hijo" + to_string(contadorHijos++);
            pHijo.prioridad = p.prioridad;
            pHijo.paternidad = p.procesoId;
            pHijo.tiempoEjecucion = p.tiempoEjecucion;
            pHijo.estado = ESTADO_NUEVO;
            procesosConHijos.push_back(pHijo);
        }
        contadorProcesos++;
    }

    Bitacora bitacora;
    bitacora.accion = "Creacion de procesos hijos, total de procesos: " + to_string(procesosConHijos.size());
    bitacora.estado = ESTADO_TERMINADO;

    pintarBitacora(bitacora);

    return procesosConHijos;

//    cout << "Total de proceso creados: " << procesosConHijos.size() << endl;
//    for (Proceso p: procesosConHijos) {
//        p.toString();
//    }
}

vector<Proceso> armarProcesos(vector<string> vector1) {
    size_t posicion = 0;
    vector<Proceso> procesos;

    for (string cadena: vector1) {
        string token;
        string delimitador = "|";

        vector<string> v;


        while ((posicion = cadena.find(delimitador)) != std::string::npos) {
            token = cadena.substr(0, posicion);
            v.push_back(token);
            cadena.erase(0, posicion + delimitador.length());
        }

        Proceso proceso = Proceso::parseProcess(v);

        procesos.push_back(proceso);
    }

    Bitacora bitacora;
    bitacora.accion = "Lectura de Procesos ";
    bitacora.estado = ESTADO_TERMINADO;
    pintarBitacora(bitacora);

    return procesos;
}

/*
 * Metodo para la lectura del archivo necesario para leer proceso por proceso
 * TODO validar la existencia del archivo, que pasa sino hay archivo
 */
vector<string> getProcessByLine() {
    string ruta;
    cout << "Ingresa la ruta de su archivo: ";
    cin >> ruta;
    string linea, texto;
    ifstream archivo(ruta);
    vector<string> lineas;
    int contador{0};
    while (getline(archivo, linea)) {
        texto = linea;
        if (contador != 0) {
            lineas.push_back(texto);
        }
        contador++;
    }

    Bitacora bitacora;
    bitacora.accion = "Lectura de archivo ";
    bitacora.estado = ESTADO_TERMINADO;

    archivo.close();

    pintarBitacora(bitacora);

    return lineas;
}

/**
 * Metodo de ejemplo para la bitacora
 * @param bitacora
 */
void pintarBitacora(Bitacora bitacora) {

    string text(bitacora.print());
    string filename("bitacora.txt");
    fstream file;

    file.open(filename, std::ios_base::app);
    if (file.is_open()) {
        file.write(text.data(), text.size());
    }
    file.close();
}


void pintarProcesos(Proceso proceso) {

    time_t hora{time(0)};
    char *horaChar = ctime(&hora);

    cout << "            -------" << endl;
    cout << "Proceso ID: "<< "|  " << proceso.procesoId << "  | -----> " << proceso.estado << " " << horaChar;
    cout << "            -------" << endl;
}



