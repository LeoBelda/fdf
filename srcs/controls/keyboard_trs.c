/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_trs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:14:20 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/22 18:45:05 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trsleft(t_env *e)
{
	e->matrices->initst.tx -= 5.0;
}

void	k_trsright(t_env *e)
{
	e->matrices->initst.tx += 5.0;
}

void	k_trsup(t_env *e)
{
	e->matrices->initst.ty -= 5.0;
}

void	k_trsdown(t_env *e)
{
	e->matrices->initst.ty += 5.0;
}
