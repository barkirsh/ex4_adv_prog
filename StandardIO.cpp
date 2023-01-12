//
// Created by nodo0 on 12/01/2023.
//

#include "StandardIO.h"

using namespace std;

StandardIO::StandardIO() {}

string StandardIO::read() {
    string str;
    getline(cin,str);
    return str;
}

void StandardIO::write(int str) {
    cout << str << endl;
}