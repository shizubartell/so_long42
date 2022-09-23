/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 21:09:06 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:54:15 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharui(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_unsigned(unsigned int u)
{
	int	i;

	i = 0;
	if (u > 9)
	{
		i = i + ft_printnbr(u / 10);
		i = i + ft_putcharui(u % 10 + 48);
	}
	else
	{
		i = i + ft_putcharui(u + 48);
	}
	return (i);
}
