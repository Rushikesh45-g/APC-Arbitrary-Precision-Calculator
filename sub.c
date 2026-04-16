#include "apc.h"

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow_flag = 0;

    node *temp1 = tail1;
    node *temp2 = tail2;

    /* Traverse digits from last (LSB) */
    while (temp1 != NULL)
    {
        int digit1 = temp1->data;
        int digit2 = 0;

        temp1 = temp1->prev;

        /* Get digit from second operand if available */
        if (temp2 != NULL)
        {
            digit2 = temp2->data;
            temp2 = temp2->prev;
        }

        /* Apply previous borrow if exists */
        if (borrow_flag)
        {
            digit1 -= 1;
            borrow_flag = 0;
        }

        /* If digit1 smaller than digit2 take borrow */
        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow_flag = 1;
        }

        /* Perform subtraction */
        int sub = digit1 - digit2;

        /* Insert result digit at beginning */
        insert_first(headR, tailR, sub);
    }

    /* Remove leading zeros from result */
    remove_pre_zeros(headR);

    /* If result becomes empty, insert 0 */
    if (*headR == NULL)
        insert_first(headR, tailR, 0);
}