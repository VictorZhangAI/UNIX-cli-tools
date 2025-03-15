#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define INFO_WIDTH 8

void show_stat_info(char *fname, struct stat *buf);

int main(int ac, char *av[])
{
	struct stat info;
	if(ac > 1)
	{
		if(stat(av[1], &info) != -1)
		{
			show_stat_info(av[1], &info);
			return 0;
		}
		else
		{
			perror(av[1]);
		}
	}
	return 1;
}

void show_stat_info(char *fname, struct stat *buf)
{
	printf("%-*s: %o\n", INFO_WIDTH, "mode", buf->st_mode);
	printf("%-*s: %o\n", INFO_WIDTH, "links", buf->st_nlink);
	printf("%-*s: %o\n", INFO_WIDTH, "user", buf->st_uid);
	printf("%-*s: %o\n", INFO_WIDTH, "group", buf->st_gid);
	printf("%-*s: %o\n", INFO_WIDTH, "size", buf->st_size);
	printf("%-*s: %o\n", INFO_WIDTH, "modtime", buf->st_mtime);
	printf("%-*s: %s\n", INFO_WIDTH, "name", fname);
	return;
}
