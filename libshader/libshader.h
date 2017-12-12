/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/12 05:36:26 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHADER_H
# define LIBSHADER_H

# include <math.h>
# include <unistd.h>

# ifndef T_VEC2R
#  define T_VEC2R

typedef struct	s_vec2r
{
	int	x;
	int	y;
}				t_vec2r;

# endif

typedef struct	s_vec2f
{
	float	x;
	float	y;
}				t_vec2f;

typedef struct	s_vec4r
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_vec4r;

typedef struct	s_vec4pf
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_vec4pf;

typedef struct	s_vec3pf
{
	float	x;
	float	y;
	float	z;
}				t_vec3pf;

typedef struct	s_vec4cf
{
	float	b;
	float	g;
	float	r;
	float	a;
}				t_vec4cf;

typedef union	u_vec4c
{
	int		val;
	t_vec4r	argb;
}				t_vec4c;

typedef union	s_vec4f
{
	t_vec4pf	pos;
	t_vec4cf	col;
}				t_vec4f;

int			vec4cf_to_rgb(t_vec4cf color);
t_vec2f		pos_to_vec2f(t_vec2r pos, t_vec2f res);

float		vec_length(t_vec3pf vec);
t_vec3pf	vec_normalize(t_vec3pf vec);
t_vec3pf	scal_vec(t_vec3pf vec, float scl);
t_vec3pf	add_vec(t_vec3pf v1, t_vec3pf v2);
t_vec3pf	sub_vec(t_vec3pf v1, t_vec3pf v2);

float		step(float edge, float x);

#endif
