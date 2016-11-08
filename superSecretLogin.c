#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secretStuff.h"

void sysCall()
{
	char command[16];
	puts("Enter a bash command: ");
	read(0, command, 15);
	system(command);

	return;
}

int main(int argc, char *argv[])
{
	volatile int auth_flag = 0x01020304;
        char password_buffer[16];

	if(argc < 2)
	{
		printf("Usage: %s <password>\n", argv[0]);
		exit(0); 
	}

	strncpy(password_buffer, argv[1], 21);
        if(strcmp(password_buffer, password) == 0)
	{
		auth_flag = 0x41424344;
	}
	
	if(auth_flag == 0x41424344) 	
	{
		 printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		 printf(" Access Granted.\n"); 
		 printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		sysCall();
	} else {
		printf("\nAccess Denied.\n");
	}
 }

