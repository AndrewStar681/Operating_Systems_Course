#include <stdio.h>
#include <stdlib.h>

void    bubble_sort(int arr[], int size); //increasing order

void    print_array(int arr[], int size);

int main(void)
{
    int array[5] = {3, 6, 3, 9, 6};
    
    printf("Initial       array: ");
    print_array(array, 5);
    bubble_sort(array, 5);
    printf("Bubble-sorted array: ");
    print_array(array, 5);

    return EXIT_SUCCESS;
}

void    bubble_sort(int arr[], int size)
{
    int tmp;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void    print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
