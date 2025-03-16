#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void dump_dir(int, const char *);

int main(int ac, char *av[])
{
	if(ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s <src> <dest>\n", av[0]);
		return EXIT_FAILURE;
	}

	int archive_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(archive_fd < 0)
	{
		perror("open");
		return EXIT_FAILURE;
	}

	dump_dir(archive_fd, av[1]);
	close(archive_fd);
	return EXIT_SUCCESS;
}

void dump_dir(int fd, const char *path)
{
	DIR *dir = opendir(path);
	if(dir == NULL)
	{
		perror("opendir");
		return;
	}

	struct dirent *entry;
	struct stat file_stat;
	char full_path[1024];

	while((entry = readdir(dir)) != NULL)
	{
		if(strcmp(entry->d_name, ".") == 0 ||
		strcmp(entry->d_name, "..") == 0)
		{
			continue;
		}

		snprintf(full_path, sizeof(full_path), 
			"%s/%s", path, entry->d_name);
		if(stat(full_path, &file_stat) < 0)
		{
			perror("stat");
			continue;
		}

		dprintf(fd, "%s %ld\n", full_path, file_stat.st_size);

		if(S_ISDIR(file_stat.st_mode))
		{
			dump_dir(fd, full_path);
		}
		else if(S_ISREG(file_stat.st_mode))
		{
			int file_fd = open(full_path, O_RDONLY);
			if(file_fd < 0)
			{
				perror("open");
				continue;
			}

			char buffer[BUFSIZ];
			ssize_t bytes;
			while((bytes = read(file_fd, buffer, BUFSIZ)) > 0)
			{
				if(write(fd, buffer, bytes) != bytes)
				{
					perror("write");
					break;
				}
			}
			close(file_fd);
		}
	}
	closedir(dir);
}
