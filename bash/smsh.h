#ifndef __SMSH_H__
#define __SMSH_H__

#define YES 1
#define NO 0

void setup();
char *next_cmd(char *, FILE *);
char *newstr(char *, int);
char **splitline(char *);
void freelist(char **);
void *emalloc(size_t);
void *erealloc(void *, size_t);
int execute(char **);
void fatal(char *, char *, int);

#endif
