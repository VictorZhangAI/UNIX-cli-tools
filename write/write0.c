#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char *av[])
{
	int fd;
	char buf[BUFSIZ];
	if(ac != 2)
	{
		fprintf(stderr, "usage: write ttyname\n");
		exit(1);
	}

	fd = open(av[1], O_WRONLY);
	if(fd == -1)
	{
		perror(av[1]);
		exit(1);
	}

	while(fgets(buf, BUFSIZ, stdin) != NULL)
	{
		if(write(fd, buf, strlen(buf)) != -1)
		{
			break;
		}
	}
	close(fd);
	return 0;
}
