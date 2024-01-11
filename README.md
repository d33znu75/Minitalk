# Minitalk
Minitalk project for 1337 school
![](https://cdn.discordapp.com/attachments/1067452256686981161/1195006459709239306/Screen_Shot_2024-01-11_at_3.05.55_PM.png?ex=65b26b7e&is=659ff67e&hm=450388adee1841076f7e0fa50683858f470b0d5a84a9c9a37ed9220d2dcf6533&)

Minitalk is a simple communication program that demonstrates interprocess communication (IPC) using signals in the Unix/Linux environment. It consists of two separate programs: a client and a server. The client and server communicate by sending signals to each other.

Here's a basic overview of how Minitalk works:

+ Client:

The client converts a string message into a series of binary bits.
It then sends each bit as a signal (SIGUSR1 for '1' and SIGUSR2 for '0') to the server.
After sending each bit, the client waits for an acknowledgment signal from the server.

+ Server:

The server receives the signals from the client and reconstructs the binary bits to form the original message.
Once a full character is received, the server sends an acknowledgment signal back to the client.
