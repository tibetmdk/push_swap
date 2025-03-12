/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:21:39 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 11:11:42 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_cost_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *a;
	int		rr;
	int		rrr;
	
    if (!stack_a || !*stack_a || !stack_b || !*stack_b)
        return;
    a = *stack_a;
    while (a)
    {
        bring_to_top_a(stack_a);
        bring_target_top_b(stack_a, stack_b);
        rr = 0;
        rrr = 0;
        while (a->ra > 0 && a->rb > 0 && ++rr)
        {
            a->ra--;
            a->rb--;
        }
        while (a->rra > 0 && a->rrb > 0 && ++rrr)
        {
            a->rra--;
            a->rrb--;
        }
        a->push_cost = rr + rrr + a->ra + a->rb + a->rra + a->rrb;
        a = a->next;
    }
}

void	bring_to_top_a(t_stack **stack_a)
{
	t_stack *a;
	int	pos;
	int	len;

	if (!stack_a || !*stack_a)
		return ;
	len = get_stack_len(*stack_a);
	a = *stack_a;
	while (a)
	{
		pos = get_index(*stack_a, a);
		a->ra = 0;
		a->rra = 0;
		if (pos <= len / 2)
			a->ra = pos;
		else
			a->rra = len - pos;
		a = a->next;
	}
}

void	bring_target_top_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	int		pos;
	int		len_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	len_b = get_stack_len(*stack_b);
	a = *stack_a;
	while (a)
	{
		if (!a->target_node)
		{
			a = a->next;
			continue ;
		}
		pos = get_index(*stack_b, a->target_node);
		a->rb = 0;
		a->rrb = 0;
		if (pos <= len_b / 2)
			a->rb = pos;
		else
			a->rrb = len_b - pos;
		a = a->next;
	}
}

t_stack	*find_cheapest_in_a(t_stack *stack_a)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!stack_a)
		return (NULL);
	cheapest = stack_a;
	current = stack_a->next;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}