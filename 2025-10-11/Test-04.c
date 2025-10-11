#include <stdio.h>

int main() 
{
    int x = 10;

    printf("%zd\n", sizeof(x++));

    printf("%d\n", x);

    return 0;
}