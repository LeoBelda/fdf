/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:15:05 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/22 18:45:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotx(t_env *e)
{
	e->matrices->initst.rx -= 5.0;
}

void	k_rotrx(t_env *e)
{
	e->matrices->initst.rx += 5.0;
}

void	k_roty(t_env *e)
{
	e->matrices->initst.ry -= 5.0;
}

void	k_rotry(t_env *e)
{
	e->matrices->initst.ry += 5.0;
}
