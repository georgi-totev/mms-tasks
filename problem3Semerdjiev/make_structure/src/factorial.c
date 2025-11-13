#include "library.h"

long long int factorial(int x)
{
    DBG_PRINT("Entered factorial");
    ++counter;
    if(x <= 1)
        return 1;
    else
        return x * factorial(x - 1);
}