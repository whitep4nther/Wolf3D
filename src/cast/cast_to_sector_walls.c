/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_sector_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 02:40:36 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 04:55:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

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
			sort[walls_intersected].content = w_inter;
			walls_intersected++;
		}
	}
	return (walls_intersected);
}
