#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

const char *lock_file = "/tmp/LCK.test2";

int main()
{
	int file_desc;
	int tries = 10;

	while (tries--)
	{
		file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444);
		if (file_desc == -1)
		{
			printf("%d - Lock alread present\n", getpid());
			sleep(3);
		}
		else
		{
			printf("%d - I have exclusive acces\n", getpid());
			sleep(1);
			close(file_desc);
			unlink(lock_file);
			sleep(2);
		}
	}

	return 0;
}
