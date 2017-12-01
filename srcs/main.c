/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:59:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/01 17:08:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage_exit(void)
{
	ft_putendl_fd("usage: ./fdf map.fdf", 2);
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
	if (argc != 2)
		usage_exit();
	fdf(argv[1]);
	return (0);
}
