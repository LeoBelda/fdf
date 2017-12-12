/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 01:07:19 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/12 01:09:22 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshader.h"

t_vec3pf	vec_normalize(t_vec3pf vec)
{
	float	len;

	len = vec_length(vec);
	return ((t_vec3pf){vec.x / len, vec.y / len, vec.z / len});
}
