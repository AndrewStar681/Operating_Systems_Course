#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char s[50];
    while (1)
    {
        printf("$>");
        fgets(s, 50, stdin);
        system(s);
    }
    return (EXIT_SUCCESS);
}
