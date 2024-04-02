
# MiniTalk - a very small communication program using only SIGUSR1 & SIGUSR2 UNIX Signals

MiniTalk is a project for the 2nd level of 42 School, in which we are asked to develop a small communication program using only UNIX Signals; In this case, just SIGUSR1 and SIGUSR2; to send text messages from a client to a server.

Done entirely in C, the characters are sent bit by bit, using bitwise operations. One of the 2 available signals represent one state while the other is used to send the other state.

## Demo:

Here's a little example, sending unicode characters:

## Installation
#### this program only requires Make and a C compiler

If you wanna try it by yourself, clone the repo and simply use "make".

You'll get 2 executables, "client" and "server".

## Usage

Lauch the server first; You'll get it's PID.

Use said PID as an argument for the client, followed by the message to send:



The server can receive multiple messages in a row without a restart, as recquired by the subject.
