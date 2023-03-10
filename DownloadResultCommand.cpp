// Bar Kirshenboim & Noa Dolev


#include "Command.h"

DownloadResultCommand::DownloadResultCommand(DefaultIO &dio1, ClientData *cd) : Command(dio1) {
    this->description = "Download the results to a file during continuing the run";
    this->dio = dio1;
    this->cd = cd;
}

void DownloadResultCommand::execute() {
    if (this->cd->getContentTest().empty() || this->cd->getContentTrain().empty()) {
        dio.write("please upload data");
        dio.read();
        return;
    }
    if (this->cd->getResultsAlg().empty()) {
        dio.write("please classify the data.");
        dio.read();
        return;
    }

    for (string s: this->cd->getResultsAlg()) {
        dio.write(s);
        dio.read();
    }
    dio.write("Done.");
    dio.read();
}
