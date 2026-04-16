/*
Project Title: Arbitrary Precision Calculator (APC)

Developed By:
Rushikesh Ghuge

Project Description:
The Arbitrary Precision Calculator (APC) is designed to perform arithmetic operations on very large numbers 
that cannot be handled by standard data types in C. The project uses data structures such as linked lists 
to store and manipulate each digit of the numbers individually. 
This allows operations like addition, subtraction, multiplication, and division on numbers with a large number of digits.
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    /* Head and tail for operands and result */
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *headR = NULL, *tailR = NULL;

    /* Validate command line arguments */
    if (cla_validation(argc, argv) == FAILURE)
        return 0;

    int sign1 = 1, sign2 = 1;

    /* Check sign of first operand */
    if (argv[1][0] == '-')
        sign1 = -1;

    /* Check sign of second operand */
    if (argv[3][0] == '-')
        sign2 = -1;

    /* Create linked lists for operands */
    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    /* Remove leading zeros */
    remove_pre_zeros(&head1);
    remove_pre_zeros(&head2);

    char oper = argv[2][0];

    /* Compare the two operands */
    int cmp = compare_list(head1, head2);

    switch (oper)
    {
        case '+':
        {
            if (sign1 == sign2)
            {
                /* Perform addition */
                addition(tail1, tail2, &headR, &tailR);

                printf("The Addition of %s and %s is :", argv[1], argv[3]);

                if (sign1 == -1)
                    printf("-");

                print_list(headR);
            }
            else
            {
                /* Perform subtraction if signs are different */
                if (cmp == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    printf("The Addition of %s and %s is :", argv[1], argv[3]);

                    if (sign1 == -1)
                        printf("-");

                    print_list(headR);
                }
                else if (cmp == OPERAND2)
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    printf("The Addition of %s and %s is :", argv[1], argv[3]);

                    if (sign2 == -1)
                        printf("-");

                    print_list(headR);
                }
                else
                {
                    printf("The Addition of %s and %s is :0\n", argv[1], argv[3]);
                }
            }
        }
        break;

        case '-':
        {
            /* Change sign of second operand */
            sign2 = -sign2;

            if (sign1 == sign2)
            {
                addition(tail1, tail2, &headR, &tailR);

                printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

                if (sign1 == -1)
                    printf("-");

                print_list(headR);
            }
            else
            {
                if (cmp == OPERAND1)
                {
                    subtraction(tail1, tail2, &headR, &tailR);

                    printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

                    if (sign1 == -1)
                        printf("-");

                    print_list(headR);
                }
                else if (cmp == OPERAND2)
                {
                    subtraction(tail2, tail1, &headR, &tailR);

                    printf("The Subtraction of %s and %s is :", argv[1], argv[3]);

                    if (sign2 == -1)
                        printf("-");

                    print_list(headR);
                }
                else
                {
                    printf("The Subtraction of %s and %s is :0\n", argv[1], argv[3]);
                }
            }
        }
        break;

        case 'x':
        case 'X':
        {
            /* Perform multiplication */
            multiplication(tail1, tail2, &headR, &tailR);

            remove_pre_zeros(&headR);

            printf("The Multiplication of %s and %s is :", argv[1], argv[3]);

            if (sign1 != sign2)
                printf("-");

            print_list(headR);
        }
        break;

        case '/':
        {
            /* Perform division */
            division(head1, tail1, head2, tail2, &headR, &tailR);

            printf("The Division of %s and %s is :", argv[1], argv[3]);

            if (sign1 != sign2)
                printf("-");

            print_list(headR);
        }
        break;

        case '%':
        {
            /* Perform modulus */
            modulus(head1, tail1, head2, tail2, &headR, &tailR);

            printf("The Modulus of %s and %s is :", argv[1], argv[3]);

            /* Remainder takes sign of first operand */
            if (sign1 == -1)
                printf("-");

            print_list(headR);
        }
        break;
    }

    return 0;
}