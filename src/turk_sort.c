/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:35:56 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/09 17:39:06 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_index(t_stack *stack, t_stack *node)
{
	int index = 0;
	while (stack)
	{
		if (stack == node)
			return index;
		stack = stack->next;
		index++;
	}
	return (-1); // Eğer node bulunamazsa hata döndür
}

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

void calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	int		len_a;
	int		len_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return;

	len_a = get_stack_len(*stack_a);
	len_b = get_stack_len(*stack_b);
	a = *stack_a;

	while (a)
	{
		int index_a = get_index(*stack_a, a); // Elemanın stack_a içindeki indexi
		int index_b = get_index(*stack_b, a->target_node); // Hedefin stack_b içindeki indexi
		
		// Yukarıdan veya aşağıdan gitmenin maliyetini hesapla
		int cost_a = (index_a <= len_a / 2) ? index_a : len_a - index_a;
		int cost_b = (index_b <= len_b / 2) ? index_b : len_b - index_b;

		// İki stack'in birlikte hareket etmesi gerektiği durumu hesapla
		a->cost = cost_a + cost_b;
		
		a = a->next;
	}
}

//int find_cheapest(t_stack *stack)

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
	find_target_a(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
}
