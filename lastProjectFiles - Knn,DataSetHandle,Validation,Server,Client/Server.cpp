// Bar Kirshenboim & Noa Dolev
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>

#include "Knn.h"

/**
* funcName: stringTpParts
* this function takes parts from the string and push them into the vector.
* @param str - the full string
* @param delim - the last char of the sub string
* @param out - the answer
* @return a vector with the substring in it
*/
void stringToParts(string &str, char delim, vector <string> &out) {
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

/**
* funcName: stringToVectorString
* this function create a vector with the full string (v0,v1,...,vn,distance,k).
* @param s - the string we want to convert
* @return a vector with the substrings in it
*/
vector <string> stringToVectorString(string s) {
    char d = ' ';
    vector <string> strVector;
    stringToParts(s, d, strVector);

    return strVector;
}

/**
* funcName: kFromString
* this function return k from the vector - the last var of the vector
* @param vec - the vector
* @return the k
*/
int kFromString(vector <string> &vec) {
    string k_string = vec.at(vec.size() - 1);
    vec.pop_back();
    return stoi(k_string);
}

/**
* funcName: distanceFromString
* this function return the distance type from the vector - the last var after k left
* @param vec - the vector
* @return the distance type
*/
string distanceFromString(vector <string> &vec) {
    string dist_type = vec.at(vec.size() - 1);
    vec.pop_back();
    return dist_type;
}

int main(int argc, char *argv[]) {
    // check that we got the right number of arguments.
    if (argc != 3) {
        perror("Wrong Input");
        exit(1);
    }

    // get the port and create the socket
    if (!isValidPort(argv[2])) {
        perror("invalid port number");
        exit(1);
    }
    int server_port = stoi(argv[2]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // failed create the socket
    if (sock < 0) {
        perror("error creating socket");
        exit(1);
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        exit(1);
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    //files
    Knn KnnAlg;
    DataSetsHandler classFile; //our file handler, server data handler

    // get the file path from the argv.
    ifstream file(argv[1]);

    // the file couldn't open
    if (!file.is_open()) {
        perror("Failed to open file");
        exit(1);

    }
    // the file is empty - exit
    if (file.eof()) {
        perror("The file is empty");
        exit(1);

    }

    // the vec from the client.
    vector<double> inputVec;

    // the file data set.
    map <vector<double>, string> dataSet = classFile.createFileDataSet(file);

    // the data set after distance calculations.
    map <vector<double>, string> newDataSet;

    // our actual program, until now - only socket and file stuff.
    char buffer[4096];
    int expected_data_len = sizeof(buffer);

    bool closeSock = false; // finishing program - in the future happen when input is '-1'
    int read_bytes;
    int sent_bytes;
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);

        if (client_sock < 0) {
            perror("error accepting client");
        }
        while (!closeSock) {
            memset(buffer, 0, expected_data_len);

            // receiving char* str[] of the user input(vector,dist,k) into buffer
            read_bytes = recv(client_sock, buffer, expected_data_len, 0);

            //something went wrong with receiving input from client - not our responsibility
            if (read_bytes == 0) {
                // connection is closed
                close(client_sock);
                break;
            } else if (read_bytes < 0) {
                close(client_sock);
                break;
            } else {
                // convert the char*[] to string
                string allData = buffer;
                // convert string to vector of strings
                vector <string> string_vector = stringToVectorString(allData);
                // get k
                int k = kFromString(string_vector);
                // get distance type
                string distType = distanceFromString(string_vector);

                try {
                    // create vector of double from the string vector - the values are valid, checked in the client.
                    inputVec = classFile.createVectorFromVectorString(string_vector);
                    //initializing new dataSet (with distances)
                    newDataSet = KnnAlg.dataSetForAlg(inputVec, dataSet, distType, k);
                    //calling our Knn algorithm
                    string resultKNN = KnnAlg.mostOccurType(KnnAlg.countTypesAppear(newDataSet, k));
                    // convert the result to char*[]
                    strcpy(buffer, resultKNN.c_str());
                    // send the answer back to the client.
                } catch (const invalid_argument &ia) {
                    strcpy(buffer, "invalid input");
                    sent_bytes = send(client_sock, buffer, sizeof(buffer), 0);
                    continue;
                }
            }

            //sending message to client - in future this will be the result of KNN
            sent_bytes = send(client_sock, buffer, sizeof(buffer), 0);

            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
    }
    close(sock);
    return 0;
}


