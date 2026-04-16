#include "apc.h"

void modulus(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
{
    node *headQ = NULL, *tailQ = NULL;   // quotient
    node *headM = NULL, *tailM = NULL;   // multiplication result

    /* Step 1: Find quotient = A / B */
    division(head1, tail1, head2, tail2, &headQ, &tailQ);

    /* Step 2: Multiply quotient * B */
    multiplication(tailQ, tail2, &headM, &tailM);

    /* Step 3: Subtract A - (Q * B) */
    subtraction(tail1, tailM, headR, tailR);

    /* Remove leading zeros */
    remove_pre_zeros(headR);

    /* Free temporary lists */
    delete_list(&headQ, &tailQ);
    delete_list(&headM, &tailM);
}