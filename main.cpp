#include <iostream>
#include <fstream>
#include <string>
#include "proceso.h"

using namespace std;

int main() {

    std::ifstream ifs("/home/luisdany/CLionProjects/test/test.txt");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    cout << content + "\n";

    std::string delimitador = "|";

    size_t pos = 0;
    std::string token;
    while ((pos = content.find(delimitador)) != std::string::npos) {
        token = content.substr(0, pos);
        std::cout << token << std::endl;
        content.erase(0, pos + delimitador.length());
    }
    std::cout << content << std::endl;

    Proceso proc;
    proc.procesoId = "1";

    cout << proc.procesoId;


    return 0;

}


void parseString2(){
//    string input("geeks\tfor\tgeeks");
//    vector<string> result;
//    boost::split(result, input, boost::is_any_of("\t"));
//
//    for (int i = 0; i < result.size(); i++)
//        cout << result[i] << endl;
}

