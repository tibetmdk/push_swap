/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:03:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 20:52:31 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void    printf_both_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a && !stack_b)
    {
        ft_printf("Stacks are empty!\n");
        return;
    }

    ft_printf("A: ");
    while (stack_a)
    {
        ft_printf("%d\t", stack_a->value ? stack_a->value : 0);
        stack_a = stack_a->next;
    }

    ft_printf("\nB: ");
    while (stack_b)
    {
        ft_printf("%d\t", stack_b->value ? stack_b->value : 0);
        stack_b = stack_b->next;
    }
    ft_printf("\n\n\n");
}

static void print_stack(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp)
    {
        ft_printf("%d\n", temp->value);
        temp = temp->next;
    }
}*/

int main(int ac, char **av)
{
    t_data  *data;
    char    *joined_args;

    if (ac >= 2)
    {
        data = (t_data *)malloc(sizeof(t_data));
        if (!data)
            return (1);
        joined_args = join_args(ac, av);
        if (!joined_args)
            return (free(data), 1);
        data->buffer = ft_split(joined_args, ' ');
        free(joined_args);
        if (!data->buffer)
            return (free(data), 1);
		if (parse_input(data) == 0)
			init_stack_a(data);
        turk_sort(data->stack_a, data->stack_b);
        //print_stack(*data->stack_a);
        //ft_printf("\n");
	}
}
