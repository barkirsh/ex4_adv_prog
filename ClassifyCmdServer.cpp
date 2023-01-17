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

for(int i = 0 ; i< cd->test_content.size();i++){
    // apply alg on one unclassified vector from text DB and enter result to result vector
    //initializing new dataSet (with distances)
//    newDataSet = KnnAlg.dataSetForAlg(inputVec, dataSet, distType, k);
//    //calling our Knn algorithm
//    string resultKNN = KnnAlg.mostOccurType(KnnAlg.countTypesAppear(newDataSet, k));
// result.push(resuktKNN)
}
}