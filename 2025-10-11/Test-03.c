#include <stdio.h>

int main() 
{
    int num = 100;

    printf("sizeof(int): %zu\n", sizeof(int));

    printf("sizeof(num): %zu\n", sizeof(num));
    
    printf("sizeof num: %zu\n", sizeof num);

    return 0;
}