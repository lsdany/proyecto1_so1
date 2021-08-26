#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    std::ifstream testFile;
    testFile.open("/home/luisdany/CLionProjects/test/test.txt");
    std::string fileLine;
    if ( testFile.is_open() ) {
        while ( testFile ) { // equivalent to myfile.good()
            std::getline (testFile, fileLine);
            std::cout << fileLine << '\n';
        }
    }
    else {
        std::cout << "unable to open the file\n";
    }
    return 0;

}

