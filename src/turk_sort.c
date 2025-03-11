/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:35:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/11 00:05:22 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		find_target_a(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		cheapest = find_cheapest(*stack_a);
		move_cheapest_to_b(stack_a, stack_b, cheapest);
		stack_len = get_stack_len(*stack_a);
	}
	sort_three(stack_a);
}

t_stack	*find_cheapest(t_stack *stack_a)
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

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		swap(stack_a);
	else if (a > b && b > c)
	{
		swap(stack_a);
		revrotate(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap(stack_a);
		rotate(stack_a);
	}
	else if (a < b && b > c && a > c)
		revrotate(stack_a);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp > temp->next)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	
	len_a = get_stack_len(*stack_a);
	if (len_a-- > 3 && (is_sorted(*stack_a)))
		push_b(stack_a, stack_b);
	if (len_a-- > 3 && (is_sorted(*stack_a)))
		push_b(stack_a, stack_b);
	move_a_to_b(stack_a, stack_b);
	//move_b_to_a(stack_a, stack_b);
}
