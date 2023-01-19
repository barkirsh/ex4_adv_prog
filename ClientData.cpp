//
// Created by barki on 1/12/2023.
//

#include "ClientData.h"

using namespace std;

ClientData::ClientData(){
    this->k = 5;
    this->distance = "AUC";
    this->train_content = *new vector<string>;
    this->test_content = *new vector<string>;
}

// getter for private member k
int ClientData::getK() {
    return k;
}

// getter for private member distance
string ClientData::getDistance() {
    return distance;
}

// setter for private member k
void ClientData::setK(int new_k) {
    k = new_k;
}

// setter for private member distance
void ClientData::setDistance(string new_distance) {
    distance = new_distance;
}
// getter for private member path_train
vector<string> ClientData::getContentTrain() {
    return train_content;
}
// setter for private member path_train
void ClientData::setContentTrain(vector<string> new_content_train) {
    train_content = new_content_train;
}

// getter for private member path_test
vector<string> ClientData::getContentTest() {
    return test_content;
}
// setter for private member path_test
void ClientData::setContentTest(vector<string> new_content_test) {
    test_content = new_content_test;
}

// getter for private member resultsAlg
vector<string> ClientData::getResultsAlg() {
    return resultsAlg;
}
// setter for private member resultsAlg
void ClientData::setResultsAlg(vector<string> new_resultsAlg) {
    resultsAlg = new_resultsAlg;
}

