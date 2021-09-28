#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int number;
    int wt;
    int at;
    int bt;
    int ct;
    int tat;
}               proccess;

void    show_table(proccess* p, float average_tat, float average_wt, int size);

int main(int ac,char** ag)
{
    float       average_tat;
    float       average_wt;
    int         n;
    int         common_bt;
    proccess    tmp;
    proccess*   p;

    common_bt = 0;
    average_tat = 0;
    average_wt = 0;

    if (ac < 2)
    {
        printf("Enter the number of proccesses you want to execute : ");
        scanf("%d", &n);
    } else
    {
        sscanf(ag[1], "%d", &n);
    }
    p = malloc(n * sizeof(proccess));
    for (int i = 0; i < n; i++)
    {
        p[i].number = i + 1;
        printf("----------------\n\n");
        printf("Proccess #%d\n", i + 1);
        printf("_______________\n");
        printf("Enter arriving time: ");
        scanf("%d", &p[i].at);
        printf("Enter bursting time: ");
        scanf("%d", &p[i].bt);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        p[i].wt = p[0].at + common_bt - p[i].at;
        if (p[i].wt < 0)
            p[i].wt = 0;
        common_bt += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;
        average_tat += p[i].tat;
        p[i].ct = p[i].tat + p[i].at;
        average_wt += p[i].wt;
    }

    average_tat /= (float)n;
    average_wt /= (float)n;

    /*
    for (int i = 0; i < n; i++)
    {
        printf("#%d waiting time : %d\n", p[i].number, p[i].wt);
        printf("#%d ta time : %d\n", p[i].number, p[i].tat);
        printf("#%d ctime : %d\n", p[i].number, p[i].ct);
    }
    printf("#average_tat : %f\n", average_tat);
    printf("#average_wt : %f\n", average_wt);
    */
    show_table(p, average_tat, average_wt, n);
}

void    show_table(proccess* p, float average_tat, float average_wt, int size)
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|    Proccess    |  Arrival time  |   Burst time   |  Waiting time  | Completion  time | Turnaround time|\n");
    for (int i = 0; i < size; i++)
    {
        printf("|-------------------------------------------------------------------------------------------------------|\n");
        printf("|");
        printf("%9d", p[i].number);
        printf("       |");
        printf("%9d", p[i].at);
        printf("       |");
        printf("%9d", p[i].bt);
        printf("       |");
        printf("%9d", p[i].wt);
        printf("       |");
        printf("%10d", p[i].ct);
        printf("        |");
        printf("%9d", p[i].tat);
        printf("       |\n");
    }
    printf("|-------------------------------------------------------------------------------------------------------|\n");
    printf("|    Average     |                |                |");
    printf("  %012.6f  |", average_wt);
    printf("                  |");
    printf("  %012.6f  |\n", average_tat);
    printf("---------------------------------------------------------------------------------------------------------\n");
}
