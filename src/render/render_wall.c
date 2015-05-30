/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:10:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 04:22:02 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_wall(t_w_intersection *i, t_env *e)
{
	int			y1;
	int			y2;

	y1 = i->projected_y1;
	y2 = i->projected_y2;
	if (e->g_render->current_top > y2)
		return ;
	if (e->g_render->current_top > y1)
		y1 = e->g_render->current_top;
	if (y2 > e->screen->height)
		y2 = e->screen->height;
	setup_x1_y1_x2(e->g_render->column, y1, e->g_render->column, e->mlx->mlx_i);
	setup_y2_color(y2, 0xdddddd00 + 0x11111100 * i->wall->id, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	e->g_render->current_top = y2;
}
