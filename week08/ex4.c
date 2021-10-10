#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/resource.h>

#define N 10*1024*1024

static volatile sig_atomic_t timeout = 0;

void    handler(int signal)
{
    (void) signal;
    timeout = 1;
}

long    getmemusage()
{
    struct rusage usage;

    getrusage(RUSAGE_SELF, &usage);
    return (usage.ru_maxrss);
}

int main(void)
{
    long base = getmemusage();
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    if (sigaction(SIGALRM, &act, NULL) < 0)
        return (1);
    alarm(10);
    int *a;

    while(!timeout)
    {
        a = malloc(N);
        memset(a, 7, N);
        printf("This one: %ld + %ld\n", base, getmemusage() - base);
        sleep(1);
        //free(a);
    }
    return (EXIT_SUCCESS);
}
