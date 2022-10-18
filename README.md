# minitalk

## Description

The aim of the project is to introduce us to signals and signals handling. To do this we have created two binaries: client and sever.
Client take as first parameter procces id of server and it will be used to send a message that is second argument
char* string. So client send the message bit by bit to the server by server's PID.
A message can include any unicode symbol.
To protect from collisions like two or more clients send messages to the same server i made a protection.
While client in proccess of sending message the server knows current PID of client and client wait server send signal back that indicates to going on nex bit.

## Compilling

Makefile creates two required binaries.
