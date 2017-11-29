/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/29 23:44:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "libftmath.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

# define XWIN 2560
# define YWIN 1440
# define X_WIN 2560.0
# define Y_WIN 1440.0

# define C_BLA 0x00000000
# define C_BLU 0x000000ff
# define C_GRE 0x0000ff00
# define C_RED 0x00ff0000
# define C_WHI 0x00ffffff

# define C_GOLD_PALE (t_rgb) {0, 238, 232, 170}
# define C_ORANGE_DARK (t_rgb) {0, 255, 160, 0}

# define C_GREEN_DARK (t_rgb) {0, 0, 100, 0}
# define C_GREEN_SEA_MED (t_rgb) {0, 60, 179, 113}
# define C_CYAN_DARK (t_rgb) {0, 0, 139, 139}
# define C_BLUE_MIDNIGHT (t_rgb) {0, 25, 25, 112}
# define C_BLUE_BLACK (t_rgb) {0, 12, 12, 70}
# define C_BLUE_NAVY (t_rgb) {0, 0, 0, 128}
# define C_INDIGO (t_rgb) {0, 75, 0, 130}

enum			e_keycodes
{
	K_A = 0,
	K_S,
	K_D,
	K_C = 8,
	K_W = 13,
	K_P = 35,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
};

typedef enum	e_modes
{
	M_SKY,
	M_GRD
}				t_modes;

typedef struct	s_kfuncs
{
	void	(*f)();
	int		keycode;
}				t_kfuncs;

typedef struct	s_controls
{
	t_kfuncs	*grd;
	t_kfuncs	*sky;
}				t_controls;

typedef struct	s_vec2c
{
	int		x;
	int		y;
	int		color;
}				t_vec2c;

typedef struct	s_colorset
{
	int			text;
	long int	background;
	int			bottom;
	int			top;
}				t_colorset;

typedef struct	s_colors
{
	t_colorset	active;
	t_colorset	from;
	t_colorset	target;
	t_colorset	*stock;
	size_t		progress;
	size_t		stock_size;
}				t_colors;

typedef struct	s_modmat
{
	double	rx;
	double	ry;
	double	rz;
	double	tx;
	double	ty;
	double	tz;
	double	s;
}				t_modmat;

typedef struct	s_mat4set
{
	t_mat4	active;
	t_mat4	from;
	t_mat4	target;
	t_mat4	*stock;
	size_t	progress;
	size_t	stock_size;
	int		switching;
}				t_mat4set;

typedef struct	s_map
{
	t_list	*vertices_list;
	t_vec4	*vertices;
	t_vec3	*proj;
	t_vec2c	*draw;
	char	*clip;
	size_t	nb_col;
	size_t	nb_line;
	size_t	nb_vtx;
	t_vec4	mid_mod;
	t_vec4	mid_point;
	double	mid_height;
	int		min_z;
	int		max_z;
}				t_map;

typedef struct	s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_matrices
{
	t_modmat	initst;
	t_modmat	movement;
	t_mat4set	*projs;
	t_mat4set	*views;
	t_vec4		eye_pos;
	t_mat4		model_mat;
	t_mat4		f_mat;
}				t_matrices;

typedef struct	s_overlay
{
	char	*fps;
}				t_overlay;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_matrices	*matrices;
	t_colors	*colors;
	t_controls	*controls;
	t_overlay	*overlay;
	t_modes		mode;
}				t_env;

void			fdf(char *file);

void			parse_map(t_map *map, char *file);
void			init_geometry(t_matrices *matrices, t_map *map);
void			init_colors(t_colors *colors);
void			init_controls(t_controls *controls);
void			init_overlay(t_overlay *overlay);
t_mat4			get_view_mat(t_vec4 eye, t_vec4 target, t_vec4 up);

int				draw(t_env *e);
void			set_matrices(t_matrices *matrices);
void			manage_text_overlay(t_env *e);

t_vec4			get_eye_pos(t_mat4 active);

void			set_color(t_colors *color);

void			vertices_to_proj(t_map *map, t_mat4 f_mat);
void			proj_to_draw(t_map *map, t_colorset active);
void			draw_to_img(t_map *map, int *addr);

int				get_color(int min_z, int max_z, int z,
												t_colorset active);

void			draw_line(t_vec2c a, t_vec2c b, int *addr);
void			draw_clipline(t_vec2c a, t_vec2c b, int *addr);
int				pix_clip(t_vec2c coord);


int				expose_hook(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				key_press_hook(int keycode, t_env *e);
int				key_release_hook(int keycode, t_env *e);

void			k_exit(t_env *e);
void			k_chpov(t_env *e, int flag);
void			k_chcolor(t_env *e, int flag);
void			k_trsx(t_env *e, int flag);
void			k_trsrx(t_env *e, int flag);
void			k_trsy(t_env *e, int flag);
void			k_trsry(t_env *e, int flag);
void			k_trsz(t_env *e, int flag);
void			k_trsrz(t_env *e, int flag);
void			k_rotx(t_env *e, int flag);
void			k_rotrx(t_env *e, int flag);
void			k_roty(t_env *e, int flag);
void			k_rotry(t_env *e, int flag);
void			k_trscamx(t_env *e, int flag);
void			k_trscamrx(t_env *e, int flag);
void			k_trscamy(t_env *e, int flag);
void			k_trscamry(t_env *e, int flag);
void			k_trscamz(t_env *e, int flag);
void			k_trscamrz(t_env *e, int flag);
void			k_rotcamy(t_env *e, int flag);
void			k_rotcamry(t_env *e, int flag);
void			k_rotcamx(t_env *e, int flag);
void			k_rotcamrx(t_env *e, int flag);
void			k_rotcamz(t_env *e, int flag);
void			k_rotcamrz(t_env *e, int flag);

void			usage_exit();
void			error_exit(char *msg);

void			print_parsed_map(t_list *map);
void			print_array_map(t_vec4 *array, size_t size);
void			print_draw_coords(t_list *draw);

#endif
