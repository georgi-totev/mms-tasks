#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check_is_integer(const char *s)
{
    if (*s == '\0') return 0;
    while(*s){
        if(!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main()
{
    char buf1[100], buf2[100];
    printf("Enter two positive integers: ");
    if(scanf("%99s %99s", buf1, buf2) != 2){
        printf("Invalid input\n");
        return 1;
    }

    if(!check_is_integer(buf1) || !check_is_integer(buf2)){
        printf("Both numbers must be integers\n");
        return 1;
    }

    int a = atoi(buf1);
    int b = atoi(buf2);

    if(a <= 0 || b <= 0){
        printf("Both numbers must be > 0\n");
    }

    printf("The GCD of the numbers is: %d\n", gcd(a, b)); //greatest common divisor - най-малкия общ делител
    printf("The LCM of the numbers is: %d\n", lcm(a, b)); //least common multiple - най-голямото общо кратно

    return 0;
}