/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:59:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/04 17:20:27 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage_exit(void)
{
	ft_putendl_fd("usage: ./fdf map.fdf [audiofile]", 2);
	exit(-1);
}

void	error_exit(char *msg)
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

int		main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		usage_exit();
	if (argc == 3)
		fdf(argv[1], argv[2]);
	else
		fdf(argv[1], NULL);
	return (0);
}
