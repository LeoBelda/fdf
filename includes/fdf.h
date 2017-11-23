/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 20:29:49 by lbelda           ###   ########.fr       */
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
# include <time.h>

# define XWIN 1920
# define YWIN 1080
# define X_WIN 1920.0
# define Y_WIN 1080.0

# define C_CYAN 0x28c1da
# define C_WHIT 0xffffff

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
	t_kfuncs	*modelmode;
	t_kfuncs	*cammode;
}				t_controls;

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
	t_list	*vertices;
	t_list	*proj;
	t_list	*draw;
	size_t	nb_col;
	size_t	nb_line;
}				t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_matrices
{
	t_modmat	initst;
	t_modmat	camst;
	t_cam		*cam;
	t_mat4		ortho_proj;
	t_mat4		pers_proj;
	t_mat4		eye_mat;
	t_mat4		f_mat;
}				t_matrices;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_matrices	*matrices;
	t_controls	*controls;
}				t_env;

void			fdf(char *map);

void			parse_map(t_map *parsed_map, char *map);

void			set_matrices(t_matrices *matrices);
void			set_controls(t_controls *controls);
t_mat4			get_view_mat(t_cam *cam, t_modmat camst);

void			draw_line(t_vec2r a, t_vec2r b, t_img imginf);

void			draw(t_env *e);

int				loop_hook(void *param);
int				expose_hook(void *param);

int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);

void			k_exit(t_env *e);
void			k_chmode(t_env *e);
void			k_trsleft(t_env *e);
void			k_trsright(t_env *e);
void			k_trsup(t_env *e);
void			k_trsdown(t_env *e);
void			k_rotx(t_env *e);
void			k_rotrx(t_env *e);
void			k_roty(t_env *e);
void			k_rotry(t_env *e);
void			k_trscamx(t_env *e);
void			k_trscamrx(t_env *e);
void			k_trscamy(t_env *e);
void			k_trscamry(t_env *e);
void			k_rotcamy(t_env *e);
void			k_rotcamry(t_env *e);
void			k_rotcamx(t_env *e);
void			k_rotcamrx(t_env *e);

void			usage_exit();
void			error_exit(char *msg);

void			print_parsed_map(t_list *map);
void			print_draw_coords(t_list *draw);

#endif
