/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:24 by abartell          #+#    #+#             */
/*   Updated: 2022/09/23 14:08:35 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_opengl_20191021/mlx.h"
#include "../inc/so_long.h"

int	main()
{
	t_window window;
	void	*img;
	int		width;
	int		height;
	char	path_floor_tile[]="./images/tileset.xpm";
	int		tileset;

	width = 16;
	height = 16;
	
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 640, 480, "so_long");
	img = mlx_xpm_file_to_image(window.mlx, path_floor_tile, &width, &height);
	tileset = mlx_put_image_to_window(window.mlx, window.win, img, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}
