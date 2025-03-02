/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:03:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/02 17:54:20 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    (void)av;
    (void)ac;
    //char    *joined_str;
    //int     *numbers;
    //int     size;
    char **res = ft_split("123 123 123 123 123 123123    123", ' ');
	int i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
    free(res);
}
