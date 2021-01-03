#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <readline/readline.h> 
#include <readline/history.h>
#include <errno.h>

void error(char *com)
{
	printf("%s: command not found\n", com);
}

int main(int argc, char **argv)
{
  	char *line;
  	char prompt[10][100];
  	char history[100][100];
  	int hist_count = 0;
  	char cwd[1024];
  	system("clear");
    printf("\n\n-------------------------------"); 
    printf("\n\n\n\tYASH SHELL");
    printf("\n\n-------------------------------");
    printf("\n\n");
    char gwd[1024];
    if(getcwd(gwd, sizeof(gwd))==NULL)
      printf("Error: %s\n", strerror(errno));
  	sleep(1);
  	while(1)
  	{
  		if(getcwd(cwd, sizeof(cwd))==NULL)
  		  printf("Error: %s\n", strerror(errno));
  		printf("yash@macbook-pro:~%s", cwd);
  		line = readline("$ ");
  		strcpy(history[hist_count++], line);
  		char *token = strtok(line, " ");
  		int i = 0;
  		while(token != NULL) 
  		{
        	strcpy(prompt[i++], token);
        	token = strtok(NULL, " ");
     	}
     	if(strcmp(prompt[0], "exit")==0)
     	{
     			if(i==1)
     				exit(0);
    			else
     			  error(history[hist_count-1]);
     	}
     		else if(strcmp(prompt[0], "pwd")==0)
     		{
     			if(i==1)
     			{
     				if(getcwd(cwd, sizeof(cwd))!=NULL) 
  			 		printf("%s\n", cwd);
  			 	else
  			 		printf("Error: %s\n", strerror(errno));
     			}
          else if(strcmp(prompt[1], "--help")==0 && i==2)
          {
            char dir[1024];
            strcpy(dir, gwd);
            strcat(dir, "/pwdhelp.txt");
            FILE *pwdfile = fopen(dir, "r");
            if(pwdfile==NULL)
            {
              printf("Error: %s\n", strerror(errno));
              continue;
            }
            char help[256];
            while(fgets(help, 256, pwdfile))
              printf("%s", help);
            fclose(pwdfile);
          }
     			else if(strcmp(prompt[1], "-P")==0)
     			{
     				if(i==2)
     				{
     					if(getcwd(cwd, sizeof(cwd))!=NULL) 
  			 			printf("%s\n", cwd);
  			 		else
  			 			printf("Error: %s\n", strerror(errno));
     				}
     				else
     					error(history[hist_count-1]);
     			}
     			else
     				error(history[hist_count-1]);
     		}
     		else if(strcmp(prompt[0],"echo")==0)
     		{
     			if(i==1)
     				printf("\n");
     			else if(strcmp(prompt[1], "-n")==0)
     			{
     				if(i>2)
     				{
     					printf("%s", prompt[2]);
     					for(int j=3; j<i; j++)
     						printf(" %s", prompt[j]);
     				}
     			}
     			else if(strcmp(prompt[1], "-E")==0)
     			{
     				if(i>2)
     				{
     					for(int j=2; j<i; j++)
     						printf("%s ", prompt[j]);
     					printf("\n");
     				}
     			}
     			else
     			{
     				for(int j=1; j<i; j++)
     					printf("%s ", prompt[j]);
     				printf("\n");
     			}
     		}
     		else if(strcmp(prompt[0], "cd")==0)
     		{
     			int chdir_result;
     			if(i==1)
     				chdir_result = chdir(getenv("HOME"));
     			else if(i==2)
     			{
     				if(strcmp(prompt[1], "~")==0)
     					chdir_result = chdir(getenv("HOME"));
            else if(strcmp(prompt[1], "--help")==0)
            {
              char dir[1024];
              strcpy(dir, gwd);
              strcat(dir, "/cdhelp.txt");
              FILE *cdfile = fopen(dir, "r");
              if(cdfile==NULL)
              {
                printf("Error: %s\n", strerror(errno));
              }
              char help[256];
              while(fgets(help, 256, cdfile))
                printf("%s", help);
              fclose(cdfile);
            }
     				else
     					chdir_result = chdir(prompt[1]);
     			}
     			else if(i==3)
     			{
     				if(strcmp(prompt[1], "-P")==0)
     					chdir_result = chdir(prompt[2]);
     				else
     					error(history[hist_count-1]);
     			}
     			
     			if(chdir_result==-1)
     				printf("Error: %s\n", strerror(errno));
     		}
     		else if(strcmp(prompt[0], "history")==0)
     		{
     			if(i==1)
     			{
  				for(int j=0; j<hist_count; j++)
     					printf("%d %s\n",j+1, history[j]);
     			}
          else if(strcmp(prompt[1], "-a")==0)
            continue;
     			else if(strcmp(prompt[1], "-c")==0)
     			{
     				hist_count = 0;
     			}
     			else
     				error(history[hist_count-1]);
     		}
     		else if(strcmp(prompt[0], "ls")==0)
     		{
     			if(fork()==0)
     			{
     				
     				if(i==1)
     				{	
     					char *argv[] = {".", NULL};
     					char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/ls");
          			execvp(dir,argv);
          		}
          		else if(i==2)
          		{
          			char *argv[] = {".", prompt[1], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/ls");
          			execvp(dir,argv);
          		}
          		else
          			error(history[hist_count-1]);
          	}
          	wait(NULL);
     		}
     		else if(strcmp(prompt[0], "mkdir")==0)
     		{
     			if(fork()==0)
     			{
     				
     				if(i==2)
     				{	
     					char *argv[] = {prompt[1], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/mkdir");
          			execvp(dir,argv);
          		}
          		else if(i==3)
          		{
          			char *argv[] = {prompt[1], prompt[2], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/mkdir");
          			execvp(dir,argv);
          		}
          		else if(i==4)
          		{
          			char *argv[] = {prompt[1], prompt[2], prompt[3], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/mkdir");
          			execvp(dir,argv);
          		}
          	}
          	wait(NULL);
     		}
     		else if(strcmp(prompt[0], "cat")==0)
     		{
     			if(fork()==0)
     			{
     				if(i>1)
     				{
     					char *argv[i+1];
     					for(int j=0; j<i; j++)
     					{
     						argv[j] = prompt[j];
     					}	
     					argv[i] = NULL;
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/cat");
          			execvp(dir, argv);
          		}
          		else
          			error(history[hist_count-1]);
          	}
          	wait(NULL);
     		}
     		else if(strcmp(prompt[0], "date")==0)
     		{
     			if(fork()==0)
     			{
     				
     				if(i==1)
     				{	
     					char *argv[] = {"./date", NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/date");
          			execvp(dir,argv);
          		}
          		else if(i==2)
          		{
          			char *argv[] = {prompt[1], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/date");
          			execvp(dir,argv);
          		}
          		else if(i==3)
          		{
          			char *argv[] = {prompt[1], prompt[2], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/date");
          			execvp(dir,argv);
          		}
          		else
          			error(history[hist_count-1]);
          	}
          	wait(NULL);
     		}
     		else if(strcmp(prompt[0], "rm")==0)
     		{
     			if(fork()==0)
     			{
     				if(i==2)
          		{
          			char *argv[] = {prompt[1], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/rm");
          			execvp(dir,argv);
          		}
          		else if(i==3)
          		{
          			char *argv[] = {prompt[1], prompt[2], NULL};
          			char dir[1024];
     					strcpy(dir, gwd);
     					strcat(dir, "/rm");
          			execvp(dir,argv);
          		}
          		else
          			error(history[hist_count-1]);
          	}
          	wait(NULL);
     		}
     		else
     			error(history[hist_count-1]);
  	}
  	return 0;
}