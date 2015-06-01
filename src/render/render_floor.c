/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 02:13:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 05:05:12 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_floor(int from, t_sector *sector, t_render *r, t_env *e)
{
	if (from <= r->current_top)
		return ;
	setup_x1_y1_x2(e->column, r->current_top, e->column,
		e->mlx->mlx_i);
	setup_y2_color(from, 0x00CCCCCC, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	r->current_top = from;
	(void)sector;
}
