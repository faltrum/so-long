# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 11:11:16 by oseivane          #+#    #+#              #
#    Updated: 2023/11/13 12:50:41 by oseivane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

INCLUDES = -I./includes

SRC_DIR = src/

OBJ_DIR = obj/

MLX_DIR = mlx/

LIB_DIR = libraries/libft

FT_PRINTF_DIR = libraries/ft_printf

INCLUDES_DIR = ./includes/*.h

INCLUDES_LIB = -I./$(LIB_DIR)

INCLUDES_LIB += -I./$(FT_PRINTF_DIR)

INCLUDES_LIB += -I./$(MLX_DIR)

LIB = -L./$(LIB_DIR) -lft

LIB += -L./$(FT_PRINTF_DIR) -lftprintf

LIB += -L./$(MLX_DIR) -lmlx -g -framework OpenGl -framework AppKit

CFLAGS = -Werror -Wall -Wextra

OBJF = .cache_exists

SRC = 	so_long \
		ft_play_game \
		ft_init_values \
		ft_go \
		ft_format_ber \
		ft_error \
		ft_frees \
		parse_check_map \
		parse_check_map2 \
		render_all \
		key_hook \
		press_key \

SOURCES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: libraries $(NAME)

$(NAME):	$(OBJECTS)
		gcc $(CFLAGS) $(OBJECTS) $(INCLUDES) $(INCLUDES_LIB) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES_DIR) | $(OBJF)
			gcc $(CFLAGS) $(INCLUDES) $(INCLUDES_LIB) -c $< -o $@
$(OBJF):
		@mkdir -p $(OBJ_DIR)
clean:
			rm -f $(OBJECTS)
	
fclean:		clean
			rm -f $(NAME)
			make -C $(LIB_DIR) fclean
			make -C $(FT_PRINTF_DIR) fclean

re:			fclean all

libraries:
			make -C $(LIB_DIR)
			make -C $(FT_PRINTF_DIR)

.PHONY:		all bonus clean fclean re libraries