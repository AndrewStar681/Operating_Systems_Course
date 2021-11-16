#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int start_program(FILE *fd);

int main(int ac, char **av)
{
    FILE *fd;
    if (ac == 1)
    {
        printf("Enter intpu-file's name");
        return (EXIT_FAILURE);
    }
    else
    {
        if (!(fd = fopen(av[1], "r")))
        {
            printf("Something is wrong.\n Try the command './(your execution file) (Name of the input-file)");
            return (EXIT_FAILURE);
        }
        return(start_program(fd));
    }
}

int    start_program(FILE *fd)
{
/****************__ALL_MAIN_VARIALES___******************/
    int proccess;    //lines in the matrix
    int type;       //columns in the matrix

    int deadlock;
    int we_can_change;//flag to change
    int changes_were;//flag to know that changes were made

    int *E_vector;  //Resources in existence
    int *A_vector;  //Resources available
    int *M_vector;  //Marked proccesses
    int **C_matrix; //Curent allocation matrix
    int **R_matrix; //Request matrix
/********************************************************/

/****************___SIZE_OF_MATRICES___******************/
    printf("Enter the number of the proccesses(lines in the matrixes): ");
    scanf("%d", &proccess);
    printf("Enter the number of the types (columns in the matrixes): ");
    scanf("%d", &type);
/********************************************************/

/***************___ALLOCATING_MEMORY___******************/

    // Allocating memory for vectors
    A_vector = malloc(type * sizeof(*A_vector));
    E_vector = malloc(type * sizeof(*E_vector));
    M_vector = calloc(proccess, sizeof(*M_vector));

    if (!E_vector || !A_vector || !M_vector)
    {
        printf("Fault in memory allocation\n");
        return (EXIT_FAILURE);
    }
    
    // Allocating memory for matrices
    C_matrix = (int**)malloc(proccess * sizeof(int*));
    R_matrix = (int**)malloc(proccess * sizeof(int*));
    if (!C_matrix || !R_matrix)
    {
        printf("Fault in memory allocation\n");
        return (EXIT_FAILURE);
    }
    for (int i = 0; i < proccess; i++)
    {
        C_matrix[i] = (int *)malloc(type * sizeof(int));
        R_matrix[i] = (int*)malloc(type * sizeof(int));
        if (!C_matrix[i] || !R_matrix[i])
        {
            printf("Fault in memory allocation\n");
            return (EXIT_FAILURE);
        }
    }
/********************************************************/

/**************___MATRIX_INITIALIZING___*****************/
    for (int i = 0; i < type; i++)
    {
        fscanf(fd, "%d", &E_vector[i]);
    }
    for (int i = 0; i < type; i++)
        fscanf(fd, "%d", &A_vector[i]);
    for (int i = 0; i < proccess; i++)
    {
        for (int j = 0; j < type; j++)
        {
            fscanf(fd, "%d", &C_matrix[i][j]);
        }
    }
    for (int i = 0; i < proccess; i++)
    {
        for (int j = 0; j < type; j++)
        {
            fscanf(fd, "%d", &R_matrix[i][j]);
        }
    }
    
    deadlock = 1;
/*******************************************************/
    fclose(fd);
    
/*******************___ALGORITHM___*********************/
    changes_were = 0;
    while(!changes_were)
    {
        for (int i = 0; i < proccess; i++)
        {
            if (M_vector[i] == 0)
            {
                we_can_change = 0;
                for (int j = 0; j < type; j++)
                {
                    if (A_vector[j] >= R_matrix[i][j])
                        we_can_change++;
                }
                if (we_can_change == type)
                {
                    changes_were = 1;
                    M_vector[i] = 1;
                    for (int j = 0; j < type; j++)
                    {
                        A_vector[j] += C_matrix[i][j];
                    }
                }
            }
        }
        if (changes_were == 0)
            break;
        changes_were = 0;
    }
/****************************************************/

/*******************___OUTPUT___*********************/
    FILE *output = fopen("ex1.txt", "w");

    //Defining if there is a deadlock
    // deadlock = 1 means no deadlock
    // deadlock = 0 means there is a deadlock
    //confusing? no at all
    for (int i = 0; i < proccess; i++)
    {
        deadlock *= M_vector[i];
    }
    //Decide what to print
    if (!deadlock)
    {
        fprintf(output, "Deadlock:\n\n");
        printf("\nDeadlock. Check file 'ex1.txt'\n");
        for (int i = 0; i < proccess; i++)
        {
            if (M_vector[i] == 0)
            {
                fprintf(output, "Proccess %d\n", i + 1);
            }
        }
    } else {
        printf("\nNo deadlock. Chek file 'ex1.txt'\n");
        fprintf(output, "No deadlock!\n");
    }
    fclose(output);
    return (EXIT_SUCCESS);
}
