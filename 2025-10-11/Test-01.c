#include <stdio.h>
#include <stdbool.h>

int main() 
{
    printf("char: %zd byte\n", sizeof(char));
    printf("_Bool: %zd byte\n", sizeof(_Bool));
    printf("short: %zd bytes\n", sizeof(short));
    printf("int: %zd bytes\n", sizeof(int));
    printf("long: %zd bytes\n", sizeof(long));
    printf("long long: %zd bytes\n", sizeof(long long));
    printf("float: %zd bytes\n", sizeof(float));
    printf("double: %zd bytes\n", sizeof(double));
    printf("long double: %zd bytes\n", sizeof(long double));

    return 0;
}