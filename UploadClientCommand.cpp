//
// Created by oem on 1/19/23.
//

#include <fstream>
#include "ClientCommand.h"

UploadClientCommand::UploadClientCommand(DefaultIO dio) {
    this->dio = dio;
}

bool UploadClientCommand::fileHandler(ifstream &file) {
    // the file couldn't open
    if (!file.is_open()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return false;
    }
    // the file is empty - exit
    if (file.eof()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return false;
    }

    // Read the file line by line
    string line;
    while (getline(file, line)) {//each time reading next line
        dio.write(line);
        dio.read();

    }
    dio.write("upload complete");
    return true;
}


void UploadClientCommand::execute() {
    // get train file
    string msg = this->dio.read();

    // print the message
    cout << msg << endl;

    string str;
    getline(cin,str);

    // get the train file path from the user.
    ifstream file1(str);

    // send the content to the server
    bool isOK = fileHandler(file1);

    if (isOK) {
        // get test file
        msg = this->dio.read();

        // print the message
        cout << msg << endl;

        getline(cin,str);

        // get the train file path from the user.
        ifstream file2(str);

        // send the content to the server
        fileHandler(file2);
    }
}