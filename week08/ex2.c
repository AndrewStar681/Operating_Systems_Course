#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define N 10*1024*1024

/*  __EX3__
*   As VIRT and RES is almost equal, it is possible to say that the proccess
*   more consumed the memory of RAM (about 3% of all)
*/

/*  __EX2__ (I used the command "vmstat 1 14" not to stop it by myself)
*   As si and so are both 0 we can say that 
*   we had enough memory to execute and run the proccess without swaps.
*   With each report we see we used more memory as FREE were decreasing
*/

/*
*   Also I use this method in order to try to limit
*   the time of the program's work
* 
*   If you have any comments about it (positive or not), please, let me know
*/
static volatile sig_atomic_t timeout = 0;

void handler(int signal)
{
    (void) signal;
    timeout = 1;
}

int main(void)
{
    // Timing
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    if (sigaction(SIGALRM, &act, NULL) < 0)
        return (1);
    alarm(10);
    
    //main code
    int *a;

    while(!timeout)
    {
        a = malloc(N);
        memset(a, 7, N);
        sleep(1);
    }
    free(a);
    return (EXIT_SUCCESS);
}
