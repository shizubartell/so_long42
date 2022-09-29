/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:01 by abartell          #+#    #+#             */
/*   Updated: 2022/09/29 16:12:49 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx_opengl_20191021/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"


//*********************************************************//
//**                Structure                           **//

typedef struct	s_window {
    void    *mlx;
    void    *win;
    char    **tab;
    char    **map;
    int     nb_col;
    int     nb_row;
    int     tile_size;
    char    *ptile;
}				t_window;

int     ft_closing(t_window *window);
int     key_setup(int keyset, t_window *window);

//*********************************************************//
//**                mapfunc.c                           **//

void count_col_row(t_window *div, char *mpath);
void store_map(t_window *div, char *mpath);

//*********************************************************//
//**                tile_to_window.c                    **//

void    set_tile(t_window *div, int j, int i);
void show_window(t_window *div);