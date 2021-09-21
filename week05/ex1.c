#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

void    *job (void * arg);

typedef struct thread_t
{
    pthread_t   thread_id;
    int         thread_num;
    char*       str;
}               thread_info;

int main(void)
{
    int             n;
    int             rv;
    thread_info*    th;
    
    printf("Enter the number of threads you want to create between 1 and 50: ");
    scanf("%d", &n);

    th = malloc(n * sizeof(thread_info));

    for (int i = 0; i < n; i++)
    {
        th[i].thread_num = i;
        rv = pthread_create(&(th[i].thread_id), NULL, job, (void *)i);
        if (rv != 0)
        {
            printf("Sorry, something was wrong");
            return (EXIT_FAILURE);
        }
    }

    return (EXIT_SUCCESS);
}

void    *job (void * arg)
{
    thread_info* thread = (thread_info*) arg;
    int     thread_num = thread->thread_num;
    pid_t   thread_id = syscall(SYS_gettid);
    printf("Created thred number : %d, ID : %d\n", thread_num, (int) thread_id);
}
