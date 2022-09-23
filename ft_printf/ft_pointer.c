/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:21:08 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:48:30 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharr(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	hex_pointer(unsigned long pr)
{
	int	p;

	p = 0;
	if (pr < 16)
	{
		if (pr > 9)
			p = p + ft_putcharr(pr + 87);
		else
			p = p + ft_putcharr(pr + 48);
	}
	else if (pr > 15)
	{
		p = p + hex_pointer(pr / 16);
		p = p + hex_pointer(pr % 16);
	}
	return (p);
}

int	ft_pointer(void *p)
{
	unsigned long	address;

	address = (unsigned long)p;
	ft_putstr_fd("0x", 1);
	return (2 + hex_pointer(address));
}
