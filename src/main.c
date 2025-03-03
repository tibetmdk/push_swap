/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:03:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/03 15:44:41 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_data	*data;
	int		i;
	
	if (ac >= 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (ac == 2)
		{
			data->buffer = ft_split(av[1], ' ');
			i = 0;
			while (data->buffer[i])
			{
				if (number_is_valid(data->buffer[i]))
					ft_error();
				i++;
			}
			if (parse_input(data))
				return (1);
			i = 0;
			while (i < data->tab_size)
			{
				printf("%d\n", data->tab[i]);
				i++;
			}

			// 🛠 Belleği temizle
			free(data->tab);
			i = 0;
			while (data->buffer[i])
				free(data->buffer[i++]);
			free(data->buffer);
			free(data);
		}	
	}
	else
		ft_printf("wrong argument count!");
	return (0);
}
