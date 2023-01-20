//
// Created by oem on 1/19/23.
//

#include "ClientCommand.h"

SettingClientCommand::SettingClientCommand(DefaultIO &dio):ClientCommand(dio) {
    //this->dio = dio;
}

void SettingClientCommand::execute() {
    string msg = this->dio.read(); // get the curr settings from server
    // print the message
    cout << msg << endl;

    // recieving from user updated K & Distance Type
    string str;
    getline(cin,str);

    this->dio.write(str); // send to server the new settings or ENTER

    if (!str.empty()) { // we tried to change somtehing
        string checkK = this->dio.read();
        dio.write("ok");
        string checkMetric = this->dio.read();
        dio.write("ok");

        if (checkK == "invalid value for K") {
            //this->dio.write(checkK);
        cout<<checkK<<endl;
        }
        //string checkMetric = this->dio.read();
        if (checkMetric == "invalid value for metric") {
          //  this->dio.write(checkMetric);
        cout<< checkMetric << endl;
        }

    }

}