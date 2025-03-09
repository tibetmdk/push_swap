/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:35:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/09 11:48:23 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"
int	get_stack_len(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

//int calculate_cost(t_stack *stack)


//int find_cheapest(t_stack *stack)

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	
	len_a = get_stack_len(*stack_a);
	if (len_a-- > 3)
		push_b(stack_a, stack_b);
	if (len_a-- > 3 )
		push_b(stack_a, stack_b);
	find_target_a(stack_a, stack_b);
}
