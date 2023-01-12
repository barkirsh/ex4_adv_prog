//
// Created by nodo0 on 12/01/2023.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand() {
    this->description = "Uploading the train csv and the test csv";
}

void Command::execute(){


    // first file:
    dio.write("Please upload your local train CSV file.");

    string file1 = dio.read();

    // send to server, check if ok

    // if ok -
    dio.write("Upload complete.");

    // if not ok -
    dio.write("invalid input");
    // return to menu

    // second file -
    dio.write("Please upload your local test CSV file.");

    string file2 = dio.read();

    // send to server, check if ok

    // if ok -
    dio.write("Upload complete.");

    // if not ok -
    dio.write("invalid input");


    // return to menu
}