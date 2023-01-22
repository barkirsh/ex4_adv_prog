// Bar Kirshenboim & Noa Dolev


#include "ClientCommand.h"

DisplayResultClientCommand::DisplayResultClientCommand(DefaultIO &dio) : ClientCommand(dio) {
    // this->dio = dio;
}

void DisplayResultClientCommand::execute() {
    string str = this->dio.read(); //  get condition from
    this->dio.write("ok"); // recieved from server
// if there is a problem
    if (str == "please upload data" || str == "please classify the data.") {
        cout << str << endl;
        this->dio.write("ok");
        return;
    }

    while (str != "Done.") {
        cout << str << endl;
        str = this->dio.read();
        this->dio.write("ok");
    }

    cout << str << endl;
}