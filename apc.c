#include "apc.h"

/* Validate command line arguments */
int cla_validation(int argc, char *argv[])
{
    /* Check argument count */
    if(argc != 4)
    {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }

    /* Check first operand */
    int i = (argv[1][0] == '-' || argv[1][0] == '+') ? 1 : 0;

    for(; argv[1][i]; i++)
    {
        if(argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("First operand must be digits\n");
            return FAILURE;
        }
    }

    /* Check second operand */
    i = (argv[3][0] == '-' || argv[3][0] == '+') ? 1 : 0;

    for(; argv[3][i]; i++)
    {
        if(argv[3][i] < '0' || argv[3][i] > '9')
        {
            printf("Second operand must be digits\n");
            return FAILURE;
        }
    }

    /* Check division or modulus by zero */
    if((argv[2][0] == '/' || argv[2][0] == '%') && strcmp(argv[3], "0") == 0)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    return SUCCESS;
}


/* Create linked list from operand string */
void create_list(char *opr, node **head, node **tail)
{
    int i = 0;

    while(opr[i])
    {
        /* Skip sign */
        if(opr[i] == '+' || opr[i] == '-')
        {
            i++;
            continue;
        }

        insert_last(head, tail, opr[i] - '0');
        i++;
    }
}


/* Insert node at end */
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
}


/* Insert node at beginning */
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));

    if(!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }

    return SUCCESS;
}


/* Print linked list number */
void print_list(node *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }

    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}


/* Delete entire list */
int delete_list(node **head, node **tail)
{
    node *temp = *head;

    while(temp)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}


/* Remove leading zeros */
void remove_pre_zeros(node **head)
{
    if(*head == NULL)
        return;

    node *temp = *head;

    while(temp->data == 0 && temp->next != NULL)
    {
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
        temp = *head;
    }
}


/* Find length of list */
int list_len(node *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }

    return count;
}


/* Compare two numbers stored in lists */
int compare_list(node *head1, node *head2)
{
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    int len1 = list_len(head1);
    int len2 = list_len(head2);

    if(len1 > len2)
        return OPERAND1;

    if(len1 < len2)
        return OPERAND2;

    /* If lengths equal compare digit by digit */
    while(head1 && head2)
    {
        if(head1->data > head2->data)
            return OPERAND1;

        if(head1->data < head2->data)
            return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME;
}