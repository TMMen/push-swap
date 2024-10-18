#include "push-swap.h"

void    ft_move_swap(t_list **stack, char c)
{
    t_list  *temp;

    temp = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    temp->next = *stack;
    *stack = temp;
    write(1, "s", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}

void    ft_move_push(t_list **stack_src, t_list **stack_dst, char c)
{
    t_list  *stack_temp;

    if (!(*stack_src))
        return ;
    stack_temp = *stack_src;
    *stack_src = (*stack_src)->next;
    stack_temp->next = *stack_dst;
    *stack_dst = stack_temp;
    write(1, "p", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}

void    ft_move_rotate(t_list **stack, char c)
{
    t_list  *temp;
    t_list  *curr;

    if (!((*stack)->next))
        return ;
    temp = *stack;
    *stack = (*stack)->next;
    curr = *stack;
    while (curr->next)
        curr = curr->next;
    curr->next = temp;
    temp->next = NULL;
    write(1, "r", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}

void    ft_move_reverse_rotate(t_list **stack, char c)
{
    t_list  *temp;
    t_list  *curr;

    curr = *stack;
    while (curr->next->next)
        curr = curr->next;
    temp = curr->next;
    curr->next = NULL;
    temp->next = *stack;
    *stack = temp;
    write(1, "rr", 2);
    write(1, &c, 1);
    write(1, "\n", 1);
}
