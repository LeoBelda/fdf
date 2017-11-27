/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:56:48 by lbelda            #+#    #+#             */
/*   Updated: 2017/11/27 18:45:27 by lbelda           ###   ########.fr       */
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
		new.z = (double)ft_atoi(splitted_line[j]) * 1.0;
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

static void		map_to_list(int fd, t_map *map)
{
	int		ret;
	size_t	i;
	char	*line;
	t_list	*new_line;

	i = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1
			|| !(new_line = line_to_vertices(line, i, &(map->nb_col))))
			error_exit("");
		ft_lstradd(&(map->vertices_list), new_line);
		free(line);
		i++;
	}
	if ((map->nb_line = i) < 2)
		error_exit("Invalid map - not enough lines");
}

static void		define_attributes(t_map *map)
{
	size_t	i;

	i = 0;
	map->nb_vtx = map->nb_line * map->nb_col;
	map->min_z = (map->vertices)[0].z;
	map->max_z = (map->vertices)[0].z;
	while (i < map->nb_vtx)
	{
		if ((map->vertices)[i].z > map->max_z)
			map->max_z = (map->vertices)[i].z;
		if ((map->vertices)[i].z < map->min_z)
			map->min_z = (map->vertices)[i].z;
		i++;
	}
	map->mid_top = vec4new((map->vertices[0].x +
							map->vertices[map->nb_vtx - 1].x) / 2,
							(map->vertices[0].y +
						 	map->vertices[map->nb_vtx - 1].y) / 2,
						0.0, 1.0);
}

void			parse_map(t_map *map, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("");
	map_to_list(fd, map);
	map->vertices = ft_lst_to_array(map->vertices_list);
	define_attributes(map);
	if (!(map->proj = ft_memalloc(sizeof(t_vec4) * map->nb_vtx)))
		error_exit("");
	if (!(map->draw = ft_memalloc(sizeof(t_vec2c) * map->nb_vtx)))
		error_exit("");
	//ft_lstdel(tmp_lst,,);
	if (close(fd) == -1)
		error_exit("");
}
