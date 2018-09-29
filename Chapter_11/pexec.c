#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("Running ps with execlp\n");
	execlp("ps", "ps", "ax", NULL);
	printf("Done.\n");

	return 0;
}
