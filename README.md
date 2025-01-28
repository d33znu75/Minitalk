# Minitalk
Minitalk project for 1337 school
![](https://i.imgur.com/5jxapRm.png)

Minitalk is a simple communication program that demonstrates interprocess communication (IPC) using signals in the Unix/Linux environment. It consists of two separate programs: a client and a server. The client and server communicate by sending signals to each other.

Here's a basic overview of how Minitalk works:

+ Client:

The client converts a string message into a series of binary bits.
It then sends each bit as a signal (SIGUSR1 for '1' and SIGUSR2 for '0') to the server.
After sending each bit, the client waits for an acknowledgment signal from the server.

+ Server:

The server receives the signals from the client and reconstructs the binary bits to form the original message.
Once a full character is received, the server sends an acknowledgment signal back to the client.
