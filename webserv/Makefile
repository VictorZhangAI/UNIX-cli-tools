CC=gcc
CFLAGS=-Wall -Werror -g -std=c11

webserv: webserv.o
	$(CC) $(CFLAGS) $< -o $@

webserv.o: webserv.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.o webserv
