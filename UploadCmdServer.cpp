//
// Created by barki on 1/16/2023.
//

#include "UploadCmdServer.h"

void UploadCmdServer:: execute(&ClientData cd){
    this.dio.write("please upload csv classifier file:");
    string line_of_file = this.dio.read();

    this.dio.write("please upload csv classifier file:");
}