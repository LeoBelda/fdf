/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_camtrsz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:31:39 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/19 18:19:33 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? 16.0 : 0.0);
}

void	k_trscamrz(t_env *e, int flag)
{
	e->matrices->movement.tz = (flag ? -16.0 : 0.0);
}
