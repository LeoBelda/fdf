/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:41:26 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/14 15:09:34 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_mid(t_vec2r pt, t_colorset cl, int *ad)
{
	dw_pt((t_vec2r){pt.x - 1, pt.y - 2}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 2}, (t_cmix){cl.st1, cl.st3, 1.}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y - 2}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y - 1}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 1}, (t_cmix){cl.st1, cl.st3, 1.}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y - 1}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y}, (t_cmix){cl.st3, cl.st1, .0}, ad);
	dw_pt(pt, (t_cmix){cl.st3, cl.st1, .0}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y}, (t_cmix){cl.st3, cl.st1, .0}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y + 1}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 1}, (t_cmix){cl.st1, cl.st3, 1.}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y + 1}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y + 2}, (t_cmix){cl.st1, cl.st3, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 2}, (t_cmix){cl.st1, cl.st3, 1.}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y + 2}, (t_cmix){cl.st1, cl.st3, .5}, ad);
}

static void	draw_topbot(t_vec2r pt, t_colorset cl, int *ad)
{
	dw_pt((t_vec2r){pt.x, pt.y - 7}, (t_cmix){cl.st3, cl.st1, .7}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 6}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 5}, (t_cmix){cl.st3, cl.st1, .3}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 4}, (t_cmix){cl.st3, cl.st1, .2}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y - 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y - 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y - 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 7}, (t_cmix){cl.st3, cl.st1, .7}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 6}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 5}, (t_cmix){cl.st3, cl.st1, .3}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 4}, (t_cmix){cl.st3, cl.st1, .2}, ad);
	dw_pt((t_vec2r){pt.x - 1, pt.y + 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x, pt.y + 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 1, pt.y + 3}, (t_cmix){cl.st3, cl.st1, .5}, ad);
}

static void	draw_leftright(t_vec2r pt, t_colorset cl, int *ad)
{
	dw_pt((t_vec2r){pt.x - 4, pt.y}, (t_cmix){cl.st3, cl.st1, .8}, ad);
	dw_pt((t_vec2r){pt.x - 3, pt.y}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x - 2, pt.y - 2}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x - 2, pt.y - 1}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x - 2, pt.y}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x - 2, pt.y + 1}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x - 2, pt.y + 2}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 4, pt.y}, (t_cmix){cl.st3, cl.st1, .8}, ad);
	dw_pt((t_vec2r){pt.x + 3, pt.y}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 2, pt.y - 2}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 2, pt.y - 1}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 2, pt.y}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 2, pt.y + 1}, (t_cmix){cl.st3, cl.st1, .5}, ad);
	dw_pt((t_vec2r){pt.x + 2, pt.y + 2}, (t_cmix){cl.st3, cl.st1, .5}, ad);
}

void		draw_star_n1(t_vec2r point, t_colorset cl, int *addr)
{
	draw_mid(point, cl, addr);
	draw_topbot(point, cl, addr);
	draw_leftright(point, cl, addr);
}
