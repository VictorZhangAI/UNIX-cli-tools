#ifndef _UTMP_LIB_H
#define _UTMP_LIB_H

#include <utmp.h>

int utmp_open(char *filename);
int utmp_reload();
struct utmp *utmp_next();
int utmp_close();

#endif
