#include "push-swap.h"

static int    ft_input_initilialize_i_delta(unsigned int i_target, unsigned int i_curr, int length)
{
    int i_delta;

    i_delta = i_target - i_curr;
    if (length % 2 == 0 && -i_delta == length / 2)
        i_delta = -i_delta;
    if (i_delta > length / 2)
        i_delta -= length;
    else if (-i_delta > length / 2)
        i_delta += length;
    return (i_delta);
}

static int ft_input_initilialize_i_target(int *array_sorted, int len, int search_value)
{
    int    i;

    i = 0;
    while (i < len && array_sorted[i] != search_value)
    {
        i++;
    }
    return (i);
}

static void    ft_populate_nodes(t_list **input_as_nodes, int *input_as_ints, int length)
{
    unsigned int i;

    i = 0;
    while (i < length)
    {
        input_as_nodes[i]->value = input_as_ints[i];
        i++;
    }
    ft_bubblesort(input_as_ints, length);
    i = 0;
    while (i < length)
    {
        input_as_nodes[i]->i_target = ft_input_initilialize_i_target(input_as_ints, length, input_as_nodes[i]->value);
        input_as_nodes[i]->i_delta = ft_input_initilialize_i_delta(input_as_nodes[i]->i_target, i, length);
        input_as_nodes[i]->next = NULL;
        i++;
    }
}

static t_list **ft_malloc_nodes(int *input_as_ints, int length)
{
    t_list **input_as_nodes;
    unsigned int i;

    input_as_nodes = (t_list **)malloc(sizeof(t_list *) * (length + 1));
    if (!input_as_nodes)
        return (NULL);
    i = 0;
    while (i < length)
    {
        input_as_nodes[i] = (t_list *)malloc(sizeof(t_list));
        if (!input_as_nodes[i])
            return (ft_input_free(input_as_nodes, i), NULL);
        i++;
    }
    input_as_nodes[i] = NULL;
    return (input_as_nodes);
}

t_list **ft_input_initialize(int length, char **input_as_strings)
{
    int *input_as_ints;
    unsigned int i;
    t_list **input_as_nodes;

    input_as_ints = ft_create_int_array_and_handle_errors(length, input_as_strings);
    if (!input_as_ints)
        return (NULL);
    input_as_nodes = ft_malloc_nodes(input_as_ints, length);
    if (!input_as_nodes)
        return (free(input_as_ints), NULL);
    ft_populate_nodes(input_as_nodes, input_as_ints, length);
    free(input_as_ints);
    return (input_as_nodes);
}
