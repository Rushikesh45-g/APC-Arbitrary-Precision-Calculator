#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *temp1 = tail1;   // Pointer to traverse first list from tail
    node *temp2 = tail2;   // Pointer to traverse second list from tail
    int carry = 0;         // Variable to store carry during addition

    while (temp1 != NULL || temp2 != NULL)   // Continue until both lists are fully traversed
    {
        int digit1 = 0;    // Store digit from first list
        int digit2 = 0;    // Store digit from second list

        if (temp1 != NULL)     // If first list still has nodes
        {
            digit1 = temp1->data;   // Get digit from first list node
            temp1 = temp1->prev;    // Move to previous node
        }

        if (temp2 != NULL)     // If second list still has nodes
        {
            digit2 = temp2->data;   // Get digit from second list node
            temp2 = temp2->prev;    // Move to previous node
        }

        int sum = digit1 + digit2 + carry;   // Add digits along with carry

        insert_first(headR, tailR, sum % 10);   // Insert result digit at beginning of result list
        carry = sum / 10;                       // Calculate carry for next addition
    }

    if (carry==1)          // If carry remains after loop
    {
        insert_first(headR, tailR, carry);   // Insert remaining carry into result list
    }
}