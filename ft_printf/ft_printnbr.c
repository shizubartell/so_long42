/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:18:51 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:50:41 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnbr(int min)
{
	int	i;

	i = 0;
	if (min == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = 11;
	}
	else if (min < 0)
	{
		i = i + ft_putchar('-');
		min = min * -1;
		i = i + ft_printnbr(min);
	}
	else if (min > 9)
	{
		i = i + ft_printnbr(min / 10);
		i = i + ft_printnbr(min % 10);
	}
	else
	i = i + ft_putchar(min + 48);
	return (i);
}
