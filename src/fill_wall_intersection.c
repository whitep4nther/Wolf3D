/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 01:47:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 01:55:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			fill_wall_intersection(t_point2 *intersection,
				t_w_intersection *w_inter, t_sector *sector, t_env *e)
{
	double		coef;

	w_inter->distance = distance_point2(intersection, &e->game->player->pos);
	w_inter->cos_distance = w_inter->distance *
		cos(D2R(true_angle(e->render->current_angle - e->game->player->angle)));
	coef = e->pplane->distance_to_pp / w_inter->cos_distance;
	w_inter->projected_height = round(e->game->map->walls[w_inter->wall].height
		* coef);
	w_inter->projected_y1 = round(e->pplane->center_y - PLAYER_HEIGHT * coef +
		get_z_in_sector(sector, intersection->x, intersection->y));
	w_inter->projected_y2 = y1 + w_inter->projected_height;
}
