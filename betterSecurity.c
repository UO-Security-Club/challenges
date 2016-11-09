#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int auth_flag;

void sysCall()
{
	char command[16];
	int i;

	puts("Enter a command: ");
	i = read(0, command, 15);

	command[i+1] = '\0';
	system(command);

	return;
}

void main(int argc, char *argv[])
{
	char pw_buff[16];
	srand(time(NULL));
	auth_flag = rand();

	if(argc < 2)
	{
		printf("Usage: %s <password>\n", argv[0]);
		exit(0); 
	}

	strcpy(pw_buff, argv[1]);
	if(atoi(pw_buff) == auth_flag)
	{
		sysCall();
	}else{
		puts("Try again :( ");
	}

	return;
}
