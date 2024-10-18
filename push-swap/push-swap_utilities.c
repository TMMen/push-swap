#include "push-swap.h"

unsigned int ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	number;

	minus = 0;
	number = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	if (minus % 2 == 1)
		number = -number;
	return (number);
}

void    ft_bubblesort(int *array_sorted, int len)
{
    int i;
    int temp;

    while (len > 0)
    {
        i = 0;
        while (i < len - 1)
        {
            if (array_sorted[i] > array_sorted[i + 1])
            {
                temp = array_sorted[i];
                array_sorted[i] = array_sorted[i + 1];
                array_sorted[i + 1] = temp;
            }
            i++;
        }
        len--;
    }
}

void    ft_input_free(t_list **input, unsigned int i)
{
    unsigned int k;

    k = 0;
    while (k < i)
    {
        free(input[k]);
        k++;
    }
    free(input);
}
