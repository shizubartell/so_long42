/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:42:09 by abartell          #+#    #+#             */
/*   Updated: 2022/09/26 21:15:08 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int     key_setup(int keyset, t_game *window)
{
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