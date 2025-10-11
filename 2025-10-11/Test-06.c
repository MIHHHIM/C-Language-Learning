#include <stdio.h>

int main() 
{
    printf("sizeof(100): %zd\n", sizeof(100));

    printf("sizeof(3.14): %zd\n", sizeof(3.14));

    printf("sizeof('A'): %zd\n", sizeof('A'));

    printf("sizeof(char): %zd\n", sizeof(char));

    return 0;
}