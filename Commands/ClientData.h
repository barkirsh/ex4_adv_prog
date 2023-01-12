//
// Created by barki on 1/12/2023.
//

#ifndef EX5_ADV_PROG_CLIENTDATA_H
#define EX5_ADV_PROG_CLIENTDATA_H


class ClientData {
private:
    private int k ;//= 5; // defult k value
    private string distance; //= "EUC"; // defult distance 'AUC'
    private string path_train; // classified file
    private string path_test; // unclassified file
    private vector<string> resultsAlg;
public:
    ClientData();
    // costructor - defultive
    // getters & setters
};


#endif //EX5_ADV_PROG_CLIENTDATA_H
