//
// Created by barki on 1/16/2023.
//

#include "UploadCmdServer.h"

UploadedCmdServer::UploadedCmdServer(DefultIO io) {
    this->describtion = "upload cmd - server";
    this->dio = io;
}

void UploadCmdServer::execute(ClientData &cd) {
// seding client request for uploading train file
    this->dio.write("Please upload your local train CSV file.");
// recieve train file data from client
    string curr_line = this->dio.read();// = this->dio.read();
    cd->train_content.push_back(curr_line); // push curr line to classifiy database (strings vector)
    while (curr_line != "end") {
        curr_line = this->dio.read();
        cd->train_content.push_back(curr_line); // push curr line to classifiy database (strings vector)
    }
// seding client request for uploading test file
    this->dio.write("Please upload your local test CSV file.");
    // recieve test file data from client
    curr_line = this->dio.read();// = this->dio.read();
    cd->test_content.push_back(curr_line); // push curr line to classifiy database (strings vector)
    while (curr_line != "end") {
        curr_line = this->dio.read();
        cd->test_content.push_back(curr_line); // push curr line to classifiy database (strings vector)
    }
// completed uploading
    this->dio.write("Done.");
}