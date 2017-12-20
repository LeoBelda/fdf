/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 21:42:41 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/24 23:18:55 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

void	rgbcpy(void *dst, t_rgb src)
{
	((unsigned char*)dst)[3] = src.a;
	((unsigned char*)dst)[2] = src.r;
	((unsigned char*)dst)[1] = src.g;
	((unsigned char*)dst)[0] = src.b;
}
