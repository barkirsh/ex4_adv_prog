# ex4_adv_prog

## How to run
- open a terminal window
- write make
- write ./server.out <port nomber>
- open one or more terminal windows
- write ./client.out <ip nomber> <port nomber>


## Big explain
our last project is a server - client based project that contains a menu of actions and the client should choose an option in each level.
the server - client conection works with socketIO based on the TCP protocol.
in advance, our project allows to create a server-client application. The server would use multiple threads to handle incoming connections from multiple clients simultaneously.

## struct
out project looks like this struct:

![image](https://user-images.githubusercontent.com/29839108/213941570-1d7ef5dd-90e9-43a8-a995-055490b9b0ad.png)






### Explanation:
#### client
every client contains - 
1. a commands array that contains all the manu options
2. a socket

#### server  
there is only one server that connect the clients with their CLIs

#### CLI
whan a new client - server connection creates, a new CLI is created for the specific client.
the CLI contains-
1. a commands array that contains all the manu options
2. a ClientData 

#### ClientData
every Client work with an uniqe data.
the Client Data contains - 
1. the k
2. the distance
3. a vector of classified data
4. a vector of unclassified data
5. a vector of the KNN results.
3 - 5 contains data םnly after the appropriate actions.

#### server commands
Each command corresponds to a certain action from the manu.
the commands responsible to the server side of the action.

#### client commands
Each command corresponds to a certain action from the manu.
the commands responsible to the client side of the action.

#### SocketIO
The TCP protocol would be used for the socket communication between the server and clients, providing a reliable and ordered data transfer.
the communication is made by read and write calls.


## Design Pattern
in our project we used the Abstract Factory design pattern.
there is an abstarc class - command and every specific command class that inherit the command class implement the execute() function.
now, whan a user choose an action, we can write:
commands[i].execute() instead of build a switch case and find the right command.

## SocketIO
TCP uses buffers on both the client and server to temporarily store data and control the flow of data between them.
we found out that whan we want to send a few messeges in a row, the TCP unifying tham and send tham together.
this fact created a problam because we didnt know if all the information moved as we wanted.

to deal with this, after every "write", we added "read" and after every "read" we added "write".
in that way, the protocol will not merge a few messeges together because there is a read action in between.

##notice:
when one of the vectors numbers contains e - We require that there be the power after the e specifically - whether negative or positive. we dont eccept e1 for example.
check if the distance is one of the distances
check if the k is a positive number

- notice:
if the k is bigger then the number of lines in the file - the knn will be calculate on the whole file.
In our distance calculations we use precision of 17 since the first assignment
The part of given user input of the distance type, we accept any way of writing a distance that we know to calculate. For example: MAN -> man, MAN, Man, mAn and so on...
