/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 02:13:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 05:17:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_floor(int from, t_sector *sector, t_env *e)
{
	if (from <= e->render->current_top)
		return ;
	setup_x1_y1_x2(e->render->column, e->render->current_top, e->render->column,
		e->mlx->mlx_i);
	setup_y2_color(from, 0xCCCCCC00, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	e->render->current_top = from;
	(void)sector;
}
