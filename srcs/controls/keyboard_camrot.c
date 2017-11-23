/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_camrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:01:55 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 22:41:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotcamy(t_env *e)
{
	e->matrices->camst.ry += 10.0;
}

void	k_rotcamry(t_env *e)
{
	e->matrices->camst.ry -= 10.0;
}

void	k_rotcamx(t_env *e)
{
	e->matrices->camst.rx += 10.0;
}

void	k_rotcamrx(t_env *e)
{
	e->matrices->camst.rx -= 10.0;
}
