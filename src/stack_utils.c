/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:04 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/08 14:33:29 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        ft_error(); // Bellek hatası yönetimi
    new_node->value = value;
    new_node->index = -1; // Başlangıçta indeks belirlenmemiş
    new_node->push_cost = 0;
    new_node->cheapest = 0;
    new_node->above_med = 0;
    new_node->target_node = NULL;
    new_node->prev = NULL;
    new_node->next = NULL;
    return (new_node);
}

void append_node(t_stack **stack, int value)
{
    t_stack *new_node;
    t_stack *temp;

    new_node = create_node(value);
    if (!*stack) // Eğer stack boşsa, direkt olarak ekle
    {
        *stack = new_node;
        return;
    }
    temp = *stack;
    while (temp->next) // Listenin sonuna git
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}

int init_stack_a(t_data *data)
{
    int i;

    i = 0;
    data->stack_a = (t_stack **)malloc(sizeof(t_stack *));
    data->stack_b = NULL; // Başlangıçta stack_b boş

    if (!data->stack_a)
        ft_error(); // Bellek tahsis hatası kontrolü
    
    *data->stack_a = NULL; // Başlangıçta stack boş

    while (i < data->tab_size)
    {
        append_node(data->stack_a, data->tab[i]);
        i++;
    }
    return (1);
}