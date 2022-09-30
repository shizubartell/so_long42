/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:55:01 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 10:18:27 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    set_tile(t_window *div, int j, int i)
{
    div->ptile = 0;

	if (div->map[j][i] == '1')
		div->ptile = "./images/walltile64x64.xpm";
	else if (div->map[j][i] == '0')
		div->ptile = "./images/floortile64x64.xpm";
	else if (div->map[j][i] == 'P')
		div->ptile = "./images/boss64x64.xpm";
	else if (div->map[j][i] == 'C')
		div->ptile = "./images/collect64x64.xpm";
	else if (div->map[j][i] == 'E')
		div->ptile = "./images/exitb64x64.xpm";
}

void show_window(t_window *div)
{
	int	j = 0;
	int y = 0;
	int i = 0;
	int x = 0;
	void *img;
	
	while (j < div->nb_row)
	{
		i = 0;
		x = 0;
		
		while (div->map[j][i] != '\n' && div->map[j][i] != '\0')
		{
			set_tile(div, j, i);
			img = mlx_xpm_file_to_image(div->mlx, div->ptile, &div->tile_size, &div->tile_size);
			mlx_put_image_to_window(div->mlx, div->win, img, x, y);
			x = x + div->tile_size;
			i++;
		}
		j++;
		y = y + div->tile_size;
	}
}

void	display(t_window *div)
{
	div->tile_size = 64;
	div->mlx = mlx_init();
	div->win = mlx_new_window(div->mlx, div->nb_col * div->tile_size, div->nb_row * div->tile_size, "so_long");
}