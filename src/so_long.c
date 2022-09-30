/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:24 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 12:09:14 by abartell         ###   ########.fr       */
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
	
		count_col_row(&window, av[1]);
		store_map(&window, av[1]);
		if (checks(&window, av[1]) == 0)
		{
			display(&window);
			show_window(&window);
			mlx_key_hook(window.win, key_setup, &window);
			mlx_hook(window.win, 17, 0, ft_closing, &window);
			mlx_loop(window.mlx);
		}
	}
	return (0);
}
