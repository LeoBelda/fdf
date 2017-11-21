/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 19:56:46 by lbelda           ###   ########.fr       */
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

# define XWIN 1920
# define YWIN 1080

# define C_CYAN 0x28c1da

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
	t_list	*to_draw;
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
	t_modmat	*initst;
	t_cam		*cam;
	t_mat4		f_mat;
}				t_matrices;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_matrices	*matrices;
}				t_env;

enum
{
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
}				keycodes;

void			fdf(char *map);

void			parse_map(t_map *parsed_map, char *map);

void			set_matrices(t_matrices *matrices);

void			draw_line(t_vec4 a, t_vec4 b, t_img imginf);

void			draw(t_env *e);

int				loop_hook(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				expose_hook(void *param);

void			usage_exit();
void			error_exit(char *msg);

void			print_parsed_map(t_list *map);

#endif
