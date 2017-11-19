/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:56:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/19 18:44:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*line_to_vertices(char *line, size_t y_pos, size_t *count_col)
{
	int		j;
	char	**splitted_line;
	t_list	*vertices_line;
	t_list	*elem;
	t_vec4	new;

	j = -1;
	vertices_line = NULL;
	if (!(splitted_line = ft_strsplit(line, ' ')))
		error_exit("");
	while (splitted_line[++j])
	{
		new.x = (double)j * 10.0;
		new.y = (double)y_pos * 10.0;
		new.z = (double)ft_atoi(splitted_line[j]);
		new.w = 1.0;
		if (!(elem = ft_lstnew(&new, sizeof(t_vec4))))
			error_exit("");
		ft_lstradd(&vertices_line, elem);
	}
	if (!*count_col)
		*count_col = j;
	if (j < 2 || (size_t)j != *count_col)
		error_exit("Invalid map - irregular lines");
	return (vertices_line);
}

static void		map_to_list(int fd, t_map *parsed_map)
{
	int		ret;
	size_t	i;
	char	*line;
	t_list	*new_line;

	i = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1
			|| !(new_line = line_to_vertices(line, i, &(parsed_map->nb_col))))
			error_exit("");
		ft_lstradd(&(parsed_map->vertices), new_line);
		free(line);
		i++;
	}
	if ((parsed_map->nb_line = i) < 2)
		error_exit("Invalid map - not enough lines");
}

void			parse_map(t_map **parsed_map, char *map)
{
	int		fd;

	if (!(*parsed_map = ft_memalloc(sizeof(t_env))))
		error_exit("");
	if ((fd = open(map, O_RDONLY)) == -1)
		error_exit("");
	map_to_list(fd, *parsed_map);
	if (close(fd) == -1)
		error_exit("");
}
