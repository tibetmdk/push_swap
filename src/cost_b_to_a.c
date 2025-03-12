/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:06:00 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/11 23:06:33 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		rr;
	int		rrr;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	b = *stack_b;
	while (b)
	{
		bring_to_top_b(stack_b);
		bring_target_top_a(stack_a, stack_b);
		rr = 0;
		rrr = 0;
		while (b->rb > 0 && b->ra > 0 && ++rr)
		{
			b->rb--;
			b->ra--;
		}
		while (b->rrb > 0 && b->rra > 0 && ++rrr)
		{
			b->rrb--;
			b->rra--;
		}
		b->push_cost = rr + rrr + b->rb + b->rrb + b->ra + b->rra;
		b = b->next;
	}
}

void	bring_to_top_b(t_stack **stack_b)
{
	t_stack	*b;
	int		pos;
	int		len;

	if (!stack_b || !*stack_b)
		return ;
	len = get_stack_len(*stack_b);
	b = *stack_b;
	while (b)
	{
		pos = get_index(*stack_b, b);
		b->rb = 0;
		b->rrb = 0;
		if (pos <= len / 2)
			b->rb = pos;
		else
			b->rrb = len - pos;
		b = b->next;
	}
}

void	bring_target_top_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		pos;
	int		len_a;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	len_a = get_stack_len(*stack_a);
	b = *stack_b;
	while (b)
	{
		if (!b->target_node)
		{
			b = b->next;
			continue ;
		}
		pos = get_index(*stack_a, b->target_node);
		b->ra = 0;
		b->rra = 0;
		if (pos <= len_a / 2)
			b->ra = pos;
		else
			b->rra = len_a - pos;
		b = b->next;
	}
}

t_stack	*find_cheapest_in_b(t_stack *stack_b)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!stack_b)
		return (NULL);
	cheapest = stack_b;
	current = stack_b->next;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
