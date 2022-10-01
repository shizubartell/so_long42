/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:42:09 by abartell          #+#    #+#             */
/*   Updated: 2022/10/01 16:26:55 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     key_setup(int keyset, t_window *window)
{
    // if(window)
    //     printf("Keyset is : %d\n", keyset);
    if (keyset == W)
        move_up(window);
    if (keyset == 1)
        move_down(window);
    if (keyset == A)
        move_left(window);
    if (keyset == D)
        move_right(window);
    if (keyset == 53)
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
		ft_printf("The dragon returned to it's lair!\n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos][div->player_y_pos + 1] = 'P';
	div->player_y_pos = div->player_y_pos + 1;
	show_window(div);
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
		ft_printf("The dragon returned to it's lair!\n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos][div->player_y_pos - 1] = 'P';
	div->player_y_pos = div->player_y_pos - 1;
	show_window(div);
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
		ft_printf("The dragon returned to it's lair!\n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos - 1][div->player_y_pos] = 'P';
	div->player_x_pos = div->player_x_pos - 1;
	show_window(div);
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
    div->collectcount== 0)
	{
		ft_printf("The dragon returned to it's lair!\n");
		ft_closing(div);
	}
	div->map[div->player_x_pos][div->player_y_pos] = '0';
	div->map[div->player_x_pos + 1][div->player_y_pos] = 'P';
	div->player_x_pos = div->player_x_pos + 1;
	show_window(div);
}