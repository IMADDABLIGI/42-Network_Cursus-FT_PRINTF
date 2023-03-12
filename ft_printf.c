/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:03:51 by idabligi          #+#    #+#             */
/*   Updated: 2022/11/20 19:59:27 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cut(va_list ptr, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		i += printf_ptr(va_arg(ptr, unsigned long));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		i += printf_uns(va_arg(ptr, unsigned int));
	else if ((c == 'x' || c == 'X'))
		i += printf_hex(va_arg(ptr, unsigned int), c);
	else if (c == '%')
		i += ft_putchar('%');
	// else
	// 	i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	ptr;

	va_start(ptr, string);
	i = 0;
	while (*string)
	{
		if (*string == '%')
		{
			i += ft_cut(ptr, *(string + 1));
			string++;
		}
		else
			i += ft_putchar(*string);
		string++;
	}
	va_end(ptr);
	return (i);
}