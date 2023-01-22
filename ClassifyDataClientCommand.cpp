// Bar Kirshenboim & Noa Dolev


#include "ClientCommand.h"

ClassifyDataClientCommand::ClassifyDataClientCommand(DefaultIO &dio) : ClientCommand(dio) {
}

void ClassifyDataClientCommand::execute() {
    // client print the messge about classifying from server
    string msg = this->dio.read();

    cout << msg << endl;
}