#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int     n = 54321;
    id_t    x = fork();

    if (x < 0)
        return EXIT_FAILURE;
    else if (x == 0)
        printf("Hello from child  %d, n = %d\n", getpid(), n);
    else
        printf("Hello from parent %d, n = %d\n", getpid(), n);
    wait(NULL);
    return (EXIT_SUCCESS);
}
