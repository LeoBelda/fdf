/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:01:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 21:15:36 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotcamy(t_env *e)
{
	e->matrices->camst.ry += 10.0;
	ft_putstr("eye:");
	print_vec4(e->matrices->cam->eye);
	ft_putendl("");
	ft_putstr("target:");
	print_vec4(e->matrices->cam->target);
	ft_putendl("");
	ft_putstr("up:");
	print_vec4(e->matrices->cam->up);
	ft_putendl("");
}

void	k_rotcamry(t_env *e)
{
	e->matrices->camst.ry -= 10.0;
	ft_putstr("eye:");
	print_vec4(e->matrices->cam->eye);
	ft_putendl("");
	ft_putstr("target:");
	print_vec4(e->matrices->cam->target);
	ft_putendl("");
	ft_putstr("up:");
	print_vec4(e->matrices->cam->up);
	ft_putendl("");
}

void	k_rotcamx(t_env *e)
{
	e->matrices->camst.rx += 10.0;
	ft_putstr("eye:");
	print_vec4(e->matrices->cam->eye);
	ft_putendl("");
	ft_putstr("target:");
	print_vec4(e->matrices->cam->target);
	ft_putendl("");
	ft_putstr("up:");
	print_vec4(e->matrices->cam->up);
	ft_putendl("");
}

void	k_rotcamrx(t_env *e)
{
	e->matrices->camst.rx -= 10.0;
	ft_putstr("eye:");
	print_vec4(e->matrices->cam->eye);
	ft_putendl("");
	ft_putstr("target:");
	print_vec4(e->matrices->cam->target);
	ft_putendl("");
	ft_putstr("up:");
	print_vec4(e->matrices->cam->up);
	ft_putendl("");
}
