/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:24:38 by idabligi          #+#    #+#             */
/*   Updated: 2022/11/20 12:43:09 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_counthex(unsigned int nub)
{
	int	i;

	i = 0;
	if (!nub)
		return (1);
	while (nub)
	{
		nub = nub / 16;
		i++;
	}
	return (i);
}

int	printf_hex(unsigned int num, char c)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_counthex(num);
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	j = 0;
	while ((i - j) > 0)
	{
		if ((num % 16) >= 0 && (num % 16) <= 9)
			ptr[i - j - 1] = (num % 16) + '0';
		else if (c == 'x' && (num % 16) >= 10 && (num % 16) < 16)
			ptr[i - j - 1] = (num % 16) + 87;
		else if (c == 'X' && (num % 16) >= 10 && (num % 16) < 16)
			ptr[i - j - 1] = (num % 16) + 55;
		num = num / 16;
		j++;
	}
	ptr[i] = '\0';
	ft_putstr(ptr);
	return (free(ptr), i);
}
