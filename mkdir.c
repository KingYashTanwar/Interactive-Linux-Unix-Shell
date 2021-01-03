#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int result;
	if(strcmp(argv[0], "-m")==0)
	{
		char *str;
		mode_t mode = strtol(argv[1], &str, 8);
		result = mkdir(argv[2], mode);
	}
	else if(strcmp(argv[0], "-v")==0)
	{
		result = mkdir(argv[1], 0777);
		if(result==-1)
		{
			printf("error: %s\n", strerror(errno));
			return 0;	
		}
		printf("%s: created directory '%s'\n", argv[1], argv[1]);
	}
	else
		result = mkdir(argv[0], 0777);
	if(result==-1)
		printf("error: %s\n", strerror(errno));	
	return 0;
}