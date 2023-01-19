//
// Created by barki on 1/17/2023.
//
#include "Command.h"

PrintCmd::PrintCmd(DefaultIO &dio) : Command(dio) {
this->description = "";
}
void PrintCmd::execute(ClientData &cd) {
    string s = "this->dio.read()";
    cout<<s<<endl;
    //this->dio.write("1 2 2 2 ");
}