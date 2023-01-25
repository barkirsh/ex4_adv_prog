// Bar Kirshenboim & Noa Dolev


#include <fstream>
#include <thread>
#include "ClientCommand.h"

bool hasEnding(string fullString, string ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void DownloadFile(vector<string> vec) {
    string path;
    if (!hasEnding(vec[vec.size() - 1], ".csv")) { // handle only csv files
        path = vec[vec.size() - 1] + "/results.csv";
    } else {
        path = vec[vec.size() - 1];
    }
    ofstream outFile(path);
    if (outFile.is_open()) {
        for (int i = 0; i < vec.size() - 1; i++) {
            outFile << vec[i] << endl;
        }
        outFile.close();
        //    cout << "File written successfully" << endl; -> not needed
    } else {
        //  cout << "Error opening file" << endl;
    }
}

DownloadResultClientCommand::DownloadResultClientCommand(DefaultIO &dio) : ClientCommand(dio) {
}


void DownloadResultClientCommand::execute() {
    string str = this->dio.read();
    this->dio.write("ok");

    if (str == "please upload data" || str == "please classify the data.") {
        cout << str << endl;
        return;
    }

    vector<string> results;
    while (str != "Done.") {
        results.push_back(str);
        str = this->dio.read();
        this->dio.write("ok");
    }

    // cout << "upload file" << endl;
    getline(cin, str);
    results.push_back(str);
    thread t = thread(DownloadFile, results);
    t.detach();
    //DownloadFile(results);
}

