/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:56:48 by lbelda            #+#    #+#             */
/*   Updated: 2018/01/29 12:15:19 by lbelda           ###   ########.fr       */
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
		new = (t_vec4) { (double)j * X_SCALE, (double)y_pos * Z_SCALE,
						(double)ft_atoi(splitted_line[j]) * 1.0, 1.0 };
		if (!(elem = ft_lstnew(&new, sizeof(t_vec4))))
			error_exit("");
		ft_lstradd(&vertices_line, elem);
	}
	ft_tabdel(&splitted_line);
	if (!*count_col)
		*count_col = j;
	if (j < 1 || (size_t)j != *count_col)
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
			|| !(new_line = line_to_vertices(line, i, &(map->nb_col_glb))))
			error_exit("");
		ft_lstradd(&(map->vertices_list), new_line);
		free(line);
		i++;
	}
	if ((map->nb_line_glb = i) < 1)
		error_exit("Invalid map - not enough lines");
}

static void		define_attributes(t_map *map)
{
	size_t	i;

	i = 0;
	map->nb_vtx_glb = map->nb_line_glb * map->nb_col_glb;
	map->min_z = (int)(map->vertices_glb)[0].z;
	map->max_z = (int)(map->vertices_glb)[0].z;
	while (i < map->nb_vtx_glb)
	{
		if ((int)(map->vertices_glb)[i].z > map->max_z)
			map->max_z = (int)(map->vertices_glb)[i].z;
		if ((int)(map->vertices_glb)[i].z < map->min_z)
			map->min_z = (int)(map->vertices_glb)[i].z;
		i++;
	}
	map->mid_mod = vec4new((map->vertices_glb[map->nb_vtx_glb - 1].x) / 2,
							(map->vertices_glb[map->nb_vtx_glb - 1].y) / 2,
						(double)(map->max_z + map->min_z) / 2.0, 1.0);
	map->mid_height = (double)-(map->max_z + map->min_z / 2.0);
	map->mid_point = mat4xvec4(trsmat4new(0.0, map->mid_height, 50.0),
						map->mid_mod);
	map->az_targut = 0;
	map->nb_vtx = SIDE * SIDE;
	map->nb_col = SIDE;
	map->nb_line = SIDE;
	map->middle = (t_vec2r) { map->nb_col_glb / 2, map->nb_line_glb / 2 };
}

static void		alloc_map(t_map *map)
{
	if (!(map->vertices = ft_memalloc(sizeof(t_vec4) * map->nb_vtx)))
		error_exit("");
	if (!(map->mod_vertices = ft_memalloc(sizeof(t_vec4) * map->nb_vtx)))
		error_exit("");
	if (!(map->target_vtx_y = ft_memalloc(sizeof(float) * map->nb_vtx)))
		error_exit("");
	if (!(map->world_coords_glb = ft_memalloc(sizeof(t_vec4)
					* map->nb_vtx_glb)))
		error_exit("");
	if (!(map->world_vtx = ft_memalloc(sizeof(t_vec4) * map->nb_vtx)))
		error_exit("");
	if (!(map->m_world_vtx = ft_memalloc(sizeof(t_vec4) * map->nb_vtx)))
		error_exit("");
	if (!(map->distancesxy = ft_memalloc(sizeof(float) * map->nb_vtx)))
		error_exit("");
	if (!(map->distancesxz = ft_memalloc(sizeof(float) * map->nb_vtx)))
		error_exit("");
	if (!(map->proj = ft_memalloc(sizeof(t_vec3) * map->nb_vtx)))
		error_exit("");
	if (!(map->draw = ft_memalloc(sizeof(t_vec2c) * map->nb_vtx)))
		error_exit("");
	if (!(map->clip = ft_memalloc(sizeof(char) * map->nb_vtx)))
		error_exit("");
}

void			parse_map(t_map *map, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("");
	map_to_list(fd, map);
	ft_putendl("map is in da list");
	map->vertices_glb = ft_lst_to_array(map->vertices_list);
	ft_putendl("map is in da array");
	define_attributes(map);
	alloc_map(map);
	if (close(fd) == -1)
		error_exit("");
}
