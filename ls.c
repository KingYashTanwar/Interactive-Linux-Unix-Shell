#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	DIR *p;
	struct dirent *d;
	p = opendir(argv[0]);
	if(p==NULL)
	{
		if(errno==20)
		{
			printf("Error: '%s' %s\n", argv[0], strerror(errno));
		}
		else
			printf("Error: %s\n", strerror(errno));
		return 0;
	}
	char contents[100][100];
	int ls_count = 0;
	while((d=readdir(p))!=NULL)
	{
		if(memcmp(d->d_name, ".", 1)!=0)
			strcpy(contents[ls_count++], d->d_name);
	}

	for(int i=0; i<ls_count; i++)
	{
		for(int j=i+1; j<ls_count; j++)
		{
			if(strcmp(contents[i],contents[j])>0)
			{
				char temp[100];
            	strcpy(temp,contents[i]);
            	strcpy(contents[i],contents[j]);
            	strcpy(contents[j],temp);
         	}
		}
	}
	if(argv[1]!=NULL && strcmp(argv[1], "-m")==0)
	{
		printf("%s", contents[0]);
		for(int i=1; i<ls_count; i++)
			printf(", %s", contents[i]);
		printf("\n");
	}
	else if(argv[1]!=NULL && strcmp(argv[1], "-1")==0)
	{
		for(int i=0; i<ls_count; i++)
			printf("%s\n", contents[i]);
	}
	else
	{
		for(int i=0; i<ls_count; i++)
			printf("%s\t", contents[i]);
		printf("\n");
	}
	int close = closedir(p);
	if(close==-1)
	{
		printf("Error: %s\n", strerror(errno));
	}
	return 0;
}