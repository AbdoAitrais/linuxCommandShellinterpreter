#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 100





int main()
{
	char cmd[MAX];

	
	while(1)
	{
		printf("shell>");
		fgets(cmd,MAX,stdin);

		if(!strcmp(cmd,"exit\n"))
			break;

		if(!strcmp(cmd,""))
			continue;

		if(!fork())
		{
			system(cmd);
			exit(1);
		}
		else 
		{
			if(wait(NULL)>0)
				continue;
		}
	}
	
	return 0;
}