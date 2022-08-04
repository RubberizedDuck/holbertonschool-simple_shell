# :shell: C - Simple Shell
A simple Unix shell created as part of the curriculum at [Holberton School](http://holbertonschool.com.au/) for Low-Level Programming.

## :cinema: Usage 
To use the shell, simply compile all the ***.c*** files by using the ***make*** command and executing the ***hsh*** file that is created.

### Example
```
$ make
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh
$ ./hsh
```
###  Compilation
All the files are compiled with gcc and flags, as follows: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh`

### Invoking :computer:
The shell can be invoked both interactively, and non-interactively.

### Style of Coding :floppy_disk:
All files were written in C programming language and follow the [Betty Style of Coding](https://github.com/holbertonschool/Betty/wiki).

## Description :closed_book:

### File Descriptions :file_folder:
- **AUTHORS:** List of contributors for this repository
- **Makefile:** Source for compiling the shell
- **_getenv.c:** Function to get the current environment members
- **fork_exec.c:** Function to fork from current process and execute command
- **linklist_funcs.c:** Functions to manipulate linked lists
- **main.h:** Source of all prototypes and structures
- **man_1_simple_shell:** Manual page for the shell
- **simple_shell.c:** Main function to run the shell
- **string_funcs.c:** Functions to manipulate strings

### Programme Description :space_invader:
The shell reads the given input from the user and splits it into tokens if the input given is more than one word. The first given word is recognised as the command and any following words are considered as arguments to the command. The shell then performs the following:

1. Checks if the input received by the user relates to a command, if not then it will print out **`command not found`** starting with the command the user tried to input. Otherwise the shell will check if the given command starts with a **`/`**, if it does the shell goes directly to the path, (all the characters that follow the **`/`** and before the delimiter **`(space)`**).

2. If the word doesn't start with the **`/`**, the shell lists all paths, splits the string into tokens with the **`:`** and concatenates the command onto the end of each directory to find an existing executable. If the executable is found the shell forks into a child process where the command is then executed following any arguments.

3. The shell then returns the output of the given command and terminates the child process and whilst the parent process waits for the child process to be terminated.

4. The shell returns a new line with **`$ `** awaiting the next user input.

### Builtins :warning:
***Not currently available***

## Authors :book:
- Hamish Ross [**_[Gotmished](https://github.com/Gotmished)_**]
- Dylan Anderson [**_[RubberizedDuck](https://github.com/RubberizedDuck)_**]
## Created By Dylan Anderson & Hamish Ross
