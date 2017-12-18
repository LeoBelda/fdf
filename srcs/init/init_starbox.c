/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_starbox.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 23:57:19 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/18 03:54:21 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_starfuncs(t_map *map)
{
	if (!(map->starfuncs = ft_memalloc(sizeof(t_starfuncs) * 7)))
		error_exit("");
	map->starfuncs[0] = (t_starfuncs) {draw_star_10, "10"};
	map->starfuncs[1] = (t_starfuncs) {draw_star_11, "11"};
	map->starfuncs[2] = (t_starfuncs) {draw_star_p0, "P0"};
	map->starfuncs[3] = (t_starfuncs) {draw_star_p1, "P1"};
	map->starfuncs[4] = (t_starfuncs) {draw_star_n0, "N0"};
	map->starfuncs[5] = (t_starfuncs) {draw_star_n1, "N1"};
	map->starfuncs[6] = (t_starfuncs) {NULL, ""};
}

static fct_type	get_star_type(char *line, t_starfuncs *funcs)
{
	size_t	i;

	i = 0;
	while (funcs[i].draw)
	{
		if (!ft_strcmp(&(line[1]), funcs[i].type))
			return (funcs[i].draw);
		i++;
	}
	error_exit("Non valid type in the starmap");
	return (NULL);
}

static void		parse_stars(t_star *starbox, t_starfuncs *funcs, int fd)
{
	int		i;
	int		ret;
	char	*line;
	char	**tab;
	void	(*drawfunc)();

	i = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			error_exit("");
		if (line[0] == '>')
			drawfunc = get_star_type(line, funcs);
		else
		{
			if (!(tab = ft_strsplit(line, ' ')))
				error_exit("");
			starbox[i] = (t_star){(t_vec4){ft_atoi(tab[0]) * 100,
				ft_atoi(tab[1]) * 100, ft_atoi(tab[2]) * 100, 1.0}, drawfunc};
			ft_tabdel(&tab);
			i++;
		}
	}
}

void	init_starbox(t_map *map)
{
	char	*header;
	int		fd;

	init_starfuncs(map);
	if ((fd = open("srcs/graphics/stars/starmap.sb", O_RDONLY)) == -1)
		error_exit("");
	if (get_next_line(fd, &header) == -1)
		error_exit("Failed to parse starmap");
	map->starbox_size = ft_atoi(header);
	if (!(map->starbox = ft_memalloc(sizeof(t_star) * map->starbox_size)))
		error_exit("");
	if (!(map->starproj = ft_memalloc(sizeof(t_vec3) * map->starbox_size)))
		error_exit("");
	if (!(map->stardraw = ft_memalloc(sizeof(t_vec2r) * map->starbox_size)))
		error_exit("");
	parse_stars(map->starbox, map->starfuncs, fd);
}
