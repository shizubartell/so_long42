/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:01 by abartell          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:43 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_opengl_20191021/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

//*********************************************************//
//**                Structure + Main                     **//

typedef struct s_window {
	void	*mlx;
	void	*win;
	char	**tab;
	char	**map;
	char	**mcopy;
	int		nb_col;
	int		nb_row;
	int		tile_size;
	char	*ptile;
	int		reachcount;
	int		allcount;
	int		player_x_pos;
	int		player_y_pos;
	int		playercount;
	int		exitcount;
	int		collectcount;
	int		moves;
}				t_window;

//*********************************************************//
//**                so_long.c                           **//

int			berending(char *path);
int			ft_closing(t_window *window);

//*********************************************************//
//**                additional.c                        **//

int			key_setup(int keyset, t_window *window);
void		move_right(t_window *div);
void		move_left(t_window *div);
void		move_up(t_window *div);
void		move_down(t_window *div);

//*********************************************************//
//**                tile_to_window.c                    **//

void		count_col_row(t_window *div, char *mpath);
void		store_map(t_window *div, char *mpath);
char		*set_tile(t_window *div, int j, int i);
void		show_window(t_window *div);
void		display(t_window *div);

//*********************************************************//
//**                mapcheck1.c                          **//

int			rectangular(t_window *div);
int			characters(t_window *div);
int			collectable(t_window *div);
void		playerone(t_window *div);
int			checks(t_window *div, char *mpath);

//*********************************************************//
//**                mapcheck2.c                          **//

int			top_wall(t_window *div);
int			left_right_wall(t_window *div);
int			exitone(t_window *div);
void		valid_precheck(t_window *div, int x, int y);
int			valid_path(t_window *div);

//*********************************************************//
//**                mapcheck3.c                          **//

void		malloc_maps(t_window *div);
int			playermsg(t_window *div);
int			bot_wall(t_window *div);

#endif