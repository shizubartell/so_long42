/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:36:43 by abartell          #+#    #+#             */
/*   Updated: 2022/10/03 13:22:34 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	checks(t_window *div, char *mpath)
{
	int	i;

	i = 0;
	i = i + rectangular(div);
	i = i + characters(div);
	i = i + collectable(div);
	i = i + top_wall(div);
	i = i + bot_wall(div);
	i = i + left_right_wall(div);
	i = i + berending(mpath);
	playerone(div);
	i = i + playermsg(div);
	i = i + exitone(div);
	i = i + valid_path(div);
	if (i == 0)
		return (0);
	return (1);
}

int	rectangular(t_window *div)
{
	int	i;

	i = 1;
	while (i < div->nb_row)
	{
		if (ft_strlen(div->map[0]) != ft_strlen(div->map[i]))
		{
			ft_printf("Map is not rectangular!, first strlen: %d \
            second strlen  %d\n", ft_strlen(div->map[0]), \
			ft_strlen(div->map[i]));
			return (1);
		}
		i++;
	}
	return (0);
}

int	characters(t_window *div)
{
	int	i;
	int	j;

	i = 0;
	while (div->map[i])
	{
		j = 0;
		while (div->map[i][j])
		{
			if (div->map[i][j] == '1' || div->map[i][j] == '0' || \
				div->map[i][j] == 'C' || div->map[i][j] == 'P' || \
				div->map[i][j] == 'E' || div->map[i][j] == '\n')
				j++;
			else
			{
				ft_printf("Wrong characters found on map, please check map!");
				exit(0);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	collectable(t_window *div)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (div->map[i])
	{
		j = 0;
		while (div->map[i][j])
		{
			if (div->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	div->collectcount = count;
	if (count <= 0)
	{
		ft_printf("No collectibles, check map!");
		exit(0);
		return (1);
	}
	return (0);
}

void	playerone(t_window *div)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = 0;
	while (div->map[i])
	{
		j = 0;
		while (div->map[i][j])
		{
			if (div->map[i][j] == 'P')
			{
				player++;
				div->player_x_pos = i;
				div->player_y_pos = j;
			}
			j++;
		}
		i++;
	}
	div->playercount = player;
}
