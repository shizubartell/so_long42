/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:42:09 by abartell          #+#    #+#             */
/*   Updated: 2022/09/25 20:46:07 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     key_setup(int keyset, t_window *window)
{
    if(window)
        printf("Keyset is : %d\n", keyset);
    if (keyset== 13)
        printf("Character goes up\n");
    if (keyset == 0)
        printf("Character goes down\n");
    if (keyset == 1)
        printf("Character goes left\n");
    if (keyset == 2)
        printf("Character goes right\n");
    if (keyset == 53)
        ft_closing(window);
    return (0);
}

int		ft_closing(t_window *window)
{
		mlx_destroy_window(window->mlx, window->win);
		printf("Exiting so_long");
		exit (0);
		return (0);
}
