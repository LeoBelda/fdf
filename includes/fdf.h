/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:53 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/16 23:45:16 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define XWIN 1920
# define YWIN 1080

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_list	*map;
}				t_env;

typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec3d;

enum
{
	K_ESC = 53,
	K_LEFT = 123,
	K_RIGHT,
	K_DOWN,
	K_UP
}				keycodes;

void			fdf(char *map);

t_list			*parse_map(char *map);

int				loop_hook(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				expose_hook(void *param);

void			usage_exit();
void			error_exit();

#endif
