# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyake <hmiyake@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/08 21:00:30 by hmiyake           #+#    #+#              #
#    Updated: 2018/09/08 23:33:09 by hmiyake          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = *.c

SRCO = $(SRCS:.c=.o)

LIBFT = libft -lft

FT_PRINTF = ft_printf -lftprintf

MLX = minilibx_macos -lmlx

FRM = -framework OpenGL -framework AppKit

FLG = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@make -C $(MLX)
	@gcc   $(FLG) $(SRCS)
	@gcc  $(SRCO) -L $(LIBFT) -L $(FT_PRINTF) -L $(MLX) $(FRM) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C ft_printf/ clean
	@make -C minilibx_macos/ clean
	@rm -f $(SRCO)

fclean: clean
	@make -C libft/ fclean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all