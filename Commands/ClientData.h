//
// Created by barki on 1/12/2023.
//

#ifndef EX5_ADV_PROG_CLIENTDATA_H
#define EX5_ADV_PROG_CLIENTDATA_H


class ClientData {
private:
     int k ;//= 5; // defult k value
     string distance; //= "EUC"; // defult distance 'AUC'
     string path_train; // classified file
     string path_test; // unclassified file
     vector<string> resultsAlg;
public:
    ClientData();
    // costructor - defultive
    // getters & setters
    int getK();
    void setK(int new_k);
    string getDistance();
    void setDistance(string new_distance);
    string getPathTrain();
    void setPathTrain(string new_path_train);
    string getPathTest();
    void setPathTest(string new_path_test);
    vector<string>& getResultsAlg();
    void setResultsAlg(vector<string> new_resultsAlg);

};


#endif //EX5_ADV_PROG_CLIENTDATA_H
