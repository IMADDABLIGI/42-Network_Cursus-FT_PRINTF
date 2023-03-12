/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:22:37 by idabligi          #+#    #+#             */
/*   Updated: 2022/11/20 12:27:37 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int	ft_printf(const char *string, ...);

int	printf_hex(unsigned int num, char c);

int	printf_ptr(unsigned long num);

int	printf_uns(unsigned int n);

int	ft_putnbr(long n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
