#include "apc.h"

void division(node *head1, node *tail1,node *head2, node *tail2,node **headR, node **tailR)
{
    node *head_OPR1 = NULL;
    node *tail_OPR1 = NULL;

    node *temp = head1;

    /* Check division by zero */
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero\n");
        return;
    }

    /* If dividend is smaller than divisor, quotient is 0 */
    if (compare_list(head1, head2) == OPERAND2)
    {
        insert_first(headR, tailR, 0);
        return;
    }

    while (temp != NULL)
    {
        /* Bring down next digit from dividend */
        insert_last(&head_OPR1, &tail_OPR1, temp->data);
        temp = temp->next;

        /* Remove leading zeros from temporary dividend */
        remove_pre_zeros(&head_OPR1);

        int count = 0;

        /* Subtract divisor repeatedly until temp dividend becomes smaller */
        while (compare_list(head_OPR1, head2) != OPERAND2)
        {
            node *head_SR = NULL;
            node *tail_SR = NULL;

            /* Perform subtraction */
            subtraction(tail_OPR1, tail2, &head_SR, &tail_SR);

            /* Delete old value */
            delete_list(&head_OPR1, &tail_OPR1);

            /* Update with new result */
            head_OPR1 = head_SR;
            tail_OPR1 = tail_SR;

            count++;
        }

        /* Store quotient digit */
        insert_last(headR, tailR, count);
    }

    /* Remove leading zeros from result */
    remove_pre_zeros(headR);

    /* If result is empty, quotient is 0 */
    if (*headR == NULL)
        insert_first(headR, tailR, 0);

    /* Free temporary list */
    delete_list(&head_OPR1, &tail_OPR1);
}