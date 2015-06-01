/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:10:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 08:29:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_wall(t_w_intersection *i, t_render *r)
{
	int			column;
	int			index;
	double		coef;
	int			y1;
	int			y2;
	int			color;
	t_texture	*txt;
	int			x;

	x = r->e->column;
	if (i->wall->height == 22)
		txt = r->e->game->map->textures + 1;
	else
		txt = r->e->game->map->textures;
	y1 = i->projected_y1;
	y2 = i->projected_y2;
	coef = i->wall->height / (double)(y2 - y1);
	if (y2 <= r->current_top)
		return ;
	if (y2 > r->max_y)
		y2 = r->max_y;
	if (y1 < r->current_top)
		y1 = r->current_top;
	if (fabs(i->wall->cos) > fabs(i->wall->sin))
		column = (int)((i->intersection.x - i->wall->seg.points[0].x) * 1 / i->wall->cos * 8) %
			txt->width;
	else
		column = (int)((i->intersection.y - i->wall->seg.points[0].y) * 1 / i->wall->sin * 8) %
			txt->width;
	while (y1 <= y2)
	{
		index = column * 3 + ((((int)((y1 - i->projected_y1) * coef * 8) % txt->height * txt->width) ) * 3);
		color = (*(int*)(txt->data + (int)(index)) & 0xFFFFFF);
		mlx_put_pixel_to_img(x, y1, color, r->e->screen);
		y1++;
	}
	r->current_top = y2;
}
