/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frustrumnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:44:52 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/23 22:56:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_frustrum	frustrumnew(double r, double t, double f, double n)
{
	t_frustrum	fr;

	fr.r = r;
	fr.t = t;
	fr.f = f;
	fr.n = n;
	return (fr);
}
