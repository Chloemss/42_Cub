/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:07:01 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:27:49 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <strings.h>
# include <sys/stat.h>
# include <stdbool.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define PINK 0xFF69B4

//	----------------------------------------------------------------------------
//										Colour
//	----------------------------------------------------------------------------

# define BLACK_L "\001\033[1;30m\002"
# define RED_L "\001\033[1;31m\002"
# define GREEN_L "\001\033[1;32m\002"
# define YELLOW_L "\001\033[1;33m\002"
# define BLUE_L "\001\033[1;34m\002"
# define PURPLE_L "\001\033[1;35m\002"
# define CYAN_L "\001\033[1;36m\002"
# define WHITE_L "\001\033[1;37m\002"
# define RESET "\001\033[0m\002"

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT 123
#  define RIGHT 124
#  define W 13
#  define S 1
#  define D 2
#  define A 0
#  define ESC 53
#  define RED_BUTTON 79
#  define CLOSERED 17
# else
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65364
#  define DOWN 65362
#  define W 119
#  define S 115
#  define D 100
#  define A 97
#  define ESC 65307
#  define RED_BUTTON 79
#  define CLOSERED 33
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_coord
{
	double	x;
	double	y;
}t_coord;

typedef struct s_parse
{
	int		argc;
	char	**argv;
	int		line;
	int		map_line;
	int		color_f;
	int		color_c;
	int		longest_line;
	int		size;
	char	**file_info;
	char	**map_tab;
}			t_parse;

typedef struct s_cub
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			*filename;
	char			**texture_tab;
	int				cpt;
	char			*texture_f;
	char			*texture_c;
	char			**map;
	int				color_f;
	int				color_c;
	int				map_x;
	int				map_y;
	int				yscreen;
	int				xscreen;
	double			x_player;
	double			y_player;
	double			pov;
	double			dist;

	int				key_left;
	int				key_right;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_esc;

	int				bpp_text[6];
	int				size_line_text[6];
	int				endian_text[6];
	char			*ptr_text[6];
	void			*text[6];
	int				widthtext[6];
	int				heighttext[6];
	int				actualtext;
	unsigned int	color;
	void			*img;
	char			*pxl;
	int				bpp;
	int				size_line;
	int				endian;
}					t_cub;

char	*ft_strjoin_classic(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_convert_color(char **buffer, t_parse *data, char **color_f,
			char **color_c);
int		ft_convert_to_hex(char *buf);
int		ft_get_color(char **buffer, t_parse *data);
char	*get_next_line(int fd);
int		ft_check_if_can_acces(char **buffer, char **env, t_cub *cub);
char	*ft_strdup(char *s);
bool	ft_check_texture_format(char **buffer);
void	ft_complete_map_tab(t_parse *data);
void	ft_replace_newline(t_parse	*data);
int		ft_acces_map(t_parse *data);
bool	ft_is_no_printable(char c);
bool	ft_check_if_good_color_range(char **buffer);
bool	ft_check_if_forbidden_char(t_parse *data);
int		ft_check_if_wrong_map_arg(t_parse *data, t_cub *cub, char **env);
bool	ft_check_wall(t_parse *data);
bool	ft_check_if_char(char *line);
int		ft_how_many_lines(t_parse *data);
void	ft_init_struct(int argc, char *argv[], t_parse *data);
int		ft_size(t_parse *data);
char	*ft_strdup(char *s);
int		ft_atoi(const char *str);
void	ft_free(char **tab);
bool	ft_check_if_good_start(char **buffer);
bool	ft_check_if_good_color_format(char **buffer);
bool	ft_check_if_good_path(char **buffer);
void	ft_count_longest_line(t_parse *data);
void	ft_parsing_manager(t_parse *data, t_cub *cub,
			char **env);
int		ft_get_file_info(t_parse *data);
void	ft_replace_space_to_wall(t_parse *data);
int		ft_create_map_in_tab(t_parse *data);
void	ft_check_cub(int argc, char *argv[]);
bool	ft_check_cub_format(char *argv);
bool	ft_is_no_e(t_parse *data, t_cub *cub);
bool	ft_is_no_n(t_parse *data, t_cub *cub);
bool	ft_is_no_s(t_parse *data, t_cub *cub);
bool	ft_is_no_w(t_parse *data, t_cub *cub);
int		ft_is_multiple_w(t_parse *data, t_cub *cub);
int		ft_is_multiple_n(t_parse *data, t_cub *cub);
int		ft_is_multiple_e(t_parse *data, t_cub *cub);
int		ft_is_multiple_s(t_parse *data, t_cub *cub);
bool	ft_check_if_forbidden_char(t_parse *data);
bool	ft_check_if_player(t_parse *data, t_cub *cub);
void	ft_putstr_fd(char *color, char *str, int fd);

int		loadtexture(t_cub *sl);
void	draw_each_y(t_cub *cub, double x, int wall, int color);
/*
    DATA
*/
//get_data.c
void	x_and_y_map(t_cub *cub);
void	get_texture(t_cub *cub);
//init_data.c
void	init_s_cub(t_cub *cub, t_parse *data);
void	init_mlx(t_cub *cub);
//print_data.c
void	print_cub(t_cub *cub);

/*
    MLX
*/
//angle_move.c
double	opposite_angle_back(double angle);
double	opposite_angle_right(double angle);
double	opposite_angle_left(double angle);
double	find_angle(double angle, int which);
double	correct_angle(double angle);
//display.c
void	display(t_cub *cub);
//event_key.c
int		key_press(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
int		event_key(t_cub *cub);
void	event_hook(t_cub *cub);
int		close_hook(t_cub *cub);
//grille.c
void	put_line_x(void *mlx_ptr, void *win_ptr, t_cub *cub);
void	put_line_y(void *mlx_ptr, void *win_ptr, t_cub *cub);
//inter.c
int		find_wall(t_cub *cub, double x, double y);
double	find_dist_x(int x, int x2, double angle);
t_coord	inter_co(t_cub *cub, double angle, int compteur);
double	inter(t_cub *cub, double angle);
t_coord	inter_ver(t_cub *cub, double angle);
//horizontal.c
double	getay(t_cub *cub, double angle);
t_coord	setcoor(double x, double y);
double	getya(double angle, double ya);
double	getcx(double angle, double ax, double xa);
double	getcx2(double angle, double cx, double xa);
t_coord	inter_hor(t_cub *cub, double angle);
//vertical.c
double	getxa2(double angle);
double	getya2(double angle);
t_coord	inter_ver(t_cub *cub, double angle);

//laser.c
void	dist_map(t_cub *cub);
void	draw_line_at_angle(t_cub *cub);
void	print_column(t_cub *cub, double lenght, double x, float coendx);
int		get_pixel_color(t_cub *cub, int x, int y);
//wall.c
void	print_wall(void *mlx_ptr, void *win_ptr, int x, int y);
void	get_wall(t_cub *cub);
/*
	MINIMAP
*/
//grid.c
void	put_line_x_minimap(void *mlx_ptr, void *win_ptr, t_cub *cub);
void	put_line_y_minimap(void *mlx_ptr, void *win_ptr, t_cub *cub);
//minimap.c
void	print_floor_minimap(void *mlx_ptr, void *win_ptr, int x, int y);
void	print_wall_minimap(void *mlx_ptr, void *win_ptr, int x, int y);
void	get_floor_minimap(t_cub *cub);
void	get_wall_minimap(t_cub *cub);
void	display_map_minimap(t_cub *cub);
//raycasting
void	mini_map(t_cub *cub);
/*
	MOVE
*/
//move.c
void	pov_move(t_cub *cub, double x);
void	x_y_move(t_cub *cub, double length, int which);
/*
    PARSING
*/
//CHECK_MAP
//check_car.c
int		good_car(char c);
int		have_position(char c);
int		check_nb_position(int position);
int		check_car(char *map);

//check_wall.c
int		check_high_wall(char *buf);
int		check_low_wall(char *buf);
int		check_side_wall(char *buf);
int		check_wall(char *buf);

//size_map.c
int		len_until_n(char *buf);
int		check_size_map(char *buf);
int		size_map(char *buf);

/*
    USEFUL
*/
//ft_split.c
char	**ft_split(char *s, char c);

//useful.c
int		ft_strlen(char *str);
int		ft_error(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*free_tab(char **tab);

#endif
