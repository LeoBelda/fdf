/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camtrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:56:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 20:55:31 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e)
{
	e->matrices->camst.tx -= 10.0;
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

void	k_trscamrx(t_env *e)
{
	e->matrices->camst.tx += 10.0;
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

void	k_trscamy(t_env *e)
{
	e->matrices->camst.ty -= 10.0;
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

void	k_trscamry(t_env *e)
{
	e->matrices->camst.ty += 10.0;
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
