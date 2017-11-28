/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camtrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:56:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/28 15:40:08 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? 10 : 0.0);
}

void	k_trscamrx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? -10 : 0.0);
}

void	k_trscamy(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? 10 : 0.0);
}

void	k_trscamry(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? -10 : 0.0);
}

void	k_trscamz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? 1.7 : 0.0);
}

void	k_trscamrz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? -1.7 : 0.0);
}
