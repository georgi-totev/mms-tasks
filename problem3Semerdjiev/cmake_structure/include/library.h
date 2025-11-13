#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

#ifdef DEBUG
#define DBG_PRINT(msg) printf("DEBUG: %s\n", msg)
#else
#define DBG_PRINT(msg) ((void)0)
#endif

long long int factorial(int x);
void print();
extern int counter;

#endif