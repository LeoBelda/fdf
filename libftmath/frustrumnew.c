/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frustrumnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:52 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/21 21:47:50 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_frustrum	frustrumnew(t_vec4 rlt, t_vec4 bfn)
{
	t_frustrum	fr;

	fr.r = rlt.x;
	fr.l = rlt.y;
	fr.t = rlt.z;
	fr.b = bfn.x;
	fr.f = bfn.y;
	fr.n = bfn.z;
	return (fr);
}
