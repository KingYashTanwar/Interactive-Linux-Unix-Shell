**SHELL** 

Working: 

- A while loop is being run repeatedly until the exit option is selected. The whole command is taken as input using readline. The input command is then split into individual words using strtok and later stored into a char[ ][ ] array. 
- The input is compared with all the given commands using strcmp and if it matches any, then that command is executed, otherwise proper error messages are printed. 
- The external commands would be handled by fork() which would call the execvp system call. 
- The program ends when the exit command is given by the user. 
- Proper error handling has been done in all the programs to cover all cases. 

Commands: 

- cd 
- It changed the working directory. 
- It can take -P,  ~, .. and --help options. 
- It will work if the directory name consists of a single word. 
- I used the chdir system call and if the provided directory is not valid(does not exist or is not a directory), then an error message would be shown. 

![](Exercise%201.2.001.png)

- echo 
- It prints the message after it. 
- It can take -n and -E options. 
- Backslash, double quotes and single quotes would be printed as it is. 

![](Exercise%201.2.002.png)

- history 
- It prints the list of entire commands used in the particular session. 
- It can take two options -a and -c 
- history -a is just stored in history and history -c clears history. 

![](Exercise%201.2.003.png)

- pwd 
- It tells the present working directory. 
- It can take -P and --help options. 
- Suitable errors are handled. 

![](Exercise%201.2.004.png)

- exit 
- It terminates the shell. 

![](Exercise%201.2.005.png)

- ls 
- It lists the contents of the present directory. 
- It can take -m and -1 options. 
- Suitable errors are handled. 

![](Exercise%201.2.006.png)

- cat 
- It reads the contents of a text file. 
- It has options -n and -E 
- Suitable errors are handled. 

![](Exercise%201.2.007.png)

- date 
- It prints the date. 
- The options -u and -R are implemented. 
- date -u -R and date -R -u can also be done. 
- Only the current date would be printed, no user given date. 
- Suitable errors are handled. 

![](Exercise%201.2.008.png)

- rm 
- It removes a directory or a file. 
- Options: -d and -v 
- Suitable errors are handled. 

![](Exercise%201.2.009.png)

- mkdir 
- It makes directories. 
- Options: -m and -v 
- Suitable errors are handled. 
- Only a single name directory could be made. 

![](Exercise%201.2.010.png)
