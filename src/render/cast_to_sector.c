/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_sector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 21:14:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 08:30:33 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		fill_wall_intersection(t_point2 *intersection,
				t_w_intersection *w_inter, double base_distance, t_env *e)
{
	double		coef;

	w_inter->distance = distance_point2(intersection, &e->game->player->pos);
	w_inter->cos_distance = w_inter->distance *
		cos(D2R(true_angle(e->render->current_angle - e->game->player->angle)))
		+ base_distance;
	coef = e->pplane->distance_to_pp / w_inter->cos_distance;
	w_inter->projected_height = round(e->game->map->walls[w_inter->wall].height
		* coef);
	w_inter->projected_y1 = round(e->pplane->center_y - (PLAYER_HEIGHT - get_z_in_sector(e->render->tmp_sector, intersection->x, intersection->y)) * coef);
	w_inter->projected_y2 = w_inter->projected_y1 + w_inter->projected_height;
}

int				cast_to_sector(t_segment2 *ray, t_sector *sector,
				double base_distance, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_point2	*intersection;
	t_w_intersection	*w_inter;

	walls_intersected = 0;
	i = -1;
	while (++i < sector->nb_walls)
	{
		if (e->game->map->walls[sector->walls[i]].column_rendered == e->render->column)
			continue ;
		w_inter = e->render->w_intersection + walls_intersected;
		intersection = &w_inter->intersection;
		if (intersection_segment2_to_segment2(ray,
			&e->game->map->walls[sector->walls[i]].seg, intersection))
		{
			w_inter->wall = sector->walls[i];
			e->render->tmp_sector = sector;
			fill_wall_intersection(intersection, w_inter, base_distance, e);
			e->render->sort[walls_intersected].content = w_inter;
			walls_intersected++;
		}
	}
	return (walls_intersected);
}
