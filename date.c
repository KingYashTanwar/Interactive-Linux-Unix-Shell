#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <time.h>

void details(struct tm* tm)
{
	char str_time[256];
	strftime(str_time, 256, "%a %b %d %T %Z %G", tm);
	printf("%s\n", str_time);
}

void zone(struct tm* tm)
{
	char str_time[256];
	strftime(str_time, 256, "%a, %d %b %G %T %z", tm);
	printf("%s\n", str_time);
}

int main(int argc, char const *argv[])
{
	if(argv[1]!=NULL && ((strcmp(argv[0], "-u")==0 && strcmp(argv[1], "-R")==0)
	 	|| (strcmp(argv[0], "-R")==0 && strcmp(argv[1], "-u")==0)))
	{
		time_t t = time(NULL);
 		struct tm* tm = localtime(&t);
		gmtime(&t);
		zone(tm);
	}
	else if(strcmp(argv[0], "-u")==0 && argv[1]==NULL)
	{
		time_t t = time(NULL);
 		struct tm* tm = localtime(&t);
		gmtime(&t);
 		details(tm);
 	}
 	else if(strcmp(argv[0], "-R")==0 && argv[1]==NULL)
	{
		time_t t = time(NULL);
 		struct tm* tm = localtime(&t);
 		zone(tm);
 	}
 	else if(strcmp(argv[0], "./date")==0)
 	{
 		time_t t = time(NULL);
 		struct tm* tm = localtime(&t);
 		details(tm);
 	}
 	else
 		printf("command not found\n");
 	return 0;
 }