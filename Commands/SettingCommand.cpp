//
// Created by oem on 1/12/23.
//

#include "SettingCommand.h"

SettingCommand::SettingCommand(ClientData *cd, DefaultIO dio) {
    this->description = "Print the current settings and update if needed";
    this->cd = cd;
    this->dio = dio;
}

void SettingCommand::execute() {
    string str = "The current KNN parameters are: K = " + to_string(this->cd->getK()) + ", distance matric = " +
                 this->cd->getDistance();
    dio.write(str);

    string change = dio.read();

    if (change == "") {
        return;
    } else {
        // check input :
        stringstream ss(change);
        string k;
        string distance;

        ss >> k;
        if (!KIsValid(k)) {
            dio.write("invalid value for K");
            return;
        }

        ss >> distance;
        if (!CurrStrIsDistance(distance)) {
            dio.write("invalid value for metric");
            return;
        }

        this->cd->setK(stoi(k));
        this->cd->setDistance(distance);
        return;
    }
}

bool SettingCommand::KIsValid(string check) {
    int k;
    try {
        k = stoi(check);
    } catch (const invalid_argument &ia) {
        return false;
    }
    if (k <= 0) {
        return false;
    }
    return true;
}

string SettingCommand::strToUpper(string word) {
    for (char &c: word) {
        c = std::toupper(c);
    }
    return word;
}


bool SettingCommand::CurrStrIsDistance(string str) {
    str = strToUpper(str);
    if (str == "AUC") {
        return true;
    } else if (str == "MAN") {
        return true;
    } else if (str == "CHB") {
        return true;
    } else if (str == "CAN") {
        return true;
    } else if (str == "MIN") {
        return true;
    } else {        // the given string that suppose to be a distance type isn't a distance
        return false;
    }
}