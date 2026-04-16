#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;
    node *temp2 = tail2;

    int carry = 0, count = 0;

    node *headR2 = NULL, *tailR2 = NULL;   /* temporary result for each row */
    node *headAR = NULL, *tailAR = NULL;   /* result after addition */

    /* Traverse second operand from last digit */
    while(temp2 != NULL)
    {
        /* Add zeros according to position (like manual multiplication) */
        for(int i = 0; i < count; i++)
        {
            insert_first(&headR2, &tailR2, 0);
        }

        /* Multiply each digit of operand1 */
        while(temp1 != NULL)
        {
            int mul = temp1->data * temp2->data + carry;

            /* First iteration directly stored in result list */
            if(count == 0)
            {
                insert_first(headR, tailR, mul % 10);
            }
            else
            {
                insert_first(&headR2, &tailR2, mul % 10);
            }

            carry = mul / 10;
            temp1 = temp1->prev;

            /* If reached beginning of operand1 store remaining carry */
            if(temp1 == NULL)
            {
                if(count == 0)
                {
                    insert_first(headR, tailR, carry);
                }
                else
                {
                    insert_first(&headR2, &tailR2, carry);
                }

                carry = 0;
            }
        }

        /* Add partial result with final result */
        if(headR2 != NULL)
        {
            addition(*tailR, tailR2, &headAR, &tailAR);

            delete_list(headR, tailR);

            *headR = headAR;
            *tailR = tailAR;

            headAR = NULL;
            tailAR = NULL;
        }

        /* Delete temporary list */
        delete_list(&headR2, &tailR2);

        /* Reset pointers for next iteration */
        temp1 = tail1;
        temp2 = temp2->prev;

        count++;   /* increase position count */
    }
}