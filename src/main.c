/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:03:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/04 18:11:06 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    t_data  *data;
    char    *joined_args;

    if (ac >= 2)
    {
        data = (t_data *)malloc(sizeof(t_data));
        if (!data)
            return (1);
        joined_args = join_args(ac, av);
        if (!joined_args)
            return (free(data), 1);
        data->buffer = ft_split(joined_args, ' ');
        free(joined_args);
        if (!data->buffer)
            return (free(data), 1);
        if (parse_input(data) == 0)
			radix_sort(data);
		int i = 0;
		ft_printf("sorted:");
		while (i < data->tab_size)
		{
			ft_printf("%d, ", data->stack_a[i]);
			i++;
		}
        free(data->tab);
		free(data->stack_a);
		free(data->stack_b);
		i = 0;
        while (data->buffer[i])
            free(data->buffer[i++]);
        free(data->buffer);
        free(data);
    }
}
