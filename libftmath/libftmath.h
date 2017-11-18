/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:18:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 15:25:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <math.h>

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

t_vec4			vec4new(double x, double y, double z, double w);
t_mat4			mat4new(t_vec4 x, t_vec4 y, t_vec4 z, t_vec4 w);

t_vec4			cross_product(t_vec4 a, t_vec4 b);
double			vec4xvec4(t_vec4 a, t_vec4 b);
t_vec4			mat4xvec4(t_mat4 mat, t_vec4 vec);
t_mat4			mat4xmat4(t_mat4 a, t_mat4 b);

#endif
