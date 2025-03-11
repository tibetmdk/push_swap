/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:02:41 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/10 19:59:11 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
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
	if (!*stack_a) // Eğer stack_b boşsa, top_a'nın next'i NULL olmalı
		top_b->next = NULL;
	else {
		top_b->next = *stack_a;
		if (*stack_a) // stack_b boş değilse, prev bağlantısını güncelle
			(*stack_a)->prev = top_b;
	}
	top_b->prev = NULL;
	*stack_a = top_b;
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
	if (!*stack_b) // Eğer stack_b boşsa, top_a'nın next'i NULL olmalı
		top_a->next = NULL;
	else {
		top_a->next = *stack_b;
		if (*stack_b) // stack_b boş değilse, prev bağlantısını güncelle
			(*stack_b)->prev = top_a;
	}
	top_a->prev = NULL;
	*stack_b = top_a;
}

void rotate(t_stack **stack)
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
}

void revrotate(t_stack **stack)
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
}