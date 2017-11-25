/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camtrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:56:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 00:34:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e)
{
	t_vec4	new;

	new = 
			mat4xvec4(rotymat4new(e->matrices->camst.ry),
			mat4xvec4(rotzmat4new(e->matrices->camst.rz),
				vec4new(1.0, 0.0, 0.0, 0.0)));
	print_vec4(new);
	ft_putendl("");
	e->matrices->camst.tx -= new.x * 10.0;
	e->matrices->camst.ty -= new.y * 10.0;
	e->matrices->camst.tz -= new.z * 10.0;
}

void	k_trscamrx(t_env *e)
{
	t_vec4	new;

	new =
			mat4xvec4(rotymat4new(e->matrices->camst.ry),
			mat4xvec4(rotzmat4new(e->matrices->camst.rz),
				vec4new(1.0, 0.0, 0.0, 0.0)));
	print_vec4(new);
	ft_putendl("");
	e->matrices->camst.tx += new.x * 10.0;
	e->matrices->camst.ty += new.y * 10.0;
	e->matrices->camst.tz += new.z * 10.0;
}

void	k_trscamy(t_env *e)
{
	t_vec4	new;

	new = mat4xvec4(rotxmat4new(e->matrices->camst.rx),
			mat4xvec4(rotymat4new(e->matrices->camst.ry),
			mat4xvec4(rotzmat4new(e->matrices->camst.rz),
				vec4new(0.0, 1.0, 0.0, 0.0))));
	e->matrices->camst.tx += new.x;
	e->matrices->camst.ty += new.y;
	e->matrices->camst.tz += new.z;
}

void	k_trscamry(t_env *e)
{
	t_vec4	new;

	new = mat4xvec4(rotxmat4new(e->matrices->camst.rx),
			mat4xvec4(rotymat4new(e->matrices->camst.ry),
			mat4xvec4(rotzmat4new(e->matrices->camst.rz),
				vec4new(0.0, 1.0, 0.0, 0.0))));
	e->matrices->camst.tx -= new.x;
	e->matrices->camst.ty -= new.y;
	e->matrices->camst.tz -= new.z;
}

void	k_trscamz(t_env *e)
{
	t_vec4	new;

	new = 
			mat4xvec4(rotymat4new(deg_rad(e->matrices->camst.ry)),
		mat4xvec4(rotxmat4new(deg_rad(e->matrices->camst.rx)),
				vec4new(0.0, 0.0, 1.0, 0.0)));
	print_vec4(new);
	ft_putendl("");
	e->matrices->camst.tx -= new.x * 10.0;
	e->matrices->camst.ty -= new.y * 10.0;
	e->matrices->camst.tz -= new.z * 10.0;
}

void	k_trscamrz(t_env *e)
{
	t_vec4	new;

	new = 
			mat4xvec4(rotymat4new(deg_rad(e->matrices->camst.ry)),
			mat4xvec4(rotxmat4new(deg_rad(e->matrices->camst.rx)),
				vec4new(0.0, 0.0, 1.0, 0.0)));
	print_vec4(new);
	ft_putendl("");
	e->matrices->camst.tx += new.x * 10.0;
	e->matrices->camst.ty += new.y * 10.0;
	e->matrices->camst.tz += new.z * 10.0;
}
