// Bar Kirshenboim & Noa Dolev


#include <fstream>
#include "ClientCommand.h"

UploadClientCommand::UploadClientCommand(DefaultIO &dio) : ClientCommand(dio) {
//    this->dio = dio;
}

void UploadClientCommand::fileHandler(ifstream &file) {
    // Read the file line by line
    string line;
    while (getline(file, line)) {//each time reading next line
        dio.write(line);
        dio.read();

    }
    dio.write("upload complete");
    dio.read();
    string complete = dio.read();
    cout << complete << endl;
}


void UploadClientCommand::execute() {
    // get train file
    string msg = this->dio.read();

    // print the message
    cout << msg << endl;

    string str;
    getline(cin, str);

    // get the train file path from the user.
    ifstream file1(str);

    // the file couldn't open
    if (!file1.is_open()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return;
    }
    // the file is empty - exit
    if (file1.eof()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return;
    }

    // send the content to the server
    fileHandler(file1);

    // get test file
    msg = this->dio.read();

    // print the message
    cout << msg << endl;

    getline(cin, str);

    // get the train file path from the user.
    ifstream file2(str);

    // the file couldn't open
    if (!file2.is_open()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return;
    }
    // the file is empty - exit
    if (file2.eof()) {
        cout << "invalid input" << endl;
        dio.write("error");
        return;
    }

    // send the content to the server
    fileHandler(file2);

}