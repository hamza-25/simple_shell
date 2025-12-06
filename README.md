# Simple Shell - HSH

A simple UNIX command line interpreter (shell) built in C language as part of the [ALX SE Program](https://www.alxafrica.com/software-engineering/).

## 📋 Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [External Commands](#external-commands)
- [Advanced Features](#advanced-features)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Authors](#authors)

## ✨ Features

### Core Shell Functionality
- **Interactive and Non-interactive modes**
- **Command execution with arguments**
- **PATH environment variable resolution**
- **Built-in command support**
- **Signal handling (Ctrl+C)**
- **Error handling with proper exit codes**
- **Memory management and cleanup**

### Enhanced User Experience
- **Current working directory display in prompt**
- **Smart directory navigation**
- **Environment variable support**
- **Command history tracking**

## 🔧 Installation

### Prerequisites
- GCC compiler
- Linux/Unix environment
- Standard C library

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Run the Shell
```bash
./hsh
```

## 🚀 Usage

### Interactive Mode
Launch the shell and interact with it directly:
```bash
$ ./hsh
/home/user/simple_shell$ ls -la
/home/user/simple_shell$ cd /tmp
/tmp$ pwd
/tmp$ exit
```

### Non-Interactive Mode
Execute commands via pipes or input redirection:
```bash
$ echo "ls -la" | ./hsh
$ echo -e "pwd\ncd ..\npwd" | ./hsh
```

## 🔨 Built-in Commands

### `cd` - Change Directory
Navigate between directories with full support for:
- `cd` - Go to HOME directory
- `cd [directory]` - Change to specified directory
- `cd ..` - Go to parent directory
- `cd -` - Return to previous directory

**Examples:**
```bash
/home/user$ cd /tmp
/tmp$ cd ..
/$ cd -
/tmp$ cd
/home/user$
```

### `env` - Environment Variables
Display all environment variables:
```bash
/home/user$ env
PWD=/home/user
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
USER=user
...
```

### `exit` - Exit Shell
Exit the shell with optional status code:
```bash
/home/user$ exit
$ echo $?
0
```

## 🔧 External Commands

The shell supports all standard UNIX commands available in your PATH:

### File and Directory Operations
- `ls` - List directory contents
- `pwd` - Print working directory
- `mkdir` - Create directories
- `rmdir` - Remove directories
- `cp` - Copy files
- `mv` - Move/rename files
- `rm` - Remove files
- `find` - Search files and directories

### Text Processing
- `echo` - Display text
- `cat` - Display file contents
- `grep` - Search text patterns
- `sort` - Sort lines
- `uniq` - Remove duplicates
- `wc` - Count words, lines, characters

### System Information
- `ps` - Process information
- `who` - Show logged users
- `date` - Display date and time
- `uname` - System information

### Examples:
```bash
/home/user$ ls -la
/home/user$ echo "Hello, World!"
/home/user$ cat file.txt
/home/user$ ps aux
/home/user$ which ls
```

## 🎯 Advanced Features

### Smart Prompt Display
- **Current directory shown in prompt**
- **Home directory abbreviated as ~**
- **Subdirectories shown relative to home**

```bash
/home/user/simple_shell$ cd Documents
/home/user/Documents$ cd ..
/home/user$ cd /
/$ cd home/user
/home/user$
```

### PATH Resolution
Automatically finds executables in PATH directories:
```bash
$ /bin/ls        # Absolute path
$ ls             # Found via PATH resolution
```

### Environment Variable Handling
- **PWD** - Always updated with current directory
- **OLDPWD** - Tracks previous directory for `cd -`
- **PATH** - Used for command resolution
- **HOME** - Used for `cd` with no arguments

### Signal Handling
- **Ctrl+C (SIGINT)** - Gracefully handled, returns to prompt
- **Clean exit** - Proper memory cleanup on exit

### Error Handling
- **Command not found** - Clear error messages
- **Permission denied** - Proper error reporting
- **Invalid directory** - Helpful error messages

```bash
$ invalidcommand
./hsh: 1: invalidcommand: not found
$ cd /invalid/path
./hsh: 1: cd: can't cd to /invalid/path
```

## 📝 Examples

### Basic Usage
```bash
$ ./hsh
/home/user/simple_shell$ pwd
/home/user/simple_shell
/home/user/simple_shell$ ls -la
total 156
drwxr-xr-x 3 user user  4096 Dec  6 14:37 .
drwxr-x--- 5 user user  4096 Dec  6 14:39 ..
-rwxr-xr-x 1 user user 26624 Dec  6 14:37 hsh
...
```

### Directory Navigation
```bash
/home/user/simple_shell$ cd /tmp
/tmp$ pwd
/tmp
/tmp$ cd -
/home/user/simple_shell$ cd ..
/home/user$ cd simple_shell
/home/user/simple_shell$
```

### Environment Variables
```bash
/home/user$ env | grep PATH
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin
/home/user$ echo $HOME
$HOME
```

### Command Execution
```bash
/home/user$ echo "Hello World"
Hello World
/home/user$ which ls
/usr/bin/ls
/home/user$ date
Fri Dec  6 14:37:22 UTC 2024
```

## 📁 Project Structure

```
simple_shell/
├── main.h              # Header file with function prototypes
├── main.c              # Main shell loop and initialization
├── prompt.c            # Prompt display and directory handling
├── _fork.c             # Process creation and execution
├── _func1.c            # String manipulation functions
├── _func2.c            # Input handling functions
├── _func3.c            # Token parsing functions
├── _func4.c            # Built-in commands implementation
├── path.c              # PATH resolution functions
├── _env.c              # Environment variable functions
├── _env_non.c          # Non-interactive environment handling
├── non_interactive.c   # Non-interactive mode implementation
├── name_of_prg.c       # Program name handling
├── AUTHORS             # Project authors
└── README.md           # This file
```

## 🔍 Technical Details

### Memory Management
- Dynamic memory allocation for command buffers
- Proper cleanup on exit and error conditions
- No memory leaks in normal operation

### Process Handling
- Fork-exec model for external commands
- Proper parent-child process synchronization
- Signal handling for interrupts

### String Processing
- Custom string manipulation functions
- Safe buffer handling
- Tokenization and parsing

## 🚫 Limitations

- No pipe (`|`) support
- No redirection (`>`, `<`, `>>`) support
- No command substitution
- No variable assignment
- No scripting support (if/while/for)
- No job control (background processes)

## 🤝 Authors

See the [AUTHORS](AUTHORS) file for contributor information.
