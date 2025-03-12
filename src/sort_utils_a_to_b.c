/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:28:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 11:12:49 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_best_match_in_b(t_stack *stack_b, int value)
{
	t_stack *b;
	t_stack *best_match;

	b = stack_b;
	best_match = NULL;
    while (b)
    {
        if (b->value < value)
        {
            if (!best_match || b->value > best_match->value)
                best_match = b;
        }
        b = b->next;
    }
    return best_match;
}

t_stack *find_max_in_stack(t_stack *stack_b)
{
    t_stack *b;
    t_stack *max_node;

	b = stack_b;
	max_node = stack_b;
    while (b)
    {
        if (b->value > max_node->value)
            max_node = b;
        b = b->next;
    }
    return (max_node);
}

void find_target_in_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *a;

    if (!stack_a || !stack_b || !*stack_a || !*stack_b)
        return;

    a = *stack_a;
    while (a)
    {
        a->target_node = find_best_match_in_b(*stack_b, a->value);
        if (!a->target_node)
            a->target_node = find_max_in_stack(*stack_b);
        a = a->next;
    }
}

void move_cheapest_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
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
	push_b(stack_a, stack_b);
}

void	move_a_to_b(t_stack **stack_a , t_stack **stack_b)
{
	int	stack_len;
	t_stack *cheapest;

	stack_len = get_stack_len(*stack_a);
	
	while (stack_len > 3)
	{
		find_target_in_b(stack_a, stack_b);
		calculate_cost_a_to_b(stack_a, stack_b);
		cheapest = find_cheapest_in_a(*stack_a);
		move_cheapest_to_b(stack_a, stack_b, cheapest);
		stack_len = get_stack_len(*stack_a);
	}
	sort_three(stack_a);
}
