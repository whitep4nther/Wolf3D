/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_sector_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 02:40:36 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 03:13:45 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		fill_wall_intersection(t_point2 *intersection,
				t_w_intersection *w_inter, t_render *r, t_env *e)
{
	double		coef;

	w_inter->distance = distance_point2(intersection, &r->reference_pos) + r->base_distance;
	w_inter->cos_distance = w_inter->distance * r->cos_ray_ref;
	coef = e->pplane->distance_to_pp / w_inter->cos_distance;
	w_inter->projected_height = round(w_inter->wall->height * coef);
	w_inter->projected_y1 = round(e->pplane->center_y - (PLAYER_HEIGHT - get_z_in_sector(r->tmp_sector, intersection->x, intersection->y)) * coef);
	w_inter->projected_y2 = w_inter->projected_y1 + w_inter->projected_height;
}

int				cast_to_sector_walls(t_segment2 *ray, t_sector *sector,
				t_w_intersection *w_intersections, t_sort *sort)
{
	int			walls_intersected;
	int			i;
	t_point2	*intersection;
	t_w_intersection	*w_inter;

	walls_intersected = 0;
	i = -1;
	while (++i < sector->nb_walls)
	{
		w_inter = w_intersections + walls_intersected;
		intersection = &w_inter->intersection;
		if (intersection_segment2_to_segment2(ray,
			&sector->walls[i]->seg, intersection))
		{
			w_inter->wall = sector->walls[i];
			w_inter->distance = distance_point2(intersection, &ray->points[0]);
			r->sort[walls_intersected].content = w_inter;
			walls_intersected++;
		}
	}
	return (walls_intersected);
}

int				cast_to_sector_walls(char calculate, t_sector *sector, t_render *r, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_point2	*intersection;
	t_w_intersection	*w_inter;

	walls_intersected = 0;
	i = -1;
	while (++i < sector->nb_walls)
	{
		r->tmp_wall = sector->walls[i];
		if (r->tmp_wall->column_rendered == e->g_render->column
			&& r->tmp_wall->depth_rendered == r->depth)
			continue ;
		w_inter = r->w_intersection + walls_intersected;
		intersection = &w_inter->intersection;
		if (intersection_segment2_to_segment2(&r->ray,
			&sector->walls[i]->seg, intersection))
		{
			w_inter->wall = sector->walls[i];
			r->tmp_sector = sector;
			if (calculate)
				fill_wall_intersection(intersection, w_inter, r, e);
			r->sort[walls_intersected].content = w_inter;
			walls_intersected++;
		}
	}
	return (walls_intersected);
}
