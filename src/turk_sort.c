/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:35:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 11:10:00 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	move_b_to_a(stack_a, stack_b);
}
