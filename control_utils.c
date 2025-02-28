/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:34:59 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/28 16:13:08 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*join_args(int ac, char **av)
{
	int		len;
	int		pos;
	int		i;
	char	*buffer;

	len = 0;
	i = 1;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	buffer = (char *)malloc(sizeof(char) * len + 1);
	pos = 0;
	i = 1;
	while (i < ac)
	{
		ft_strcpy(buffer + pos, av[i]);
		pos += ft_strlen(av[i]);
		if (i < ac - 1)
			buffer[pos++] = ' ';
		i++;
	}
	buffer[pos] = '\0';
	return (buffer);
}

int	count_numbers(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32)
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] != '\0' && str[i] != 32)
		}
	}
}

#include <stdio.h>

int main(int ac, char **av)
{
	printf("%s", join_args(ac, av));
}
