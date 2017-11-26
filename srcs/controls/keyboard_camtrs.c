/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camtrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:56:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/26 17:43:01 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? 1.5 : 0.0);
}

void	k_trscamrx(t_env *e, int flag)
{
	e->matrices->movement.tx = (flag ? -1.5 : 0.0);
}

void	k_trscamy(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? 0.2 : 0.0);
}

void	k_trscamry(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? -0.2 : 0.0);
}

void	k_trscamz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? 1.0 : 0.0);
}

void	k_trscamrz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? -1.0 : 0.0);
}
