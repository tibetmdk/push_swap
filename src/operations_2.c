/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:43:01 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 10:06:31 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	s_wap(stack_a, 'a', 0);
	s_wap(stack_b, 'b', 0);
	if (print)
		ft_printf("ss\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	revrotate(stack_a, 'a', 0);
	revrotate(stack_b, 'b', 0);
	if (print)
		ft_printf("rrr\n");
}

void rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
	if (print)
		ft_printf("rr\n");
}