#include "push-swap.h"

static int ft_is_it_ordered(t_list **input)
{
    int temp_delta;
    t_list  *curr;

    curr = input[0];
    temp_delta = curr->i_delta;
    while (curr)
    {
        if (curr->i_delta != temp_delta)
            return (0);
        curr = curr->next;
    }
    while (temp_delta > 0)
    {
        write(STDOUT_FILENO, "rra\n", 4);
        temp_delta--;
    }
    while (temp_delta < 0)
    {
        write(STDOUT_FILENO, "ra\n", 3);
        temp_delta++;
    }
    return (1);
}

static void ft_push_lowest(t_list **stack_a, t_list **stack_b, int limit)
{
    int i;

    i = 0;
    while (i < limit)
    {
        if ((*stack_a)->i_target < limit)
        {
            ft_move_push(stack_a, stack_b, 'a');
            i++;;
        }
        else if ((*stack_a)->next->i_target < limit)
            ft_move_rotate(stack_a, 'a');
        else
            ft_move_reverse_rotate(stack_a, 'a');
    }
}

static void    ft_five_or_less(t_list **stack_a, t_list **stack_b, int length)
{
    if (length - 3 > 0)
        ft_push_lowest(stack_a, stack_b, length - 3);
    if ((*stack_a)->i_target == (*stack_a)->next->i_target + 1
            || (*stack_a)->i_target + 2 == (*stack_a)->next->i_target)
        ft_move_swap(stack_a, 'a');
    if ((*stack_a)->i_target > (*stack_a)->next->i_target 
        && (*stack_a)->i_target > (*stack_a)->next->next->i_target)
        ft_move_rotate(stack_a, 'a');
    if ((*stack_a)->i_target < (*stack_a)->next->i_target 
        && (*stack_a)->i_target > (*stack_a)->next->next->i_target)
        ft_move_reverse_rotate(stack_a, 'a');
    if ((*stack_b)->next && (*stack_b)->i_target < (*stack_b)->next->i_target)
        ft_move_swap(stack_b, 'b');
    while ((*stack_b))
        ft_move_push(stack_b, stack_a, 'b');
}

static void    ft_radixsort(t_list **stack_a, t_list **stack_b, int length)
{
    unsigned int offset;
    unsigned int i;

    offset = 0;
    while (offset < ft_amount_of_digits(length))
    {
        i = 0;
        while (i < length)
        {
            if ((((*stack_a)->i_target >> offset) & 1) == 1)
                ft_move_rotate(stack_a, 'a');
            else
                ft_move_push(stack_a, stack_b, 'a');
            i++;
        }
        while (*stack_b)
            ft_move_push(stack_b, stack_a, 'b');
        offset++;
    }
}

void    ft_push_swap_sort(t_list **input, int length)
{
    t_list  *stack_a;
    t_list  *stack_b;

    ft_stack_initialize(input);
    if (ft_is_it_ordered(input))
        return ;
    stack_a = input[0];
    stack_b = NULL;
    if (length <= 5)
        ft_five_or_less(&stack_a, &stack_b, length);
    else
        ft_radixsort(&stack_a, &stack_b, length);
}
