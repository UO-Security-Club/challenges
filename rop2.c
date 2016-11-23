#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void some_func()
{
	asm("syscall");
	asm("ret");

	asm("pop %edx");
	asm("pop %ecx");
	asm("pop %ebx");
	asm("pop %eax");
	asm("ret");
}

void vuln_func(char * input)
{
	char buf[32];

	memcpy(buf, input, 64);
}

void main(int argc, char * argv[])
{
	if(argc < 2){
		puts("Error: Need an argument");
		exit(1);
	}

	vuln_func(argv[1]);

	return;
}
