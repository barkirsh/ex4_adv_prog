//
// Created by oem on 1/12/23.
//

#include "SettingCommand.h"

SettingCommand::SettingCommand() {
    this->description = "Print the current settings and update if needed";
}

void Command::execute() {

    // get from the server the string

    string str;
    dio.write(str);

    string change = dio.read();

    if (change.compare("/n")) {
        // return to the menu
    } else {
        // check input :
//        stringstream ss(change);
//        string k;
//        string distance;
//
//        ss >> k;
//        if (!checkInput(k)) {
//            dio.write("invalid value for K");
//            // return to menu
//        }
//
//        ss >> distance;
//        if (!checkInput(distance)) {
//            dio.write("invalid value for metric");
//            // return to menu
//        }

        // send to server the new values.

    }
}