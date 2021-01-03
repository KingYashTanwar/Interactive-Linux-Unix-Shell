# Interactive-Linux-Unix-Shell
Working:
● A while loop is being run repeatedly until the exit option is selected. The whole
command is taken as input using readline. The input command is then split into
individual words using strtok and later stored into a char[ ][ ] array.
● The input is compared with all the given commands using strcmp and if it
matches any, then that command is executed, otherwise proper error messages
are printed.
● The external commands would be handled by fork() which would call the execvp
system call.
● The program ends when the exit command is given by the user.
● Proper error handling has been done in all the programs to cover all cases.
Commands:
➔ cd
◆
◆
◆
◆
It changed the working directory.
It can take -P, ~, .. and --help options.
It will work if the directory name consists of a single word.
I used the chdir system call and if the provided directory is not valid(does
not exist or is not a directory), then an error message would be shown.
