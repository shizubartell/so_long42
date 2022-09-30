/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:03:05 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 14:45:31 by abartell         ###   ########.fr       */
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
    int j;
    int right_col;

    j = 0;
    right_col = div->nb_col - 1;
    while (j < div->nb_row)
    {
        if (div->map[j][0] != '1')
        {
            ft_printf("Left wall is broken!\n");
            return (1);
        }
        j++;
    }
    j = 0;
    while (j , div->nb_row)
    {
        if (div->map[j][right_col] != '1')
        {
            ft_printf("Right wall is broken\n");
            return (1);
        }
        j++;
    }
}
