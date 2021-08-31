#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 50

int main(void)
{
    char    s[N];
    int     l;

    printf("Write a string and press an ENTER: ");
    fgets(s, N, stdin);
    l = strlen(s);
    while (--l >= 0)
    {
        printf("%c", s[l]);
    }    
    return (0);
}
