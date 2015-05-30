/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_portal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 07:09:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:47:27 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			send_portal(t_portal *portal, t_player *p,  t_env *e)
{
	t_segment2	ray;
	t_w_intersection	*w_inter;
	int			walls;

	ray.points[0] = p->pos;
	set_ray(p->angle, PLAYER_SIGHT, &ray);
	walls = cast_to_sector_walls(&ray, p->current_sector, e->w_intersection, e->sort);
	if (walls > 0)
	{
		quicksort(e->sort, 0, walls - 1, qs_walls_cmp);
		w_inter = e->sort[0].content;
		portal->wall = w_inter->wall;
		portal->sector = p->current_sector;
		portal->pos = w_inter->intersection;
		portal->angle = true_angle(portal->wall->angle - 90);
		if (fabs(portal->angle - p->angle) < 90)
			portal->angle = true_angle(portal->angle - 180);
		set_portal_angle(portal->angle, portal);
	}
}
