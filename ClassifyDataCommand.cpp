# include "Command.h"
//#include "../DataSetsHandler.h"
#include "Knn.h"

ClassifyDataCommand::ClassifyDataCommand(DefaultIO &dio1, ClientData *cd) : Command(dio1) {
    this->description = "Calculating the knn algorithm";
    this->dio = dio1;
    this->cd = cd;
}

void ClassifyDataCommand:: execute(){
    if(this->cd->getContentTrain().empty() || this->cd->getContentTest().empty()) {
        // if files weren't uploaded
        dio.write("please upload data");
        return;
    }

    // the vec from the client.

    DataSetsHandler classFile; //our file handler, server data handler
    map<vector<double>, string> classifiedMap;
    try {
        // create a map of the classified data
        classifiedMap = classFile.createFileDataSet(this->cd->getContentTrain());
    }  catch (const invalid_argument &ia) {
        this->dio.write("invalid input");
        return;
    }

    // the data set after distance calculations.
    map <vector<double>, string> newDataSet;
    vector<string> results;
    Knn KnnAlg;

    int counter = 1;
    vector<double> unclassifiedVec;
    // create a vector of classified data
    for (string line: this->cd->getContentTest()) {
        // create a vector - check validate:
        try {
            // create vector of double from the string vector - need to check the values.
            unclassifiedVec = classFile.createVector(line);
            //initializing new dataSet (with distances)
            newDataSet = KnnAlg.dataSetForAlg(unclassifiedVec, classifiedMap, this->cd->getDistance(), this->cd->getK());
            //calling our Knn algorithm
            string resultKNN = KnnAlg.mostOccurType(KnnAlg.countTypesAppear(newDataSet, this->cd->getK()));

            //insert the results vector the result and the counter
            results.push_back(to_string(counter) + " " + resultKNN);
            counter += 1;
            // send the answer back to the client.
        } catch (const invalid_argument &ia) {
            this->dio.write("invalid input");
            return;
        }
    }

    this->cd->setResultsAlg(results);
    dio.write("classifying data complete");
}
