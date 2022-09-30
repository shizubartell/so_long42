/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:36:43 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 14:40:56 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int checks(t_window *div, char *path)
{
    int i;

    i = 0;
    i = i + rectangular(div);
    i = i + characters(div);
    i = i + collectable(div);
    i = i + top_bottom_wall(div);
    i = i + left_right_wall(div);
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

int characters(t_window *div)
{
	int		i;
	int		j;

	i = 0;
	while (div->map[i])
	{
		j = 0;
		while (div->map[i][j])
		{
            if ( div->map[i][j] == '1' || div->map[i][j] == '0' || \
                 div->map[i][j] == 'C' || div->map[i][j] == 'P' || \
                 div->map[i][j] == 'E' || div->map[i][j] == '\n')
                j++;
            else
            {
                ft_printf("Wrong characters found on map, please check map!");
                return (1);
            }                   
	    }
        i++;
    }
}

int collectable(t_window *div)
{
    int i;
    int j;
    int count;

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
    if (count <= 0)
        {
            ft_printf("No collectibles, check map!");
            return(1);
        }
}