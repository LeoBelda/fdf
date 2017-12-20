/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_camrotx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:26:42 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/19 18:18:56 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotcamx(t_env *e, int flag)
{
	e->matrices->movement.rx = (flag ? 1.3 : 0.0);
}

void	k_rotcamrx(t_env *e, int flag)
{
	e->matrices->movement.rx = (flag ? -1.3 : 0.0);
}
