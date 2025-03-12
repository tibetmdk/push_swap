/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:52:33 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 11:30:19 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_best_match_in_a(t_stack *stack_a, int value)
{
	t_stack *a;
	t_stack *best_match;

	a = stack_a;
	best_match = NULL;
	while (a)
	{
		if (a->value > value)
		{
			if (!best_match || a->value < best_match->value)
				best_match = a;
		}
		a = a->next;
	}
	return (best_match);
}

t_stack	*find_min_in_stack(t_stack *stack_a)
{
	t_stack	*a;
	t_stack *min_node;

	a = stack_a;
	min_node = stack_a;
	while (a)
	{
		if (a->value < min_node->value)
			min_node = a;
		a = a->next;
	}
	return (min_node);
}

void	find_target_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
        return;
    b = *stack_b;
	while (b)
	{
		b->target_node = find_best_match_in_a(*stack_a, b->value);
		if (!b->target_node)
			b->target_node = find_min_in_stack(*stack_a);
		b = b->next;
	}
}

void move_cheapest_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	if (!cheapest)
		return ;
	while (cheapest->ra > 0 && cheapest->rb > 0)
	{
		rr(stack_a, stack_b);
		cheapest->ra--;
		cheapest->rb--;
	}
	while (cheapest->rra > 0 && cheapest->rrb > 0)
	{
		rrr(stack_a, stack_b);
		cheapest->rra--;
		cheapest->rrb--;
	}
	while (cheapest->ra-- > 0)
		rotate(stack_a);
	while (cheapest->rra-- > 0)	
		revrotate(stack_a);
	while (cheapest->rb-- > 0)
		rotate(stack_b);
	while (cheapest->rrb-- > 0)
		revrotate(stack_b);
	push_a(stack_a, stack_b);
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len;
	t_stack	*cheapest;

	stack_len = get_stack_len(*stack_b);
	while (stack_len > 0)
	{
		find_target_in_b(stack_a, stack_b);
		calculate_cost_b_to_a(stack_a, stack_b);
		cheapest = find_cheapest_in_b(*stack_b);
		move_cheapest_to_a(stack_a, stack_b, cheapest);
		stack_len = get_stack_len(*stack_b);
		printf_both_stack(*stack_a, *stack_b);
		sleep(2);
	}
}