/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:43:01 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 20:29:55 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	revrotate(stack_a, 'a');
	revrotate(stack_b, 'b');
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}