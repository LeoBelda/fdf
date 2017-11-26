/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 20:33:45 by lbelda           ###   ########.fr       */
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

# define XWIN 1920
# define YWIN 1080
# define X_WIN 1920.0
# define Y_WIN 1080.0

# define C_CYA 0x28c1da
# define C_BLA (t_rgb) {0, 0, 0, 0}
# define C_BLU (t_rgb) {0, 0, 0, 200}
# define C_RED (t_rgb) {0, 255, 0, 0}
# define C_GRE (t_rgb) {0, 0, 255, 0}
# define C_BRO (t_rgb) {0, 153, 76, 0}
# define C_WHI (t_rgb) {0, 255, 255, 255}

enum
{
	K_A = 0,
	K_S,
	K_D,
	K_W = 13,
	K_P = 35,
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
}				keycodes;

typedef struct	s_kfuncs
{
	void	(*f)();
	int		keycode;
}				t_kfuncs;

typedef struct	s_controls
{
	int			mode;
	t_kfuncs	*camera;
}				t_controls;

typedef struct	s_vec2c
{
	int		x;
	int		y;
	t_rgb	color;
}				t_vec2c;

typedef struct	s_colors
{
	t_rgb	background;
	t_rgb	text;
	t_rgb	bottom;
	t_rgb	top;
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

typedef struct	s_cam
{
	t_vec4	eye;
	t_vec4	target;
	t_vec4	up;
}				t_cam;

typedef struct	s_map
{
	t_list	*vertices_list;
	t_vec4	*vertices;
	t_vec3	*proj;
	t_vec2c	*draw;
	size_t	nb_col;
	size_t	nb_line;
	size_t	nb_vertices;
	double	min_z;
	double	max_z;
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
	t_cam		*cam;
	t_mat4		ortho_mat;
	t_mat4		pers_mat;
	t_mat4		view_mat;
	t_mat4		model_mat;
	t_mat4		f_mat;
}				t_matrices;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_matrices	*matrices;
	t_colors	*colors;
	t_controls	*controls;
}				t_env;

void			fdf(char *file);

void			parse_map(t_map *map, char *file);

void			draw(t_env *e);
void			init_env(t_env *e);
void			set_matrices(t_matrices *matrices);
void			set_controls(t_controls *controls);
void			manage_text_overlay(t_env *e);

void			draw_line(t_vec2c a, t_vec2c b, t_img imginf);
void			draw_clipline(t_vec2c a, t_vec2c b, t_img imginf);
int				pix_clip(t_vec2c coord);

int				loop_hook(void *param);
int				expose_hook(void *param);

int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				key_press_hook(int keycode, void *param);
int				key_release_hook(int keycode, void *param);

void			k_exit(t_env *e);
void			k_chmode(t_env *e);
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
