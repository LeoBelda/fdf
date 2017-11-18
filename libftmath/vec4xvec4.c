/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4xvec4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:29:54 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/18 13:48:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

double	vec4xvec4(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y);
}
