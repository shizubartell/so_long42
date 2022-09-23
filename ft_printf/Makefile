# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abartell <abartell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:29:58 by abartell          #+#    #+#              #
#    Updated: 2022/07/22 20:41:56 by abartell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME	=	libftprintf.a

LIBFT	=	libft.a
LIBFT_PATH	=	./libft

#srcs for printf
SRCS	=	ft_printf.c \
			ft_character.c \
			ft_pointer.c \
			ft_string.c \
			ft_printnbr.c \
			ft_lc_hexa_deci.c \
			ft_uc_hexa_deci.c \
			ft_unsigned.c \


#RM is a reference to a "make" variable
RM		= rm -f

#compiler
CC		= gcc

#using different flags for the compiler gcc
FLAGS	= -Wall -Wextra -Werror -I. -I$(LIBFT_PATH)

#targeting all files
#% used as rule definitions
# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 		make -C $(LIBFT_PATH)

# NAME: all
# all: $(NAME)
# $(NAME) : $(OBJS) $(USR_LIB)
# 	ar rcs $(NAME) $(OBJS)
#implictig rules for compiling a c programm
#compiling with flags
#CFLAGS = extra flags for c compiler
OBJS:= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $^ $(FLAGS) -o $@

NAME: all
all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@echo
	cd libft; make; cp libft.a ..;
	cd ..;
	mv libft.a $(NAME);


#deleting all executable files and objects
clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

#targets that do not refer to files but are just actions
.PHONY: all clean fclean re libft