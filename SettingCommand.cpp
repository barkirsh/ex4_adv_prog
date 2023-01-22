// Bar Kirshenboim & Noa Dolev


#include "Command.h"

SettingCommand::SettingCommand(DefaultIO &dio1, ClientData *cd) : Command(dio1) {
    this->description = "Print the current settings and update if needed";
    this->cd = cd;
    this->dio = dio1;
}

void SettingCommand::execute() {
    string str = "The current KNN parameters are: K = " + to_string(this->cd->getK()) + ", distance matric = " +
                 this->cd->getDistance();
    dio.write(str);

    string change = dio.read(); // reading change

    if (change.empty()) {
        return;
    } else {
        // check input :
        stringstream ss(change);
        string k;
        string distance;

        ss >> k;
        if (!KIsValid(k)) {
            dio.write("invalid value for K");
            dio.read();
            ss >> distance;
            if (!CurrStrIsDistance(distance)) {
                dio.write("invalid value for metric");
                dio.read();
                return;
            }
            dio.write("metric is ok");
            dio.read();

        } else {
            dio.write("k is ok");
            dio.read();
            ss >> distance;
            if (!CurrStrIsDistance(distance)) {
                dio.write("invalid value for metric");
                dio.read();
                return;
            }
            dio.write("metric is ok");
            dio.read();


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
        c = toupper(c);
    }
    return word;
}


bool SettingCommand::CurrStrIsDistance(string str) {
    if (str.empty()) {
        return false;
    }
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