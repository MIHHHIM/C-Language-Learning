#include <stdio.h>

int main() 
{
    printf("%c\n", '\'');
    printf("%s\n", "\"");
    printf("C:\\Test\\Code\\Hello.c\n");
    printf("\a");
    printf("%c\n", '\130');
    printf("%c\n", '\x30');
    
    return 0;
}