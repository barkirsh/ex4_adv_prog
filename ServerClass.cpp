//
// Created by oem on 1/12/23.
//

#include "ServerClass.h"

ServerClass::ServerClass(int server_port) :port(server_port),sock(socket(AF_INET,SOCK_STREAM,0)){
   // this -> dio = *new SocketIO(this.);
   if (this->sock < 0){
       perror("ERROR : create socket");
   }
    struct sockaddr_in sin;
    memset(&sin, 0 , sizeof (sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons((this->port));

    if(bind(sock,(struct sockaddr *)&sin,sizeof (sin))<0){
        perror("ERROR : bind socket");
        exit(1);
    }
}
void ServerClass:: handleClient(int client_socket) {
    SocketIO sio{client_socket};// = new SocketIO(client_socket); //
    cout<< "we accepted new client to program, client sock is: "<< to_string(client_socket)<<endl;
    CLI cli(sio);
    cli.start();
    cout<< " client disconnect, client sock is: "<< to_string(client_socket)<<endl;

}
void ServerClass :: start(){
    int client_socket;

    if (listen(this->sock,5)<0){
        perror("ERROR : listen socket");
        exit(1);
    }
    cout<<"The server is open and ready to accept"<< endl;

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof (client_sin);
    while(true){
         client_socket = accept(this->sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_socket < 0) {
            perror("ERROR : accept client");
        } else { // here we accept a new client
            handleClient(client_socket);
        }
    }

}

bool isValidPort(const string& str) {
    int portNum;
    try {
        portNum = stoi(str);
        if (portNum < 1024 || portNum > 65535) {
            return false;
        }
    }
    catch (const invalid_argument &ia) {
        return false;
    }
    return true;
}

bool checkArgs (int argc, char *argv[]) {
    // check that we got the right number of arguments.
    if (argc != 2) {
        perror("Wrong Input");
        exit(1);
    }

    bool checkPort = isValidPort(argv[1]);
    if (checkPort) {
        return true;
    }
    return false;
}




int main(int argc, char *argv[]){


    if (!checkArgs(argc,argv)) {
        exit(1);
    }

    ServerClass server = *new ServerClass(stoi(argv[1])); // creating serverClass
    server.start();


    }
