/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 02:13:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 12:08:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_floor(int from, t_sector *sector, t_render *r, t_env *e)
{
	double		distance;
	int			x;
	int			y;
	t_player	*p;
	t_texture	*txt;
	int			color;

	if (from <= r->current_top)
		return ;
	p = e->game->player;
	txt = e->game->map->textures + 2;
	e->ints[9] = from;
	while (from > r->current_top)
	{
		distance = ((PLAYER_HEIGHT * e->pplane->distance_to_pp /
			abs(from - e->pplane->shifted_y)) + r->base_distance) / r->cos_ray_ref;
		x = abs((int)floor(r->reference_pos.x + distance * r->ray_cos) * 4 % txt->width);
		y = abs((int)floor(r->reference_pos.y + distance * r->ray_sin) * 4 % txt->height);
		color = *(int*)(txt->data + (y * 3 * txt->width +
			x * 3));
		color = color & 0xFFFFFF;
		mlx_put_pixel_to_img(e->column, from, color, e->screen);
		from--;
	}
	r->current_top = e->ints[9];
	(void)sector;
}
