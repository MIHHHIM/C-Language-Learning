#include <stdio.h>

int main() 
{
    short s = 10;
    int num = 100;

    printf("%zd\n", sizeof(s = num + 2));

    printf("%zd\n", s);

    return 0;
}