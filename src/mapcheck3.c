/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:46:52 by abartell          #+#    #+#             */
/*   Updated: 2022/10/01 11:36:00 by abartell         ###   ########.fr       */
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

void	freemap(t_window *div)
{
	int i = 0;

	while (div->map[i])
	{
		if (div->map[i])
			free(div->map[i]);
		i++;
	}
	if (div->map)
		free(div->map);
}

void	freemcopy(t_window *div)
{
	int i = 0;

	while (div->mcopy[i])
	{
		if (div->mcopy[i])
			free(div->mcopy[i]);
		i++;
	}
	if (div->mcopy)
		free(div->mcopy);
}
