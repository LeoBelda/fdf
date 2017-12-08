/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colorfuncs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:17:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/08 16:09:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_cfuncs(t_colors *colors)
{
	if (!(colors->cfuncs = ft_memalloc(sizeof(t_cfuncs) * 6)))
		error_exit("");
	(colors->cfuncs)[0] = (t_cfuncs) { switch_colorset, C_STOCK };
	(colors->cfuncs)[1] = (t_cfuncs) { program_disco, C_DISCO };
	(colors->cfuncs)[2] = (t_cfuncs) { program_hyper, C_HYPER };
	(colors->cfuncs)[3] = (t_cfuncs) { program_strobo, C_STROBO };
	(colors->cfuncs)[4] = (t_cfuncs) { program_glowing, C_GLOWING };
	(colors->cfuncs)[5] = (t_cfuncs) { NULL, 0 };
}

void	set_bfuncs(t_colors *colors)
{
	if (!(colors->bfuncs = ft_memalloc(sizeof(t_bfuncs) * 3)))
		error_exit("");
	(colors->bfuncs)[0] = (t_bfuncs) { plain_background, B_DEFAULT };
	(colors->bfuncs)[1] = (t_bfuncs) { no_background, B_TRIPPY };
	(colors->bfuncs)[2] = (t_bfuncs) { NULL, 0 };
}
