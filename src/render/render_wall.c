/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:10:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 06:57:18 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_wall(t_w_intersection *i, t_render *r)
{
	int			column;
	int			index;
	int			y1;
	int			y2;
	int			color;
	t_texture	*txt;
	int			x;

	x = r->e->column;	
	txt = r->e->game->map->textures;
	y1 = i->projected_y1;
	y2 = i->projected_y2;
	if (y2 <= r->current_top)
		return ;
	if (y2 > r->max_y)
		y2 = r->max_y;
	if (y1 < r->current_top)
		y1 = r->current_top;
	if (fabs(i->wall->cos) > fabs(i->wall->sin))
		column = (int)((i->intersection.x - i->wall->seg.points[0].x) * 1 / i->wall->cos) %
			txt->width;
	else
		column = (int)((i->intersection.y - i->wall->seg.points[0].y) * 1 / i->wall->sin) %
			txt->width;
	index = column;
	while (y1 <= y2)
	{
		color = *(int*)(txt->data + index);
		mlx_put_pixel_to_img(x, y1, color, r->e->screen);
		index += txt->width;
		y1++;
	}
}
