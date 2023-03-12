/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:45:43 by idabligi          #+#    #+#             */
/*   Updated: 2022/11/20 12:47:40 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countptr(unsigned long num)
{
	int	i;

	i = 0;
	if (!num)
		return (1);
	while (num)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

int	printf_ptr(unsigned long num)
{
	int		i;
	int		j;
	char	*ptr;

	i = ft_countptr(num);
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	j = 0;
	while ((i - j) > 0)
	{
		if ((num % 16) >= 0 && (num % 16) <= 9)
			ptr[i - j - 1] = (num % 16) + '0';
		else if ((num % 16) >= 10 && (num % 16) < 16)
			ptr[i - j - 1] = (num % 16) + 87;
		num = num / 16;
		j++;
	}
	ptr[i] = '\0';
	ft_putstr("0x");
	ft_putstr(ptr);
	return (free(ptr), (i + 2));
}
