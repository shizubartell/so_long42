/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:24 by abartell          #+#    #+#             */
/*   Updated: 2022/09/24 19:19:26 by abartell         ###   ########.fr       */
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
		int		width;
		int		height;
		int		fd;
		// char	path_wall_tile[]="./images/lavatile.xpm";
		// char	path_floor_tile[]="./images/floor.xpm";
		// int		lavatile;
		// int		floor;
		// void	*img_wall;
		// void	*img_floor;
		char	*path_tile;
		int		nb_col;
		void	*img;
		char	*line;
		char	**map;
		int		nb_row;
		int		row_index;
		int		i;
		int		j;
		int		x;
		int		y;

		fd = open(av[1], O_RDONLY);
		// width = 16;
		// height = 16;
		line = get_next_line(fd);
		nb_col = ft_strlen(line) - 1;
		nb_row = 0;
		row_index = 1;
		while(line != NULL)
		{
			line = get_next_line(fd);
			nb_row++;
		}
		close(fd);
		printf("nb of column is: %d\n", nb_col);
		printf("nb of rows is: %d\n", nb_row);
		map = malloc(sizeof(char *) * (nb_row + 1));
		window.tab = map;
		if (!map)
			return (0);
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		map[0] = line;
		while(line != NULL)
		{
			line = get_next_line(fd);
			map[row_index] = line;
			printf("%s", line);
			row_index++;
		}
		width = 16;
		height = 16;
		window.mlx = mlx_init();
		window.win = mlx_new_window(window.mlx, nb_col*width, (row_index -1)*height, "so_long");
		printf("row_index is : %d\n", row_index);
		j = 0;
		while(j < nb_row)
		{
			i = 0;
			x = 0;
			while (map[j][i] != '\n' && map[j][i] != '\0')
			{
				if (map[j][i] == '1')
					path_tile = "./images/lavatile.xpm";
				else if (map[j][i] == '0')
					path_tile = "./images/floor.xpm";
				img = mlx_xpm_file_to_image(window.mlx, path_tile, &width, &height);
				mlx_put_image_to_window(window.mlx, window.win, img, x, y);
				x = x + width;
				i++;
			}
			j++;
			y = y + height;
		}
	mlx_key_hook(window.win, key_setup, &window);
	mlx_hook(window.win, 17, 0, ft_closing, &window);
	mlx_loop(window.mlx);
	}
	return (0);
}
