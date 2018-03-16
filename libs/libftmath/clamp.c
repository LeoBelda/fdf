/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:16:35 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/16 12:18:35 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

double	clamp(double val, double min, double max)
{
	val = fmin(val, max);
	val = fmax(val, min);
	return (val);
}
