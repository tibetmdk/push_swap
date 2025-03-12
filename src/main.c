/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:03:54 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/12 11:36:50 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void printf_both_stack(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *temp1 = stack_a;
    t_stack *temp2 = stack_b;

    ft_printf("A: ");
    while (temp1)
    {
        if (temp1->value) // NULL kontrolü
            ft_printf("%s\t", temp1->value);
        else
            ft_printf("(null)\t");
        temp1 = temp1->next;
    }

    ft_printf("\nB: ");
    while (temp2)
    {
        if (temp2->value) // NULL kontrolü
            ft_printf("%s\t", temp2->value);
        else
            ft_printf("(null)\t");
        temp2 = temp2->next;
    }
    ft_printf("\n");
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
}

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
        print_stack(*data->stack_a);
        ft_printf("\n");
	}
}
