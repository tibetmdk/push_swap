/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:28:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/09 16:50:42 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_best_match(t_stack *stack_b, int value)
{
    t_stack *b = stack_b;
    t_stack *best_match = NULL;

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
    t_stack *b = stack_b;
    t_stack *max_node = stack_b;

    while (b)
    {
        if (b->value > max_node->value)
            max_node = b;
        b = b->next;
    }
    return max_node;
}

void find_target_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *a;

    if (!stack_a || !stack_b || !*stack_a || !*stack_b)
        return;

    a = *stack_a;
    while (a)
    {
        a->target_node = find_best_match(*stack_b, a->value);
        if (!a->target_node)
            a->target_node = find_max_in_stack(*stack_b);
        ft_printf("%d\n", a->target_node->value);
        a = a->next;
    }
}