/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps3_camrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 02:11:39 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/20 03:04:22 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ps3_camrotz(t_env *e, int flag)
{
	e->matrices->movement.rz = 1.4 * flag;
}

void	ps3_camrotx(t_env *e, int value)
{
	e->matrices->movement.rx = 1.3 * value / 32767;
}

void	ps3_camroty(t_env *e, int value)
{
	e->matrices->movement.ry = 0.7 * value / 32767;
}

void	ps3_reset_camrot(t_env *e)
{
	e->matrices->movement.rz = 0;
	e->matrices->movement.rx = 0;
}
