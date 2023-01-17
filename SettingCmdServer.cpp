//
// Created by barki on 1/17/2023.
//

#include "SettingCmdServer.h"

SettingCmdServer::SettingCmdServer(DefultIO io){
    this->descrbtion = "setting - server";
    this->dio = io;
}
void SettingCmdServer:: execute(ClientData &cd){
    int k = cd.getK;
    string distType = cd.getDistance;

    this->dio.write("The current KNN are: K = " + tostring(k) + "distance metric = "+ tostring(distType));
    string updateSetting = this->dio.read();
    if (updateSetting == ""){ // if client didnt wanted to change alg setting - he pressed -ENTER-
        return;
    }
    //need to prase the string from client and update k & distance
    // cd.setK()
    // cd.setDistance()
}