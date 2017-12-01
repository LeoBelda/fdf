/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_camroty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:27:25 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:27:35 by lbelda           ###   ########.fr       */
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
