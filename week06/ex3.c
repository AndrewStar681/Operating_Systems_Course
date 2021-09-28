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
    int rem_bt;
}               proccess;

void    show_table(proccess* p, float average_tat, float average_wt, int size);

int main(int ac,char** ag)
{
    float       average_tat;
    float       average_wt;
    int         n;
    int         quantum;
    int         undone;
    int         timer;
    proccess    tmp;
    proccess*   p;

    average_tat = 0;
    average_wt = 0;
    undone = 1;

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
        printf("________________\n\n");
        printf("Proccess #%d\n", i + 1);
        printf("_______________\n");
        printf("Enter arriving time: ");
        scanf("%d", &p[i].at);
        printf("Enter bursting time: ");
        scanf("%d", &p[i].bt);
        p[i].rem_bt = p[i].bt;
    }
    printf("\n____________________________________\n\n");
    printf("Please, specify the quantum time: ");
    scanf("%d", &quantum);
    
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

    timer = p[0].at;

    while(undone)
    {
        undone = 0;
        for(int i = 0; i < n; i++)
        {
            if (timer >= p[i].at)
                if (p[i].rem_bt > quantum)
                {
                    timer += quantum;
                    p[i].rem_bt -= quantum;
                    undone = 1;
                } else if (p[i].rem_bt > 0) {
                    timer += p[i].rem_bt;
                    p[i].rem_bt = 0;
                    p[i].wt = timer - p[i].at - p[i].bt;
                    if (p[i].wt < 0)
                        p[i].wt = 0;
                }
        }
    }

    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
        p[i].ct = p[i].tat + p[i].at;
        average_tat += p[i].tat;
        average_wt += p[i].wt;
    }

    average_tat /= (float)n;
    average_wt /= (float)n;

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
