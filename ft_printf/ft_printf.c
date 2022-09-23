/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:28:49 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:31:00 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_arguments(va_list args, const char variable)
{
	if (variable == 'c')
		return (ft_character(va_arg(args, int)));
	if (variable == 's')
		return (ft_string(va_arg(args, char *)));
	if (variable == 'i' || variable == 'd')
		return (ft_printnbr(va_arg(args, int)));
	if (variable == 'x')
		return (ft_lc_hexa_deci(va_arg(args, unsigned int)));
	if (variable == 'X')
		return (ft_uc_hexa_deci(va_arg(args, unsigned long)));
	if (variable == 'p')
		return (ft_pointer(va_arg(args, void *)));
	if (variable == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (variable == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counting;
	int		i;

	counting = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			counting = counting + ft_arguments(args, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			counting++;
		}
			i++;
	}
	va_end(args);
	return (counting);
}
