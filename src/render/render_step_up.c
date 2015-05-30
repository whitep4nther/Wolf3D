/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_step_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 01:31:09 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 02:06:09 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_step_up(t_sector *from, t_sector *to,
	   			t_w_intersection *w_inter, t_env *e)
{
	double		z1;
	double		z2;
	int			y1;
	int			y2;

	z1 = get_z_in_sector(from, w_inter->intersection.x, w_inter->intersection.y);
	z2 = get_z_in_sector(to, w_inter->intersection.x, w_inter->intersection.y);
	if (z1 >= z2)
		return ;
	y1 = w_inter->projected_y1;
	y2 = y1 + z2 / w_inter->cos_distance * e->pplane->distance_to_pp;
	if (e->g_render->current_top > y2)
		return ;
	if (e->g_render->current_top > y1)
		y1 = e->g_render->current_top;
	setup_x1_y1_x2(e->g_render->column, y1, e->g_render->column, e->mlx->mlx_i);
	setup_y2_color(y2, 0x9918ad00, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	e->g_render->current_top = y2;
}
