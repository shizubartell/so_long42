/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:02:05 by abartell          #+#    #+#             */
/*   Updated: 2022/07/22 21:46:05 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_character(int c);
int	ft_string(char *str);
int	ft_printnbr(int min);
int	ft_lc_hexa_deci(unsigned int hex);
int	ft_uc_hexa_deci(unsigned int max);
int	ft_pointer(void *ptr);
int	ft_unsigned(unsigned int u);

#endif
