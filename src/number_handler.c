/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:02:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/02 16:05:05 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int number_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

static int	number_count(char *str)
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

    count = number_count(str);
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
