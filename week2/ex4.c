#include <stdio.h>
#include <stdlib.h>

void    swap(int *a, int *b);

int main(void)
{
    int a;
    int b;

    printf("Print to integer numbers and press ENTER: ");
    scanf("%d %d", &a, &b);
    printf("a = %d\nb = %d", a, b);
    swap(&a, &b);
    printf("\na = %d\nb = %d", a, b);
    return EXIT_SUCCESS;    
}

void    swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
