#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE* file;
	char line[256];
	if(strcmp(argv[1], "-n")==0)
	{
		int i = 1;
		for(int j=2; j<argc; j++)
		{
			file = fopen(argv[j], "r");
			if(file==NULL)
			{
				printf("Error: '%s' %s\n", argv[j], strerror(errno));
				return 0;
			}
			while(fgets(line, 256, file))
				printf("     %d  %s", i++, line);
		}
	}
	else if(strcmp(argv[1], "-E")==0)
	{
		for(int j=2; j<argc; j++)
		{
			file = fopen(argv[j], "r");
			if(file==NULL)
			{
				printf("Error: '%s' %s\n", argv[j], strerror(errno));
				return 0;
			}
			while(fgets(line, 254, file))
			{
				if(line[strlen(line)-1] == '\n')
					line[strlen(line)-1] = '\0';
				printf("%s%c\n",line, '$');
			}
		}
	}
	else
	{
		for(int j=1; j<argc; j++)
		{
			file = fopen(argv[j], "r");
			if(file==NULL)
			{
				printf("Error: '%s' %s\n", argv[j], strerror(errno));
				return 0;
			}
			while(fgets(line, 256, file))
				printf("%s", line);
		}
	}
	return 0;
}