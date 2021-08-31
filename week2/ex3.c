#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int h;
    if (ac == 1)
    {
        printf("You didn't enter a number");
        return EXIT_SUCCESS;
    }    
    sscanf(av[1], "%d", &h);
    for (int i = 0; i < 2*h; i += 2)
    {
        for (int j = 1; j < 2*h; j++)
        {
            if (j >= h - (i/2) && j <= h + (i)/2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("%d", h);
}
