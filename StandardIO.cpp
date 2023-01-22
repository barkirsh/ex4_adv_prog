// Bar Kirshenboim & Noa Dolev


#include "StandardIO.h"

using namespace std;

StandardIO::StandardIO() {}

string DefaultIO::read() {
    string str;
    getline(cin,str);
    return str;
}

void DefaultIO::write(string str) {
    cout << str << endl;
}