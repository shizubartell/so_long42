/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:46:52 by abartell          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:57 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	malloc_maps(t_window *div)
{
	div->map = malloc(sizeof(char *) * (div->nb_row + 1));
	if (!(div->map))
		exit(0);
	div->mcopy = malloc(sizeof(char *) * (div->nb_row + 1));
	if (!(div->mcopy))
		exit(0);
}

int	playermsg(t_window *div)
{
	if (div->playercount != 1)
	{
		ft_printf("More than one player!\n");
		exit(0);
		return (1);
	}
	return (0);
}

int	bot_wall(t_window *div)
{
	int	i;
	int	bot_row;

	i = 0;
	bot_row = div->nb_row - 1;
	while (div->map[bot_row][i] != '\0' && div->map[bot_row][i] != '\n')
	{
		if (div->map[bot_row][i] != '1')
		{
			ft_printf("Bottom wall is broken!\n");
			exit(0);
			return (1);
		}
		i++;
	}
	return (0);
}
