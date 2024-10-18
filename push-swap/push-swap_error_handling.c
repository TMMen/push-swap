#include "push-swap.h"

static int ft_error_in_strings(const char *str)
{
    unsigned int i;

    i = 0;
    while (str[i] <= 32)
        i++;
    if (str[i] == '-')
        i++;
    if (str[i] == '\0')
    {
        write(1, "Error: use only numbers\n", 25);
        return (0);
    }
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            write(1, "Error: use only numbers\n", 25);
            return (0);
        }
        i++;
    }
    if (str[i] == '\0')
        return (1);
    write(1, "Error: use only numbers\n", 25);
    return (0);
}

static int ft_error_duplicates(int *array, int len_input)
{
    unsigned int i;
    unsigned int j;
    int          numb;

    i = 0;
    while (i < len_input)
    {
        numb = array[i];
        j = i;
        while (j < len_input)
        {
            if (i != j && numb == array[j])
            {
                write(1, "Error: no duplicate numbers\n", 29);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

static int ft_error_overunderflow(char *str, int num)
{
    unsigned int    i;

    i = ft_strlen(str) - 1;
    if (num == -2147483648 && i - 9 >= 0 && str[i - 10] != '-')
    {
        write(1, "Error: there's over- or underflow of an integer", 48);
        return (0);
    }
    while (i > 0)
    {
        if (num % 10 != str[i] - '0' && -(num % 10) != str[i] - '0')
        {
            write(1, "Error: there's over- or underflow of an integer", 48);
            return (0);
        }
        i--;
        num /= 10;
    }
    return (1);
}

int *ft_create_int_array_and_handle_errors(int length, char **input_as_strings)
{
    unsigned int    i;
    int             *input_as_ints;

    input_as_ints = (int *)malloc(sizeof(int) * length);
    if (!input_as_ints)
        return (NULL);
    i = 0;
    while (i < length)
    {
        if (!ft_error_in_strings(input_as_strings[i + 1]))
            return (free(input_as_ints), NULL);
        input_as_ints[i] = ft_atoi(input_as_strings[i + 1]);
        if (!ft_error_overunderflow(input_as_strings[i + 1], input_as_ints[i]))
            return (free(input_as_ints), NULL);
        i++;
    }
    if (ft_error_duplicates(input_as_ints, length))
        return (free(input_as_ints), NULL);
    return (input_as_ints);
}
