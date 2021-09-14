#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    fork();
    fork();
    fork();
    sleep(5);

    return (EXIT_SUCCESS);
}
