#include <stdio.h>
#include "library.h"

void print(void)
{
    DBG_PRINT("Entered print"); 
    printf("functions called: %d\n", counter);
}