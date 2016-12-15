#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[100];

void win()
{
	system(string);
}

void add_bin(int x)
{
	if(x == 0xbadf000d){
		strcat(string, "/bin");
	}
}

void add_sh(int x, int y)
{
	if(x == 0xdeadbeef && y == 0xcafebabe){
		strcat(string, "/sh");
	}
}

void vuln_func(char * str)
{
	char buffer[100];
	strcpy(buffer, str);
}

int main(int argc, char ** argv)
{
	string[0] = 0;
	vuln_func(argv[1]);
	return(0);
}
