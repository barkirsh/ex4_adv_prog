# include "DisplayResultCommand.h"
DisplayResultCommand::DisplayResultCommand(ClientData *cd, DefaultIO dio) {
    this->description = "display results to client";
    this->cd = cd;
    this->dio = dio;
}

// displaying for each raw of test file it classification
void  DisplayResultCommand:: execute() {
    if (this->cd->getContentTest().empty() ||this->cd->getContentTrain().empty()) {
        dio.write("please upload data");
        return;
    }
    if (this->cd->getResultsAlg().empty()) {
        dio.write("please classify the data.");
        return;
    }

    for (string s:this->cd->getResultsAlg()) {
        dio.write(s);
    }
    dio.write("Done.");
}