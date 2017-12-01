/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_camrotz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:27:44 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:28:07 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotcamz(t_env *e, int flag)
{
	e->matrices->movement.rz = (flag ? 1.0 : 0.0);
}

void	k_rotcamrz(t_env *e, int flag)
{
	e->matrices->movement.rz = (flag ? -1.0 : 0.0);
}
