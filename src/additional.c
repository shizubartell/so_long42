/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:42:09 by abartell          #+#    #+#             */
/*   Updated: 2022/10/03 13:30:50 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_setup(int keyset, t_window *window)
{
	if (keyset == W)
		move_up(window);
	if (keyset == S)
		move_down(window);
	if (keyset == A)
		move_left(window);
	if (keyset == D)
		move_right(window);
	if (keyset == ESC)
		ft_closing(window);
	return (0);
}

void	move_right(t_window *div)
{
	if (div->map[div->player_x_pos][div->player_y_pos + 1] == '1' || \
	(div->map[div->player_x_pos][div->player_y_pos + 1] == 'E' && \
	div->collectcount != 0))
		return ;
	if (div->map[div->player_x_pos][div->player_y_pos + 1] == 'C')
		div->collectcount--;
	if (div->map[div->player_x_pos][div->player_y_pos + 1] == 'E' && \
	div->collectcount == 0)
	{
		ft_printf("The dragon returned to it's lair! \n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos][div->player_y_pos + 1] = 'P';
	div->player_y_pos = div->player_y_pos + 1;
	show_window(div);
	div->moves++;
	ft_printf("Stepcount: %d \n", div->moves);
}

void	move_left(t_window *div)
{
	if (div->map[div->player_x_pos][div->player_y_pos - 1] == '1' || \
	(div->map[div->player_x_pos][div->player_y_pos - 1] == 'E' && \
	div->collectcount != 0))
		return ;
	if (div->map[div->player_x_pos][div->player_y_pos - 1] == 'C')
		div->collectcount--;
	if (div->map[div->player_x_pos][div->player_y_pos - 1] == 'E' && \
	div->collectcount == 0)
	{
		ft_printf("The dragon returned to it's lair! \n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos][div->player_y_pos - 1] = 'P';
	div->player_y_pos = div->player_y_pos - 1;
	show_window(div);
	div->moves++;
	ft_printf("Stepcount: %d \n", div->moves);
}

void	move_up(t_window *div)
{
	if (div->map[div->player_x_pos - 1][div->player_y_pos] == '1' || \
	(div->map[div->player_x_pos - 1][div->player_y_pos] == 'E' && \
	div->collectcount != 0))
		return ;
	if (div->map[div->player_x_pos - 1][div->player_y_pos] == 'C')
		div->collectcount--;
	if (div->map[div->player_x_pos - 1][div->player_y_pos] == 'E' && \
	div->collectcount == 0)
	{
		ft_printf("The dragon returned to it's lair! \n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos - 1][div->player_y_pos] = 'P';
	div->player_x_pos = div->player_x_pos - 1;
	show_window(div);
	div->moves++;
	ft_printf("Stepcount: %d \n", div->moves);
}

void	move_down(t_window *div)
{
	if (div->map[div->player_x_pos + 1][div->player_y_pos] == '1' || \
	(div->map[div->player_x_pos + 1][div->player_y_pos] == 'E' && \
	div->collectcount != 0))
		return ;
	if (div->map[div->player_x_pos + 1][div->player_y_pos] == 'C')
		div->collectcount--;
	if (div->map[div->player_x_pos + 1][div->player_y_pos] == 'E' && \
	div->collectcount == 0)
	{
		ft_printf("The dragon returned to it's lair! \n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos + 1][div->player_y_pos] = 'P';
	div->player_x_pos = div->player_x_pos + 1;
	show_window(div);
	div->moves++;
	ft_printf("Stepcount: %d \n", div->moves);
}
