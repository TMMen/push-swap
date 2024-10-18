#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# include <unistd.h>

typedef struct s_list
{
    int             value;
    int             i_target;
    int             i_delta;
    struct s_list   *next;
}   t_list;


t_list  **ft_input_initialize(int length, char **input_as_strings);
int     *ft_create_int_array_and_handle_errors(int length, char **input_as_strings);
void    ft_input_free(t_list **input, unsigned int i);

int	            ft_atoi(const char *str);
unsigned int    ft_strlen(char *str);
void            ft_bubblesort(int *array_sorted, int len);

void    ft_move_swap(t_list **stack, char c);
void    ft_move_push(t_list **stack_src, t_list **stack_dst, char c);
void    ft_move_rotate(t_list **stack, char c);
void    ft_move_reverse_rotate(t_list **stack, char c);

void            ft_push_swap_sort(t_list **input, int length);
void            ft_stack_initialize(t_list **input);
unsigned int    ft_amount_of_digits(int value);

#endif