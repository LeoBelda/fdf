/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_vec4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:14:25 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 17:24:09 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

t_vec4	norm_vec4(t_vec4 vec)
{
	t_vec4	norm;
	double	lenght;

	lenght = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	norm.x = vec.x / lenght;
	norm.y = vec.y / lenght;
	norm.z = vec.z / lenght;
	norm.w = vec.w / lenght;
	return (norm);
}
