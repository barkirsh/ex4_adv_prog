//
// Created by oem on 1/19/23.
//

#include "ClientCommand.h"

SettingClientCommand::SettingClientCommand(DefaultIO &dio):ClientCommand(dio) {
    //this->dio = dio;
}

void SettingClientCommand::execute() {
    // get train file
    string msg = this->dio.read();

    // print the message
    cout << msg << endl;

    string str;
    getline(cin,str);

    this->dio.write(str);
    if (!str.empty()) {
        string checkK = this->dio.read();
        if (checkK == "invalid value for K") {
            this->dio.write(checkK);
        }
        string checkMetric = this->dio.read();
        if (checkMetric == "invalid value for metric") {
            this->dio.write(checkMetric);
        }
    }
}