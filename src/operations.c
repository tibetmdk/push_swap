/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:02:41 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 20:33:01 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char stack_name)
{
	t_stack *first;
	t_stack *second;

	if(!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	if (stack_name == 'a')
		ft_printf("sa\n");
	else if (stack_name == 'b')
		ft_printf("sb\n");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;

	if (!*stack_b)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (!*stack_a)
		top_b->next = NULL;
	else {
		top_b->next = *stack_a;
		if (*stack_a)
			(*stack_a)->prev = top_b;
	}
	top_b->prev = NULL;
	*stack_a = top_b;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;

	if (!*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (!*stack_b)
		top_a->next = NULL;
	else {
		top_a->next = *stack_b;
		if (*stack_b) // stack_b boş değilse, prev bağlantısını güncelle
			(*stack_b)->prev = top_a;
	}
	top_a->prev = NULL;
	*stack_b = top_a;
	ft_printf("pb\n");
}

void rotate(t_stack **stack, char stack_name)
{
    t_stack *first;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;

    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;

    last = *stack;
    while (last->next)
        last = last->next;

    last->next = first;
    first->prev = last;
    first->next = NULL;
	if (stack_name == 'a')
		ft_printf("ra\n");
	else if (stack_name == 'b')
		ft_printf("rb\n");
}

void revrotate(t_stack **stack, char stack_name)
{
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
	if (stack_name == 'a')
		ft_printf("rra\n");
	else if (stack_name == 'b')
		ft_printf("rrb\n");
}