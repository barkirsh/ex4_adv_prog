//
// Created by nodo0 on 12/01/2023.
//

#include "UploadCommand.h"

UploadCommand::UploadCommand(ClientData* cd, DefaultIO dio){
    this->description = "Uploading the train csv and the test csv";
    this->dio = dio;
    this->cd = cd;
}

void UploadCommand::execute(){
    vector<string> trainVec = *new vector<string>;
    vector<string> testVec = *new vector<string>;

    // first file:
    dio.write("Please upload your local train CSV file.");

    // the content of the train file
    string train = dio.read();
    while (train != "upload complete") {
        if (train == "error") {
            return;
        }
        trainVec.push_back(train);
        train = dio.read();
    }

    // send to server
    this->cd->setContentTrain(trainVec);
    dio.write("Upload complete.");

    // second file -
    dio.write("Please upload your local test CSV file.");

    // the content of the train file
    string test = dio.read();
    while (test != "upload complete") {
        if (test == "error") {
            return;
        }

        testVec.push_back(test);
        test = dio.read();
    }

    // send to server
    this->cd->setContentTest(testVec);

    dio.write("Upload complete.");
}

