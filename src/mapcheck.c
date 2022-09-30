/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:36:43 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 12:29:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int checks(t_window *div, char *path)
{
    int i;

    i = 0;
    i = i + rectangular(div);
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
			ft_printf("Map is not rectangular!, first strlen: %d second strlen  %d\n", ft_strlen(div->map[0]), ft_strlen(div->map[i]));
			return (1);
		}
		i++;
	}
	return (0);
}