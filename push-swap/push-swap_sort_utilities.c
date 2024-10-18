#include "push-swap.h"

void    ft_stack_initialize(t_list **input)
{
    unsigned int    i;
    t_list  *curr;

    curr = input[0];
    i = 1;
    while (input[i])
    {
        curr->next = input[i];
        i++;
        curr = curr->next;
    }
}

unsigned int ft_amount_of_digits(int value)
{
    unsigned int i;

    i = 0;
    while (value)
    {
        value /= 2;
        i++;
    }
    return (i);
}