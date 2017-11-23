/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camtrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:56:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 05:19:57 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamx(t_env *e)
{
	e->matrices->camst.tx += 10.0;
}

void	k_trscamrx(t_env *e)
{
	e->matrices->camst.tx -= 10.0;
}

void	k_trscamy(t_env *e)
{
	e->matrices->camst.ty += 10.0;
}

void	k_trscamry(t_env *e)
{
	e->matrices->camst.ty -= 10.0;
}
