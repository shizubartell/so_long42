/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:24 by abartell          #+#    #+#             */
/*   Updated: 2022/09/23 19:25:01 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl_20191021/mlx.h"
#include "../inc/so_long.h"

int	main()
{
	t_window window;
	int		width;
	int		height;
	char	path_wall_tile[]="./images/lavatile.xpm";
	int		lavatile;
	void	*img_wall;

	width = 64;
	height = 64;
	
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 16*width, 16*height, "so_long");
	
	img_wall = mlx_xpm_file_to_image(window.mlx, path_wall_tile, &width, &height);
	lavatile = mlx_put_image_to_window(window.mlx, window.win, img_wall, 64, 64);
	mlx_loop(window.mlx);
	return (0);
}
