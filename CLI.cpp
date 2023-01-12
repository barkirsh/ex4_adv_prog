//
// Created by oem on 1/12/23.
//

#include "CLI.h"

CLI::CLI() {
    commands[1] = *new UploadCommand();
    commands[2] = *new SettingCommand();
    //commands[3] = *new ClassifyDataCommand();
    //commands[4] = *new DisplayResultCommand();
    //commands[5] = *new DownloadsResultCommand();

    cd = *new ClientData();
}

void CLI::start() {

}