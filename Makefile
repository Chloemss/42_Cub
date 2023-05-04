# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: massavie <massavie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 14:30:35 by cmassavi          #+#    #+#              #
#    Updated: 2023/05/04 17:47:41 by massavie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRCS	=	cub3D/data/get_data.c\
			cub3D/data/init_data.c\
			cub3D/data/print_data.c\
			cub3D/mlx/display.c\
			cub3D/move/angle_move.c\
			cub3D/move/event_key.c\
			cub3D/move/key.c\
			cub3D/move/move.c\
			cub3D/parsing/Check_format/ft_check_cub_format.c\
			cub3D/parsing/Check_format/ft_check_cub.c\
			cub3D/parsing/Check_format/ft_check_texture_format.c\
			cub3D/parsing/Check_If/ft_check_if_can_acces.c\
			cub3D/parsing/Check_If/ft_check_if_forbidden_char.c\
			cub3D/parsing/Check_If/ft_check_if_player.c\
			cub3D/parsing/Check_If/ft_check_if_wrong_map_arg.c\
			cub3D/parsing/Check_If/ft_check_wall.c\
			cub3D/parsing/Check_If_No/ft_is_no_e.c\
			cub3D/parsing/Check_If_No/ft_is_no_n.c\
			cub3D/parsing/Check_If_No/ft_is_no_s.c\
			cub3D/parsing/Check_If_No/ft_is_no_w.c\
			cub3D/parsing/Check_Multiple/ft_is_multiple_e.c\
			cub3D/parsing/Check_Multiple/ft_is_multiple_n.c\
			cub3D/parsing/Check_Multiple/ft_is_multiple_s.c\
			cub3D/parsing/Check_Multiple/ft_is_multiple_w.c\
			cub3D/parsing/Map/ft_create_map_in_tab.c\
			cub3D/parsing/Map/ft_get_file_info.c\
			cub3D/parsing/ft_parsing_manager.c\
			cub3D/raycasting/inter/horizontal/ft_get.c\
			cub3D/raycasting/inter/horizontal/horizontal.c\
			cub3D/raycasting/inter/vertical/ft_get.c\
			cub3D/raycasting/inter/vertical/vertical.c\
			cub3D/raycasting/inter/collision.c\
			cub3D/raycasting/inter/inter.c\
			cub3D/raycasting/draw.c\
			cub3D/raycasting/raycasting.c\
			cub3D/raycasting/useful.c\
			cub3D/useful/ft_split.c\
			cub3D/useful/useful.c\
			cub3D/Utils/ft_access_map.c\
			cub3D/Utils/ft_atoi.c\
			cub3D/Utils/ft_check_if_char.c\
			cub3D/Utils/ft_check_if_good_color_format.c\
			cub3D/Utils/ft_check_if_good_color_range.c\
			cub3D/Utils/ft_check_if_good_path.c\
			cub3D/Utils/ft_check_if_good_start.c\
			cub3D/Utils/ft_complete_map_tab.c\
			cub3D/Utils/ft_convert_color.c\
			cub3D/Utils/ft_count_longest_line.c\
			cub3D/Utils/ft_free.c\
			cub3D/Utils/ft_get_color.c\
			cub3D/Utils/ft_how_many_lines.c\
			cub3D/Utils/ft_init_struct.c\
			cub3D/Utils/ft_is_no_printable.c\
			cub3D/Utils/ft_putstr_fd.c\
			cub3D/Utils/ft_replace_newline.c\
			cub3D/Utils/ft_size.c\
			cub3D/Utils/ft_strdup.c\
			cub3D/Utils/ft_strjoin_classic.c\
			cub3D/Utils/ft_strncmp.c\
			cub3D/Utils/get_next_line_utils.c\
			cub3D/Utils/get_next_line.c\
			cub3D/main.c
			

OBJS= $(SRCS:.c=.o)

CC		=	gcc -Wall -Wextra -Werror -g3

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:	all clean fclean re