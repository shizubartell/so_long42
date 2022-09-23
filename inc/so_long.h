/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:25:01 by abartell          #+#    #+#             */
/*   Updated: 2022/09/23 14:04:36 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_window {
    void    *mlx;
    void    *win;
}				t_window;
