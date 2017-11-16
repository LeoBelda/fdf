/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:59:50 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/16 18:30:49 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage_exit()
{
	ft_putendl_fd("usage: ./fdf map.fdf", 2);
	exit(-1);
}

void	error_exit()
{
	perror("Error");
	exit(-1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	fdf();
	return (0);
}
