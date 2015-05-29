/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_through_portal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 06:39:33 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 08:32:37 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_through_portal(int which, double base_distance, t_env *e)
{
	t_portal	*from;
	t_portal	*to;
	t_segment2	new_ray;
	t_render	*r;
	double		percent;

	r = e->render;
	from = (which == LEFT_PORTAL) ? e->game->lportal : e->game->rportal;
	to = (which == LEFT_PORTAL) ? e->game->rportal : e->game->lportal;
	e->ints[0] = fabs(r->tmp_wall->seg.points[1].x - r->tmp_wall->seg.points[0].x);
	e->ints[1] = fabs(r->tmp_wall->seg.points[1].y - r->tmp_wall->seg.points[0].y);
	if (e->ints[0] > e->ints[1])
		percent = (r->tmp_inter->intersection.x - from->pos.x) /
			PORTAL_WIDTH * r->tmp_wall->cos;
	else
		percent = (r->tmp_inter->intersection.y - from->pos.y) /
			PORTAL_WIDTH * r->tmp_wall->sin;
	new_ray.points[0].x = to->pos.x + PORTAL_WIDTH * to->wall->cos * percent;
	new_ray.points[0].y = to->pos.y + PORTAL_WIDTH * to->wall->sin * percent;
	set_ray(true_angle(r->current_angle + to->wall->angle), &new_ray);
	render_minimap_ray(&new_ray, e);
	render_sector(&new_ray, to->sector, base_distance + r->tmp_inter->cos_distance, e);
}
