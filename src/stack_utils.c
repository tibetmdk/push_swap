/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:04 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/07 18:41:21 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_data *data)
{
	int	i;

	i = 0;
	data->stack_a = (t_stack *)malloc(sizeof(t_stack));
	data->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!data->stack_a || !data->stack_b)
		ft_error();
	

}