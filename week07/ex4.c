#include <stdlib.h>
#include <stdio.h>

void    *realloc_ft(void* ptr, int size_prev, int size_pres);

int main(void)
{
    int*    arr1;
    int     n;
    int     size;

    printf("Enter the number of elements of an initial array: ");
    scanf("%d", &n); 
    arr1 = malloc(n * sizeof(*arr1));
    
    for (int i = 0; i < n; i++)
        arr1[i] = n - i;
    printf("Now your array has %d elements which are: ", n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n\n");
    printf("Enter the new size which array must be: ");
    scanf("%d", &size);
    arr1 = realloc_ft(arr1, n, size);
    printf("\n\n");
    if (size == 0)
        printf("Now your array has no elements");
    printf("Now your array has %d elements\n where %d ones are saved from the initial: ", size, size > n ? n : size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    return (EXIT_SUCCESS);
}

void    *realloc_ft(void* ptr, int size_prev, int size_pres)
{
    void*   new_ptr;

    if (size_pres == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
    {
        ptr =  malloc(size_pres * sizeof(*ptr));
        return (ptr);
    }
    new_ptr = malloc(size_pres * sizeof(*ptr));
    for (int i = 0; i < size_prev; i++)
        *((int*) new_ptr + i) = *((int*) ptr + i);
    free(ptr);
    return (new_ptr);
}
