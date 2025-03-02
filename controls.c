/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:02:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/02 00:49:19 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] )
	}
}

static int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && str[i] != 32)
				i++;
		}
	}
	return (count);
}

int *parse_input(char *str, int *size)
{
    int *arr;
    int count, i = 0, j = 0;
    long num;

    count = count_numbers(str);
    arr = malloc(sizeof(int) * count);
    if (!arr)
        return (NULL);

    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (!str[i])
            break;
        num = ft_atol(&str[i]);
        if (num > INT_MAX || num < INT_MIN)
            (ft_error(), free(arr), exit(1));
        arr[j++] = (int)num;
        while (str[i] && str[i] != ' ')
            i++;
    }
    *size = count;
    return (arr);
}
