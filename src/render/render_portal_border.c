/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal_border.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 06:32:58 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 06:47:36 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		render_portal_border(t_portal *portal, t_w_intersection *w_inter,
			t_render *r, t_env *e)
{
	int		y1;

	if (w_inter->projected_y2 <= e->g_render->current_top)
		return ;
	y1 = (w_inter->projected_y1 < e->g_render->current_top) ?
		e->g_render->current_top : w_inter->projected_y1;
	setup_x1_y1_x2(e->g_render->column, y1,
		e->g_render->column, e->mlx->mlx_i);
	setup_y2_color(w_inter->projected_y2, get_portal_color(portal, e),
		e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	e->g_render->current_top = w_inter->projected_y2;
	(void)r;
}
