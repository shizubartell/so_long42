/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:24:33 by abartell          #+#    #+#             */
/*   Updated: 2022/09/25 20:58:02 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int nb_of_col(char **path)
{
    int nb_col;
    int fd;
    char    *line;

    fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	nb_col = ft_strlen(line) - 1;
	close(fd);
    return(nb_col);
}
