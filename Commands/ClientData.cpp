//
// Created by barki on 1/12/2023.
//



#include "ClientData.h"

using namespace std;

ClientData::ClientData(){
    this->k = 5;
    this->distance = "EUC";
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
string ClientData::getPathTrain() {
    return path_train;
}
// setter for private member path_train
void ClientData::setPathTrain(string new_path_train) {
    path_train = new_path_train;
}

// getter for private member path_test
string ClientData::getPathTest() {
    return path_test;
}
// setter for private member path_test
void ClientData::setPathTest(string new_path_test) {
    path_test = new_path_test;
}

// getter for private member resultsAlg
vector<string> ClientData::getResultsAlg() {
    return resultsAlg;
}
// setter for private member resultsAlg
void ClientData::setResultsAlg(vector<string> new_resultsAlg) {
    resultsAlg = new_resultsAlg;
}

