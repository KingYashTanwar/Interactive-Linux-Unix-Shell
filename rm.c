#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h>

int main(int argc, char const *argv[])
{
	if(strcmp(argv[0], "-d")==0)
	{
		int result = remove(argv[1]);
		if(result==-1)
			printf("Error: %s\n", strerror(errno));
	}
	else if(strcmp(argv[0], "-v")==0)
	{
		int result = unlink(argv[1]);
		if(result==-1)
			printf("Error: %s\n", strerror(errno));
		else
			printf("removed '%s'\n", argv[1]);
	}
	else
	{
		int result = unlink(argv[1]);
		if(result==-1)
			printf("Error: %s\n", strerror(errno));
	}
	return 0;
}