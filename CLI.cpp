//
// Created by oem on 1/12/23.
//

#include "CLI.h"

CLI::CLI(DefaultIO dio){
    this->dio = dio;
    cd = new ClientData();

    commands[1] = new UploadCommand(cd, this->dio);
    commands[2] = new SettingCommand(cd, this->dio);
    commands[3] = new ClassifyDataCommand(cd,this->dio);
    commands[4] = new DisplayResultCommand(cd,this->dio);
    //commands[5] = *new DownloadsResultCommand();


}

void CLI::menu() {
    string str = "Welcome to the KNN Classifier ServerClass. Please choose an option:\n1. upload an unclassified csv"
                 " data file\n2. algorithm settings\n3. classify data\n4. display results\n5. download results\n"
                 "8. exit\n";
    dio.write(str);
}

void CLI::start() {
    string input;
    menu();
    input = this->dio.read();
    int option;
    while (input != "8") {
        try {
            option = stoi(input);
        } catch (const invalid_argument &ia) {
            this->dio.write("invalid input");
            return;
        }
        this->commands[option]->execute();

        menu();
        input = this->dio.read();
    }
}