/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kbcamtrsy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:30:44 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/07 18:41:54 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_trscamy(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? 20 : 0.0);
}

void	k_trscamry(t_env *e, int flag)
{
	e->matrices->movement.ty = (flag ? -20 : 0.0);
}
