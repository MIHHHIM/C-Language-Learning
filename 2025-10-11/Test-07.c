#include <stdio.h>
#include <limits.h>

int main() 
{
    unsigned int max = UINT_MAX;
    unsigned int min = 0;

    printf("UINT_MAX: %u\n", max);

    unsigned int a = max + 1;
    printf("max + 1 = %u\n", a);

    unsigned int b = min - 1;
    printf("min - 1 = %u\n", b);

    return 0;
}