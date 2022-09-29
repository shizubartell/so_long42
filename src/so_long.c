/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:24 by abartell          #+#    #+#             */
/*   Updated: 2022/09/29 14:44:23 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl_20191021/mlx.h"
#include "../inc/so_long.h"

int		ft_closing(t_window *window)
{
		mlx_destroy_window(window->mlx, window->win);
		printf("Exiting so_long");
		exit (0);
		return (0);
}

int	main(int ac, char **av)
{
	
	if (ac == 2)
	{
	t_window window;
	window.nb_col=0;
	int	j;
	int y;
	int i;
	int x;
	char *path_tile;
	void *img;
	
	

	count_col_row(&window, av[1]);
	store_map(&window, av[1]);
	window.tile_size = 64;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.nb_col * window.tile_size, window.nb_row * window.tile_size, "so_long");
	j = 0;
	y = 0;
	while(j < window.nb_row)
	{
		i = 0;
		x = 0;
		while (window.map[j][i] != '\n' && window.map[j][i] != '\0')
		{
			if (window.map[j][i] == '1')
				path_tile = "./images/walltile64x64.xpm";
			else if (window.map[j][i] == '0')
				path_tile = "./images/floortile64x64.xpm";
			else if (window.map[j][i] == 'P')
				path_tile = "./images/boss64x64.xpm";
			else if (window.map[j][i] == 'C')
				path_tile = "./images/collect64x64.xpm";
			img = mlx_xpm_file_to_image(window.mlx, path_tile, &window.tile_size, &window.tile_size);
			mlx_put_image_to_window(window.mlx, window.win, img, x, y);
			x = x + window.tile_size;
			i++;
		}
		j++;
		y = y + window.tile_size;
	}

	

	mlx_key_hook(window.win, key_setup, &window);
	mlx_hook(window.win, 17, 0, ft_closing, &window);
	mlx_loop(window.mlx);
	}
	return (0);
}
