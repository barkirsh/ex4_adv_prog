//
// Created by oem on 1/12/23.
//

#include "CLI.h"

CLI::CLI(DefaultIO &dio1) :dio(dio1){
    // this->dio = dio;
    cd = new ClientData();
    commands[1] = new UploadCommand(this->dio, cd);
    commands[2] = new SettingCommand(this->dio, cd);
    commands[3] = new ClassifyDataCommand(this->dio, cd);
    commands[4] = new DisplayResultCommand(this->dio, cd);
    commands[5] = new DownloadResultCommand(this->dio, cd);


}

void CLI::menu() {
    string str = "Welcome to the KNN Classifier ServerClass. Please choose an option:\n1. upload an unclassified csv"
                 " data file\n2. algorithm settings\n3. classify data\n4. display results\n5. download results\n"
                 "8. exit\n";
    dio.write(str);
}

void CLI::start() {
    //string input;
    menu(); // write menu first time
    string input = this->dio.read();
    int option;
    bool isLegal = true;
    while (input != "8") {
        try {
            option = stoi(input);
            if (option < 1 || option > 5) {
                throw invalid_argument("Wrong Input");
            }
        } catch (const invalid_argument &ia) {
            this->dio.write("invalid input");
            isLegal = false;
        }
        if (isLegal) {
            this->commands[option]->execute();
        }

        menu();
        //input = "";
        input = this->dio.read();
    }
    deleteAll();
    // close connection
}

void CLI::deleteAll() {
    for (int i = 5; i > 0; i--) {
        delete this->commands[i];
    }
    delete this->cd;
}