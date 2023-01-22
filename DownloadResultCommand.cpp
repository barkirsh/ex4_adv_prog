//
// Created by oem on 1/19/23.
//

#include "Command.h"

DownloadResultCommand::DownloadResultCommand(DefaultIO &dio1, ClientData *cd) : Command(dio1) {
    this->description = "Download the results to a file during continuing the run";
    this->dio = dio1;
    this->cd = cd;
}

void DownloadResultCommand::execute() {
    if (this->cd->getContentTest().empty() || this->cd->getContentTrain().empty()) {
        dio.write("please upload data");
        return;
    }
    if (this->cd->getResultsAlg().empty()) {
        dio.write("please classify the data.");
        return;
    }

    for (string s: this->cd->getResultsAlg()) {
        dio.write(s);
    }
}
