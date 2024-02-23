# Simple Shell

A simple UNIX command line shell program written in C. 

## Description

This shell program implements basic functionality of a UNIX command line shell including:

- Reading commands from stdin
- Parsing commands into arguments 
- Executing commands by calling execve()
- Handling I/O redirection using pipes 
- Implementing basic built-in commands like cd, exit
- Proper error handling for system calls

The goal of the project was to learn the fundamentals of how a shell program works under the hood by creating a basic but working shell from scratch.

## Features

- Support for executing external commands by path lookup using the PATH environment variable
- Argument parsing using strtok() to break the command line into individual arguments
- Support for piping between commands using fork() and dup2()
- Implemented built-in commands cd and exit
- Signal handling for Ctrl-C with SIGINT
- Proper error checking and return codes for system calls

## Usage

To build and run the shell:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Example usages:

```
ls -l 
pwd
exit
```


This was a fun learning project to understand the internals of how a simple shell works. Please feel free to check it out and provide any feedback!

## Links

Project Repo: https://github.com/dadashussein/holbertonschool-simple_shell

LinkedIn Profile: hhttps://www.linkedin.com/in/dadashussein/

Let me know if you have any other questions!