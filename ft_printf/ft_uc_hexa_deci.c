/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uc_hexa_deci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:51:57 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:52:56 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharu(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_uc_hexa_deci(unsigned int max)
{
	int	ma;

	ma = 0;
	if (max < 16)
	{
		if (max > 9)
			ma = ma + ft_putcharu(max + 55);
		else
			ma = ma + ft_putcharu(max + 48);
	}
	else if (max > 15)
	{
		ma = ma + ft_uc_hexa_deci(max / 16);
		ma = ma + ft_uc_hexa_deci(max % 16);
	}
	return (ma);
}
