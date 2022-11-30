/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:29:09 by bvarlamo          #+#    #+#             */
/*   Updated: 2022/09/30 15:18:07 by hrothery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# ifdef __linux__

#  include <X11/X.h>
#  include <X11/keysym.h>
#  include "../mlx/mlx.h"
# endif

# ifdef __APPLE__

#  include "../minilibx_opengl/mlx.h"
# endif

# include "keycodes.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../Libft/libft.h"

# define SCREENWIDTH 800
# define SCREENHEIGHT 600
# define TURN 0.03
# define STEP_INTERVAL 0.1
# define TAB 4

# define FLOOR 0
# define CEILING 1
# define NORTH 2
# define SOUTH 3
# define WEST 1
# define EAST 0

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_coordinates
{
	double	x;
	double	y;
}	t_coordinates;

typedef struct s_icoordinates
{
	int	x;
	int	y;
}	t_icoordinates;

typedef struct s_values
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img;
	int					bits;
	int					line;
	int					end;
	t_coordinates		pos;
	t_coordinates		dir;
	t_coordinates		plane;
	double				camerax;
	t_coordinates		ray;
	t_icoordinates		move;
	t_coordinates		side;
	t_coordinates		delta;
	double				perpwalldist;
	t_icoordinates		step;
	int					hit;
	int					p_side;
	int					lineheight;
	int					h;
	int					drawstart;
	int					drawend;
	unsigned long int	color;
	double				olddirx;
	double				oldplanex;
	int					texnum;
	double				wallx;
	t_icoordinates		tex;
	char				*pattern[4];
	void				*t_tex[4];
	void				*itex[4];
	int					width[4];
	int					height[4];
	int					tbits[4];
	int					tline[4];
	int					tend[4];
	double				t_step;
	double				texpos;
	char				**map;
	int					nr_rows;
	int					nr_columns;
	int					nswefc[7];
	int					nr_start_pos;
	int					floor;
	int					ceiling;
	int					w;
	int					s;
	int					a;
	int					d;
	int					left;
	int					right;
	int					old_x;

}	t_values;

//color_utils.c
int		get_color(char *line, char **tmp, t_values *vars, int i);

//free.c
bool	free_map(t_values *vars);
bool	free_paths(t_values *vars);
bool	color_err(char **tmp);
bool	invalid_data(char **tmp);

//helpers.c
void	drawwalls(int x, t_values *vars);
void	draw_mini(t_values *vars, int x, int y, unsigned int color);
void	draw_player(t_values *vars);
void	mini_map(t_values *vars);
int		test(t_values *vars);

//init_pos.c
void	init_pos_and_dir(char c, t_values *vars, int i, int j);

//keys.c
int		turnleft(t_values *vars);
int		turnright(t_values *vars);
int		stepright(t_values *vars);
int		stepleft(t_values *vars);
int		keys(int key, t_values *vars);

//main_helpers.c
int		xclose(t_values *vars);
void	raycasting(t_values *vars);
int		init_mlx(t_values *vars);
bool	check_file(int argc, char *argv);
bool	init_to_null(t_values *vars);

//main.c, main_linux.c
bool	free_everything(t_values *vars);
void	draw_fc(t_values *vars);

//parser_utils0.c
bool	init_value(char *line, t_values *vars);
void	write_nswefc(t_values *vars, char *line);
char	first_char(char *line);
void	replace_newline(char *line);

//parser_utils1.c
bool	check_character(char c, t_values *vars, int i, int j);
bool	empty_lines(t_values *vars);
bool	check_map(t_values *vars);
bool	init_to_null(t_values *vars);
void	sort_data(t_values *vars, char *line, int *count, bool *ret);

//parser_utils2.c
bool	save_tex(char **tmp, t_values *vars, int i);
bool	textures(t_values *vars);
int		count_commas(char *s);
char	*replace_tabs(char *line);

//parser.c
int		parse_input(char *argv, t_values *vars);

//raycastinghelpers.c
void	raycast1(t_values *vars);
void	raycast2(t_values *vars);
void	raycast3(t_values *vars);
void	raycast4(t_values *vars);
void	raycast5(t_values *vars);

//space_check.c
bool	left_border(int i, int j, t_values *vars);
bool	right_border(int i, int j, t_values *vars);
bool	top_border(int i, int j, t_values *vars);
bool	bottom_border(int i, int j, t_values *vars);

//stepforward.c
void	stepforward(t_values *vars);
void	stepbackward(t_values *vars);

//wall_check.c
bool	left_wall(int i, int j, t_values *vars);
bool	right_wall(int i, int j, t_values *vars);
bool	top_wall(int i, int j, t_values *vars);
bool	bottom_wall(int i, int j, t_values *vars);

#endif