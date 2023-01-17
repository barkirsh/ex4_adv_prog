//
// Created by barki on 1/12/2023.
//

#ifndef EX5_ADV_PROG_CLIENTDATA_H
#define EX5_ADV_PROG_CLIENTDATA_H

#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

class ClientData {
private:
    int k ;//= 5; // defult k value
    string distance; //= "AUC"; // defult distance 'AUC'
    vector<string> train_content; // classified file
    vector<string> test_content; // unclassified file
    vector<string> resultsAlg;  // results
public:
    ClientData();
    // costructor - defultive
    // getters & setters
    int getK();
    void setK(int new_k);
    string getDistance();
    void setDistance(string new_distance);
    vector<string> getContentTrain();
    void setContentTrain(vector<string> new_path_train);
    vector<string> getContentTest();
    void setContentTest(vector<string> new_path_test);
    vector<string> getResultsAlg();
    void setResultsAlg(vector<string> new_resultsAlg);

};


#endif //EX5_ADV_PROG_CLIENTDATA_H