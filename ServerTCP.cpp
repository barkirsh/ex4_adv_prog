//
// Created by barki on 1/13/2023.
//

#include "ServerTCP.h"

/**
 * constructor ServerTCP -> get the port for connect server to
 */
ServerTCP::ServerTCP(int server_port) {
    // creating socket
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
    // binding server to socket
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        exit(1);
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        exit(1);
    }
}

/**
 * new client is added to server -> create the thread that handle that client?
 */
void ServerTCP::newClient(int client_socket) {

}
/**
 *  the program that each thread will execute, reciving & sending to client...
 *  doesnt know how it relate to commands here
 * @param client_sock
 */
void ServerTCP::runClient(int client_sock) {
    cout<<"created thread for client num"<<client_sock<<endl;
    char buffer[4096];
    int expected_data_len = sizeof(buffer);

    bool closeSock = false; // finishing program - in the future happen when input is '-1'
    int read_bytes;
    int sent_bytes;
    //files
    Knn KnnAlg;
    DataSetsHandler classFile; //our file handler, server data handler
    ifstream file("iris_classified.csv");// for now, keep the classified file

    map <vector<double>, string> dataSet = classFile.createFileDataSet(file);
    map <vector<double>, string> newDataSet;
    // the vec from the client.
    vector<double> inputVec;
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
    cout<<"disconnecting client : "<<client_sock<<endl;
}


/**
 * stating server side
 */
void ServerTCP::listen() {


    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);

    thread forcli[5];
    int num_of_client = 0;
    while (true) { // listener
        int client_sock = accept(this->_sock, (struct sockaddr *) &client_sin, &addr_len);// accepting new client
        if (client_sock < 0) {
            // forcli.join();
            perror("error accepting client client sock res<0");
        }
        if (num_of_client == 3){
            break;
        }
        else{ // need to create new thread and call function of thread

            forcli[num_of_client] = thread(clientThread,client_sock);
            num_of_client++;
        }
    }
    //forcli.join();
    forcli[0].join();
    forcli[1].join();
    forcli[2].join();

    close(this->_sock);
    return 0;


}

