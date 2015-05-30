/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_through_portal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 06:39:33 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:07:55 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_through_portal(t_portal *from, t_portal *to,
				t_render *r, t_env *e)
{
	t_render	new_r;
	double		new_angle;

	if (r->depth == 2)
		return ;
	new_angle = true_angle(to->angle + (true_angle(r->ray_angle - 180) - from->angle));
	get_portal_new_pos(from, &r->tmp_inter->intersection, to, &new_r.ray.points[0]);
	init_render_struct(new_angle, to->angle,
		&new_r.ray.points[0], &new_r);
	new_r.cos_ray_ref = r->cos_ray_ref;
	new_r.base_distance = r->base_distance + r->tmp_inter->distance;
	new_r.depth = r->depth + 1;
	render_minimap_ray(&new_r.ray, e);
	render_sector(to->sector, &new_r, e);
}
