/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 23:04:30 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <math.h>
# include <unistd.h>

typedef struct	s_vec2r
{
	int	x;
	int	y;
}				t_vec2r;

typedef struct	s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec4;

typedef struct	s_mat4
{
	t_vec4	x;
	t_vec4	y;
	t_vec4	z;
	t_vec4	w;
}				t_mat4;

typedef struct	s_frustrum
{
	double	r;
	double	l;
	double	t;
	double	b;
	double	f;
	double	n;
}				t_frustrum;

t_vec2r			vec2rnewd(double x, double y);
t_vec2r			vec2rnewi(int x, int y);
t_vec4			vec4new(double x, double y, double z, double w);
t_mat4			mat4new(t_vec4 x, t_vec4 y, t_vec4 z, t_vec4 w);
t_mat4			idmat4new(void);
t_mat4			sclmat4new(double x, double y, double z);
t_mat4			trsmat4new(double x, double y, double z);
t_mat4			rotxmat4new(double x);
t_mat4			rotymat4new(double y);
t_mat4			rotzmat4new(double z);
t_mat4			orthomat4new(t_frustrum fr);
t_mat4			persmat4new(double fov, double f, double n);
t_frustrum		frustrumnew(double r, double t, double f, double n);

t_vec4			cross_product(t_vec4 a, t_vec4 b);
t_vec4			norm_vec4(t_vec4 vec);
double			vec4xvec4(t_vec4 a, t_vec4 b);
t_vec4			mat4xvec4(t_mat4 mat, t_vec4 vec);
t_mat4			mat4xmat4(t_mat4 a, t_mat4 b);

double			deg_rad(double deg);

void			print_double_fd(double nb, int fd);
void			print_double(double nb);
void			print_vec4_fd(t_vec4 vec, int fd);
void			print_vec4(t_vec4 vec);
void			print_vec2r_fd(t_vec2r vec, int fd);
void			print_vec2r(t_vec2r vec);
void			print_mat4_fd(t_mat4 vec, int fd);
void			print_mat4(t_mat4 vec);

#endif
