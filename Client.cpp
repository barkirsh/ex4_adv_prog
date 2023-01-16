// Bar Kirshenboim & Noa Dolev

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <fstream>


#include "ValidationClient.h"

using namespace std;

int main(int argc, char *argv[]) {
    // check that we got the right number of arguments.
    if (argc != 3) {
        perror("Wrong Input");
        exit(1);
    }
    // Parse command-line arguments
    char *ip_address = argv[1]; // IP address of server - this computer: "127.0.0.1"
    if (!isValidIP(argv[1])) {
        perror("invalid ip number");
        exit(1);
    }
    if (!isValidPort(argv[2])) {
        perror("invalid port number");
        exit(1);

    }
    int port_no = stoi(argv[2]); // Port number of server


    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        // Socket creation failed
        perror("error creating socket");
        exit(1);

    }
    try {
        // Set up sockaddr_in structure with server information
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin)); // Zero out memory occupied by sin
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(port_no);
        if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("error connecting to server");
            exit(1);

        }
    }
    catch (...) {
        perror("error with ip ");
        exit(1);

    }
    bool inputIsValid;
    bool keepGoing = true;
    char data_addr[4096];
    char buffer[4096];
    string dataToSend;

    while (keepGoing) {
        memset(buffer, 0, sizeof buffer);

        // receiving from user string of input : "vector distType k", get message from user
        std::getline(std::cin, dataToSend);

        dataToSend = strToUpper(dataToSend);
        if (dataToSend == "-1") {
            keepGoing = false;
            continue;
        }
        // checking the input is valid
        inputIsValid = checkInputClient(dataToSend);

        if (!inputIsValid) {
            cout << "invalid input" << endl;
            continue;
        }
            // fit the input, so we will be able to send it to server (char[]) only if valid
        else { // input that was entered is valid, so we will send it to server
            // Convert message to char array
            strcpy(data_addr, dataToSend.c_str());
            // Send message to server
            int data_len = strlen(data_addr);
            int sent_bytes = send(sock, data_addr, data_len, 0);// send something to server
            if (sent_bytes < 0) {
                // Error occurred while sending data
                perror("Error occurred while sending data");
                exit(1);

            }
            // Receive response from server
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                // Connection is closed
                cout << "Connection is closed from server" << endl;
                break;
            } else if (read_bytes < 0) {
                // Error occurred while receiving data
                perror("Error occurred while receiving data");
                exit(1);

            } else {
                // Print response from server, result of knn in our case
                cout << buffer << endl;
            }
        }
    }
    // Close socket
    close(sock);


    return 0;
}
