#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int             data;
    struct s_list   *next;
}               t_list;

void    print_list(t_list *begin);

void    insert_node(t_list **begin, int data);

void    delete_node(t_list **begin, int data);  //we delete the first node
                                //with the given data if it exist
int main(void)
{
    t_list *head;

    head = NULL;

    insert_node(&head, 2);
    insert_node(&head, 8);
    print_list(head);
    insert_node(&head, 3);
    insert_node(&head, 2);
    print_list(head);
    delete_node(&head, 8);

    print_list(head);
    delete_node(&head, 2);
    print_list(head);

    return EXIT_SUCCESS;
}

void    insert_node(t_list **begin, int data)
{
    t_list  *node;
    t_list  *list;

    node = malloc(sizeof(node));
    node->next = NULL;
    node->data = data;
    if (*begin == NULL)
    {
        *begin = node;
        printf("Created node with data = %d\n", data);
        return ;
    }
    list = *begin;
    while (list->next != NULL)
        list = list->next;
    list->next = node;
    printf("Created node with data = %d\n", data);
}

void    print_list(t_list *begin)
{
    int i;

    i = 0;
    while (begin != NULL)
    {
        if (i > 0)
            printf("->");
        printf("%d", begin->data);
        begin = begin->next;
        i = 1;
    }
    if (i == 0)
        printf("\nSorry, but the LinkedList is empty\n\n");
    printf("\n");
}

void    delete_node(t_list **begin, int data)
{
    t_list *list;
    t_list *del;

    list = *begin;
    if (!list)
    {
        printf("The LinkedList is empty");
        return ;
    }
    if (list->data == data)
    {
        *begin = (*begin)->next;
        list->next = NULL;
        free(list);
        printf("The node with data = %d is deleted\n", data);
        return ;
    }

    while (list->next && list->next->data != data)
        list = list->next;
    if (list->next)
    {
        del = list->next;
        list->next = del->next;
        del->next = NULL;
        free(del);
        printf("The node with data = %d is deleted\n", data);
        return ;
    }
    printf("There is no node wit data = %d\n", data);
}
