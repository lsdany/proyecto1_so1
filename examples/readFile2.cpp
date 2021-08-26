#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    std::ifstream ifs("/home/luisdany/CLionProjects/test/test.txt");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    cout << content;

    return 0;

}

