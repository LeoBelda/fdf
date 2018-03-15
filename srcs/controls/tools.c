/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:31:22 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/15 12:09:49 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	send_release_signals(t_env *e, t_kfuncs *active)
{
	size_t	i;

	if (!active)
		return ;
	i = 0;
	while (active[i].f)
		active[i++].f(e, 0);
}

t_kbmodes	get_mode_sync(t_kbsync *kbsync, t_modes envmode)
{
	size_t	i;

	i = 0;
	while (kbsync[i].envmode)
	{
		if (kbsync[i].envmode == envmode)
			return (kbsync[i].kbmode);
		i++;
	}
	return (0);
}

void		switch_kbmode(t_env *e, t_kfuncs **preset, t_kbmodes mode)
{
	int	i;

	i = 0;
	send_release_signals(e, *preset);
	while (e->controls->presets[i].kbmode)
	{
		if (mode == e->controls->presets[i].kbmode)
		{
			*preset = e->controls->presets[i].preset;
			break ;
		}
		i++;
	}
}
