/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:03:05 by abartell          #+#    #+#             */
/*   Updated: 2022/10/01 11:45:21 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int top_bottom_wall(t_window *div)
{
    int i;
    int bot_row;

    i = 0;
    bot_row = div->nb_row - 1;
    while (div->map[0][i] != '\0' && div->map[0][i] != '\n')
        {
            if (div->map[0][i] != '1')
            {
                ft_printf("Top wall is broken!\n");
                return(1);
            }
            i++;
        }
    i = 0;
    while (div->map[bot_row][i] != '\0' && div->map[bot_row][i] != '\n')
        {
            if (div->map[bot_row][i] != '1')
            {
                ft_printf("Bottom wall is broken!\n");
                return (1);            
            }
            i++;
        }
}

int left_right_wall(t_window *div)
{
    int i;

    i = 0;
    while (i < div->nb_row)
    {
        if (div->map[i][0] != '1')
        {
            ft_printf("Left wall is broken!\n");
            return (1);
        }
        i++;
    }
    i = 0;
    while (i < div->nb_row)
    {
        if (div->map[i][div->nb_col - 1] != '1')
        {
            ft_printf("Right wall is broken\n");
            return (1);
        }
        i++;
    }
}

int exitone(t_window *div)
{
	int	nb_e = 0;
    int i = 0;
    int j = 0;

	while (div->map[i])
	{
		j = 0;
		while (div->map[i][j])
		{
			if (div->map[i][j] == 'E')
				nb_e++;
			j++;
		}
		i++;
	}
    div->exitcount = nb_e;
	if (nb_e != 1)
	{
		ft_printf("More than one exit!\n");
        exit (0);
        return (1);
	}
}

void    valid_precheck(t_window *div, int x, int y)
{
    div->allcount = div->collectcount + div->exitcount;
    if (div->mcopy[x][y] == '1')
        return ;
    if (div->mcopy[x][y] == 'C')
        div->reachcount++;
    if (div->mcopy[x][y] == 'E')
        div->reachcount++;
    div->mcopy[x][y] = '1';
    valid_precheck(div, x, y + 1);
    valid_precheck(div, x, y - 1);
    valid_precheck(div, x + 1, y);
    valid_precheck(div, x - 1, y);
}

int valid_path(t_window *div)
{
    int x;
    int y;
    
    x = div->player_x_pos;
    y = div->player_y_pos;
    div->reachcount = 0;
    valid_precheck(div, x, y);
    ft_printf("Counter of all reachable things: %d\n", div->reachcount);
    ft_printf("Counter of all things: %d\n", div->allcount);
    if (div->allcount != div->reachcount)
    {
        ft_printf("No valid path to play the game!");
        // freemap(div);
        // freemcopy(div);
        return (1);
    }
    return (0);
}
