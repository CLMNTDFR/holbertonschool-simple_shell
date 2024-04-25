# HOLBERTON SCHOOL SIMPLE SHELL PROJECT
 
## DESCRIPTION
This is the repository for our project for [Holberton School](https://www.holbertonschool.fr/).
The project consisted in coding `hsh`, a simplified and custom version of `sh` *Bourne Shell*.
This project was carried out as part of the fundamentals curriculum, and in a team of two people, over a period of two weeks.

## TABLE OF CONTENTS
- [OVERVIEW](#overview)
- [FEATURES](#features)
- [BUILT-INS](#built-ins)
	- [Exit](#exit)
	- [Env](#env)
- [SOFTWARE INSTALLATION AND COMPILATION](#software-installation-and-compilation)
- [EXAMPLES](#examples)
	- [Interactive](#interactive)
	- [Non Interactive](#non-interactive)
- [LIBRARIES USED](#libraries-used)
- [PROJECT FILES DESCRIPTION](#project-files-description)
- [UML DIAGRAM OVERVIEW](#uml-diagram-overview-unified-modeling-language)
- [AUTHORS](#authors)
- [LICENSE](#license)
 
## OVERVIEW
`hsh` is a custom UNIX command line interpreter, coded in pure **C** language. It reads and executes commands from the standard input, with memory management and error handling implemented.

## FEATURES
`hsh` operates in two modes: `interactive` and `non-interactive`. It effectively manages command lines with arguments and paths.
 
## BUILT-INS
The following built-ins functions have been implemented:

### • Exit
* Usage: `exit`
* Quits `hsh` 

```
$ ./hsh
$ exit
```
 
### • Env
* Usage: `env`
* Prints the current environment

```
$ env
LANGUAGE=en_US:en
PWD=/holbertonschool-simple_shell
``` 

## SOFTWARE INSTALLATION AND COMPILATION
* Git clone the repository with: 

**HTTPS:**
```
$ git clone https://github.com/CLMNTDFR/holbertonschool-simple_shell.git
```
**SSH:** 
```
$ git clone git@github.com:CLMNTDFR/holbertonschool-simple_shell.git
```

* The shell operates by being compiled with GCC version 9.4.0 on Ubuntu 20.04 LTS or later versions, as well as MACOS 14.4.1 or later. It can also be compiled using the Ubuntu version of Windows Subsystem for Linux (WSL).

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

* To run the program, simply execute `./hsh`. It will display a prompt (`$`) awaiting your command input.

* **Exiting**

To exit the program, type `$ exit` or use CTRL + D.

* **Manual**

`hsh` comes with a manual page accessible by running:
```
man ./man_1_simple_shell
```

## EXAMPLES
Below are presented examples of `hsh` usage.

### • Interactive

In interactive mode, `hsh` receives directly the command from the user: standard input linked to the terminal and detected by the [isatty(3)](https://www.man7.org/linux/man-pages/man3/isatty.3.html) function.

**Command**

```
$ ls -la
$ echo 'Holberton school'
$ pwd
```

**Output**

```
total 80
drwxr-xr-x  3 clement clement  4096 Apr 22 12:30 .
drwxr-x--- 18 clement clement  4096 Apr 22 10:58 ..
drwxr-xr-x  8 clement clement  4096 Apr 22 12:33 .git
-rw-r--r--  1 clement clement   138 Apr 22 11:03 AUTHORS
-rw-r--r--  1 clement clement  1074 Apr 22 11:03 LICENCE.md
-rw-r--r--  1 clement clement  4420 Apr 22 11:03 README.md
-rw-r--r--  1 clement clement   852 Apr 22 10:27 command_executor.c
-rw-r--r--  1 clement clement   877 Apr 22 11:57 command_path_resolver.c
-rw-r--r--  1 clement clement   602 Apr 22 12:30 command_reader.c
-rw-r--r--  1 clement clement   913 Apr 22 10:27 command_tokenizer.c
-rwxr-xr-x  1 clement clement 17624 Apr 22 12:30 hsh
-rw-r--r--  1 clement clement   563 Apr 22 10:27 main.h
-rw-r--r--  1 clement clement  1550 Apr 22 12:36 man_1_simple_shell
-rw-r--r--  1 clement clement   940 Apr 22 10:27 simple_shell.c
'Holberton school'
/home/clement/holbertonschool-simple_shell
```

### • Non interactive

In non interactive mode, the commands are read according to the piped commands.

**Command**

```
echo "/bin/ls" | ./hsh
```
**Output**

```
AUTHORS     README.md           command_path_resolver.c  command_tokenizer.c  hsh     man_1_simple_shell
LICENCE.md  command_executor.c  command_reader.c         main.h               simple_shell.c
```


## LIBRARIES USED
`stdlib.h` | `stdio.h` | `unistd.h` | `string.h` | `sys/types.h` | `sys/wait.h` | `sys/stat.h` 

## PROJECT FILES DESCRIPTION
The projects include 6 files as follows: 

| File | Description                                     |
|----------|-----------------------------------------------|
|  `simple_shell.c`     |  Main entry point for the shell program; manages the shell loop and command processing. |
|  `main.h`     |  Header files, containing all functions prototypes as well as the librairies used. |
|   `command_executor.c`   |   Contains functions for executing commands and handling errors.     |
|   `command_path_resolver.c`    |   Finds the complete path for a command, checking environment variables.    |
|   `command_reader.c`     |     Reads user commands from standard input, handling interaction.   |
|     `command_tokenizer.c`  | Tokenizes user input into discrete arguments for processing.  |


## UML DIAGRAM OVERVIEW (Unified Modeling Language)
![UML](https://i.postimg.cc/bwYJC664/UML-23-04-2024-drawio.png)

## AUTHORS
• **Clément DEFER**
[@CLMNTDFR](https://github.com/CLMNTDFR)

• **James JAROSZ**
[@jmsjrz](https://github.com/jmsjrz)

## LICENCE
Copyright © <26/04/2024> • **James JAROSZ** & **Clément DEFER**
For more informations, consult the `LICENCE.md` file.
