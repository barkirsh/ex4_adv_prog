//
// Created by barki on 1/17/2023.
//

#include "ClassifyCmdServer.h"
ClassifyCmdServer :: ClassifyCmdServer(DefultIO &dio){
    this->dio = dio;
    this->describtion = "classify cmd - server";
}
void ClassifyCmdServer :: execute(ClientData &cd){
// we will call here to the knn alg handler and update the result db
}