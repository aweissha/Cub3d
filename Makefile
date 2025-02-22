NAME = cub3D


LIBFT	= libft/

LIBFTTARGET	= $(LIBFT)libft.a

SRC_DIR = src/

CC = cc
CFLAGS = -Wunreachable-code -Ofast -Wall -Werror -Wextra -g
# -g -fsanitize=address

MLX42FLAGS = -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
# SAN_LDFLAGS = -L ../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitizer

HEADER_FILE = include/cub3d.h

RM = rm -f


SRCS =		$(SRC_DIR)main.c \
			$(SRC_DIR)init.c \
			$(SRC_DIR)init_2.c \
			$(SRC_DIR)init_3.c \
			$(SRC_DIR)error.c \
			$(SRC_DIR)error_2.c \
			$(SRC_DIR)raycasting.c \
			$(SRC_DIR)raycasting_utils.c \
			$(SRC_DIR)ray_algorithm.c \
			$(SRC_DIR)render.c \
			$(SRC_DIR)textures.c \
			$(SRC_DIR)weapon.c \
			$(SRC_DIR)map.c \
			$(SRC_DIR)map2.c \
			$(SRC_DIR)map3.c \
			$(SRC_DIR)map_utils.c \
			$(SRC_DIR)map_utils2.c \
			$(SRC_DIR)map_validation.c \
			$(SRC_DIR)mini_map.c \
			$(SRC_DIR)mini_map2.c \
			$(SRC_DIR)player_movement.c \


OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) 
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(MLX42FLAGS) $(OBJS) -o $(NAME) $(LIBFTTARGET) libmlx42.a 
# $(SAN_LDFLAGS)
all: $(NAME) 

clean:
	@$(MAKE) -C $(LIBFT) fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
