//
// Created by oem on 1/12/23.
//

#include "ServerClass.h"

ServerClass::ServerClass() {
    this -> dio = *new StandardIO;
}

void ServerClass::menu() {
    string str = "Welcome to the KNN Classifier ServerClass. Please choose an option:\n1. upload an unclassified csv"
                 " data file\n2. algorithm settings\n3. classify data\n4. display results\n5. download results\n"
                 "8. exit\n";
    dio.write(str);
}