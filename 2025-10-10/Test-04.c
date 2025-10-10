#include <stdio.h>

int main() 
{
    for (int i = 32; i <= 127; i++) 
    {
        printf("%c ", i);
        if (i % 16 == 15) 
        {
            printf("\n");
        }
    }
    return 0;
}