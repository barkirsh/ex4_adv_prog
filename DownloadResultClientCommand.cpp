//
// Created by oem on 1/19/23.
//

#include "ClientCommand.h"

DownloadResultClientCommand::DownloadResultClientCommand(DefaultIO &dio) : ClientCommand(dio) {
}

void DownloadResultClientCommand::execute() {
    string str = this->dio.read();
    this->dio.write("ok");

    if (str == "please upload data" || str == "please classify the data.") {
        cout << str << endl;
        return;
    }

    while (str != "Done.") {
        cout << str << endl;
        str = this->dio.read();
        this->dio.write("ok");
    }
    this->dio.write("ok");
}