#ifndef MYLIB_H_
#define MYLIB_H_

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

extern int getword(char *s, int limit, FILE *stream);
extern void *emalloc(size_t s);

#endif
