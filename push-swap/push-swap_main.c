#include "push-swap.h"

int main(int ac, char **av)
{
    t_list          **input;
    int             *array_numbers;

    if (ac > 1)
    {
        input = ft_input_initialize(ac - 1, av);
        if (!input)
            return (EXIT_FAILURE);
        ft_push_swap_sort(input, ac - 1);
        ft_input_free(input, ac - 1);
    }
    else
        return (EXIT_FAILURE);
}