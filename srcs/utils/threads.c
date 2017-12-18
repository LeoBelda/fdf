/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 07:06:06 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 09:40:45 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	send_threads(void *(*f)(), t_env *e)
{
	int			i;
	t_thrd		dt[NB_THRD];
	pthread_t	threads[NB_THRD];

	i = -1;
	while (++i < NB_THRD - 1)
	{
		dt[i] = (t_thrd){e, i};
		if (pthread_create(&(threads[i]), NULL, f,
			(void*)&(dt[i])))
			error_exit("");
	}
	dt[i] = (t_thrd){e, i};
	f((void*)&(dt[i]));
	i = -1;
	while (++i < NB_THRD - 1)
		if (pthread_join(threads[i], NULL))
			error_exit("");
}

void	send_threads_m(void *(*f)(), t_map *map)
{
	int			i;
	t_thrdm		dt[NB_THRD];
	pthread_t	threads[NB_THRD];

	i = -1;
	while (++i < NB_THRD - 1)
	{
		dt[i] = (t_thrdm){map, i};
		if (pthread_create(&(threads[i]), NULL, f,
			(void*)&(dt[i])))
			error_exit("");
	}
	dt[i] = (t_thrdm){map, i};
	f((void*)&(dt[i]));
	i = -1;
	while (++i < NB_THRD - 1)
		if (pthread_join(threads[i], NULL))
			error_exit("");
}
