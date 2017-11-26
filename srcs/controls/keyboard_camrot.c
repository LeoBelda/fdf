/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:01:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 17:28:01 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotcamy(t_env *e, int flag)
{
	e->matrices->movement.ry = (flag ? 0.6 : 0.0);
}

void	k_rotcamry(t_env *e, int flag)
{
	e->matrices->movement.ry = (flag ? -0.6 : 0.0);
}

void	k_rotcamz(t_env *e, int flag)
{
	e->matrices->movement.rz = (flag ? 0.6 : 0.0);
}

void	k_rotcamrz(t_env *e, int flag)
{
	e->matrices->movement.rz = (flag ? -0.6 : 0.0);
}

void	k_rotcamx(t_env *e, int flag)
{
	e->matrices->movement.rx = (flag ? 0.6 : 0.0);
}

void	k_rotcamrx(t_env *e, int flag)
{
	e->matrices->movement.rx = (flag ? -0.6 : 0.0);
}
