/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_trs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:14:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/25 19:48:37 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trsx(t_env *e)
{
	e->matrices->initst.tx += 5.0;
}

void	k_trsrx(t_env *e)
{
	e->matrices->initst.tx -= 5.0;
}

void	k_trsy(t_env *e)
{
	e->matrices->initst.ty += 5.0;
}

void	k_trsry(t_env *e)
{
	e->matrices->initst.ty -= 5.0;
}

void	k_trsz(t_env *e)
{
	e->matrices->initst.tz += 5.0;
}

void	k_trsrz(t_env *e)
{
	e->matrices->initst.tz -= 5.0;
}
