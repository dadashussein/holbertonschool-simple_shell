# holbertonschool-simple_shell

#### Compilation

Your shell will be combined with this way

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

#### Testing

Your shell should work like this in interactive mode:

``` c
./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

#### Checks

The Checker will be released at the end of the project (1-2 days before the deadline). We strongly encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task `8. Test suite.`

#### Copyright - Plagiarism

* You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
* You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
* You are not allowed to publish any content of this project.
* Any form of plagiarism is strictly forbidden and will result in removal from the program.

## Tasks

0. - [ ] **Betty would be proud**
1. - [ ] **Simple shell 0.1**
2. - [ ] **Simple shell 0.2**
3. - [ ] **Simple shell 0.3**
4. - [ ] **Simple shell 0.4**
5. - [ ] **Simple shell 1.0**
6. - [ ] **Simple shell 0.1.1**
7. - [ ] **Simple shell 0.2.1**
8. - [ ] **Simple shell 0.4.1**
9. - [ ]**setenv, unsetenv**
10. - [ ]**cd**
11. - [ ]** ;**
12. - [ ]**&& and ||**
13. - [ ]**alias**
14. - [ ]**Variables**
15. - [ ]**Comments**
16. - [ ]**File as input**


### Task 0

Write a beautiful code that passes the Betty checks

### Task 1

Write a UNIX command line interpreter.

* Usage: simple_shell
Your Shell should:

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

* use the PATH
* implement built-ins
* handle special characters : ", ', `, \, *, &, #
* be able to move the cursor
* handle commands with arguments

`execve` *will be the core part of your Shell, don’t forget to pass the environ to it…*

``` shell
julien@ubuntu:~/shell$ ./shell 
#cisfun$ ls
./shell: No such file or directory
#cisfun$ /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ /bin/ls -l
./shell: No such file or directory
#cisfun$ ^[[D^[[D^[[D
./shell: No such file or directory
#cisfun$ ^[[C^[[C^[[C^[[C
./shell: No such file or directory
#cisfun$ exit
./shell: No such file or directory
#cisfun$ ^C
julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
#cisfun$ julien@ubuntu:~/shell$
```

### Task 2

Simple shell 0.1 +

* Handle command lines with arguments

### Task 3

Simple shell 0.2 +

* Handle the PATH
* fork must not be called if the command doesn’t exist

### Task 4

Simple shell 0.3 +

* Implement the exit built-in, that exits the shell
* Usage: exit
* You don’t have to handle any argument to the built-in exit

### Task 5

Simple shell 0.4 +

* Implement the env built-in, that prints the current environment

``` shell
julien@ubuntu:~/shell$ ./simple_shell
$ env
USER=julien
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/julien
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=julien
TERM=xterm-256color
PATH=/home/julien/bin:/home/julien/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
$ exit
julien@ubuntu:~/shell$ 
```

### Task 6

Simple shell 0.1 +

* Write your own getline function
* Use a buffer to read many chars at once and call the least possible the read system call
* You will need to use static variables
* You are not allowed to use getline

You don’t have to:

