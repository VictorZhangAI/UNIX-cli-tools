#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <string.h>

#define PORTNUM 13000
#define HOSTLEN 256
#define oops(msg) {perror(msg); exit(1);}

int main(int ac, char *av[])
{
	struct sockaddr_in saddr;
	struct hostnet *hp;
	char hostname[HOSTLEN];
	int sock_id, sock_fd;
	FILE *sock_fp;
	time_t thetime;

	sock_id = socket(PF_INET, SOCK_STREAM, 0);
	if(sock_id == -1)
		oops("socket");

	bzero((void *)&addr, sizeof(saddr));
	gethostname(hostname, HOSTLEN);
}
