/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:06:00 by abartell          #+#    #+#             */
/*   Updated: 2022/09/30 14:32:26 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void count_col_row(t_window *div, char *mpath)
{
    int fd;
    char *line;
    int nb_row;
    
    fd = open(mpath, O_RDONLY);
	line = get_next_line(fd);
	div->nb_col = strlen(line) - 1;
	nb_row = 0;
	while(line != NULL)
	{
		line = get_next_line(fd);
		nb_row++;
	}
    div->nb_row = nb_row;
	close(fd);
	div->map = malloc(sizeof(char *) * (div->nb_row + 1));
}

void store_map(t_window *div, char *mpath)
{
	int	fd;
	char *line;
	int row_index;

	row_index = 1;
	fd = open(mpath, O_RDONLY);
	line = get_next_line(fd);
	div->map[0] = line;
	printf("%s", div->map[0]);
	while(line != NULL)
	{
		line = get_next_line(fd);
		div->map[row_index] = line;
		printf("%s", div->map[row_index]);
		row_index++;
	}
}