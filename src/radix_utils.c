/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:40:05 by tmidik            #+#    #+#             */
/*   Updated: 2025/03/04 18:22:46 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int *arr, int size)
{
	int	i;
	int	max;
	int	bits;

	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	push_a(t_data *data)
{
	if (data->top_b == -1)
		return ;
	data->stack_a[++data->top_a] = data->stack_b[data->top_b--];
}

static void	push_b(t_data *data)
{
	if (data->top_a == -1)
		return ;
	data->stack_b[++data->top_b] = data->stack_a[0];
	for (int k = 0; k < data->top_a; k++) 
		data->stack_a[k] = data->stack_a[k + 1];
	data->top_a--;
}

/*static void	rotate_a(t_data *data)
{
    int	temp;
    int	i;
    
    i = 0;
    if (data->top_a < 1)
        return ;
    temp = data->stack_a[0];
    while (i < data->top_a)
    {
        data->stack_a[i] = data->stack_a[i + 1];
        i++;
    }
    data->stack_a[data->top_a] = temp;
}*/

void	radix_sort(t_data *data)
{
	int	bits;
	int	i;
	int	j;

	// ✅ Stack'ler için bellek ayır
	data->stack_a = (int *)malloc(sizeof(int) * data->tab_size);
	data->stack_b = (int *)malloc(sizeof(int) * data->tab_size);
	if (!data->stack_a || !data->stack_b) // Malloc başarısız olursa programı sonlandır
	{
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}

	// ✅ `stack_a`'ya başlangıç dizisini yükle
	for (i = 0; i < data->tab_size; i++)
		data->stack_a[i] = data->tab[i];

	data->top_a = data->tab_size - 1;
	data->top_b = -1;

	bits = get_max_bits(data->stack_a, data->tab_size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		int size = data->tab_size;
		while (j < size)
		{
			if (((data->stack_a[0] >> i) & 1) == 0)
				push_b(data);
			j++;
		}
		while (data->top_b != -1)
			push_a(data);
		i++;
	}
}
