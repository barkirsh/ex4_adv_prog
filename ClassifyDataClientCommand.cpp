//
// Created by oem on 1/19/23.
//

#include "ClientCommand.h"

ClassifyDataClientCommand::ClassifyDataClientCommand(DefaultIO &dio): ClientCommand(dio) {
    // this->dio = dio;
}

void ClassifyDataClientCommand::execute() {
    string msg = this->dio.read();

    cout << msg << endl;
}