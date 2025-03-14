/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:35:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/14 10:03:01 by tmidik           ###   ########.fr       */
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
		s_wap(stack_a, 'a', 1);
	else if (a > b && b > c)
	{
		s_wap(stack_a, 'a', 1);
		revrotate(stack_a, 'a', 1);
	}
	else if (a > b && b < c && a > c)
		rotate(stack_a, 'a', 1);
	else if (a < b && b > c && a < c)
	{
		s_wap(stack_a, 'a', 1);
		rotate(stack_a, 'a', 1);
	}
	else if (a < b && b > c && a > c)
		revrotate(stack_a, 'a', 1);
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
static int get_min_index(t_stack *a)
{
    int min;
    int index;
    int i;

    if (!a)
        return (-1);
    min = a->value;
    index = 0;
    i = 0;
    while (a)
    {
        if (a->value < min)
        {
            min = a->value;
            index = i;
        }
        a = a->next;
        i++;
    }
    return (index);
}

static void final_rotation(t_stack **stack_a)
{
	int	min_index;
	int	size;

	min_index = get_min_index(*stack_a);
	size = get_stack_len(*stack_a);
	if (min_index <= size/2)
	{
		while (min_index-- > 0)
			rotate(stack_a, 'a', 1);
	}
	else
	{
		while (min_index++ < size)
			revrotate(stack_a, 'a', 1);
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	
	len_a = get_stack_len(*stack_a);
	if (len_a-- > 3 && (is_sorted(*stack_a)))
		push_b(stack_a, stack_b, 1);
	if (len_a-- > 3 && (is_sorted(*stack_a)))
		push_b(stack_a, stack_b, 1);
	move_a_to_b(stack_a, stack_b);
	move_b_to_a(stack_a, stack_b);
	if (is_sorted(*stack_a))
		final_rotation(stack_a);
}
