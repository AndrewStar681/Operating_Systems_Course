#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int     N;
    int*    arr;

    printf("Enter the number N - the size of the array that will be created: ");
    scanf("%d", &N);
    arr = malloc(N * sizeof(*arr));

    for (int i = 0; i < N; i++)
        arr[i] = i;

    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);

    return (EXIT_SUCCESS);
}
