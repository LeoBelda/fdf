/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:56:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/17 00:03:04 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*parse_map(char *map)
{
	t_list	*map_str;
	t_list	*parsed_map;
	char	*line;
	int		ret;
	int		fd;

	map_str = NULL;
	if ((fd = open(map, O_RDONLY)) == -1)
		error_exit();
	while ((ret = get_next_line(fd, &line)))
	{
		ft_lstradd(&map_str, ft_lstnew(line, ft_strlen(line)));
		free(line);
	}
	if (close(fd) == -1)
		error_exit();
	parsed_map = 0;
	return (parsed_map);
}
