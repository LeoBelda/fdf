/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:59:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/11 04:58:53 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			usage_exit(void)
{
	ft_putendl_fd("usage: ./fdf map.fdf [audiofile] \
[-default | -loud | -quiet]", 2);
	exit(-1);
}

void			error_exit(char *msg)
{
	if (!*msg)
		perror("Error");
	else
	{
		ft_putstr("Error: ");
		ft_putendl(msg);
	}
	exit(-1);
}

static t_lmodes	arg_is_mode(char *arg)
{
	if (!(ft_strcmp(arg, "-default")))
		return (L_DEFAULT);
	else if (!(ft_strcmp(arg, "-loud")))
		return (L_LOUD);
	else if (!(ft_strcmp(arg, "-quiet")))
		return (L_QUIET);
	else
		return (0);
}

int				main(int argc, char **argv)
{
	t_lmodes	launchmode;

	if (argc < 2 || argc > 4)
		usage_exit();
	if (argc == 3)
		(launchmode = arg_is_mode(argv[2])) ?
			fdf(argv[1], NULL, launchmode) : fdf(argv[1], argv[2], 1);
	else if (argc == 4)
		(launchmode = arg_is_mode(argv[3])) ?
			fdf(argv[1], argv[2], launchmode) : usage_exit();
	else
		fdf(argv[1], NULL, 1);
	return (0);
}
