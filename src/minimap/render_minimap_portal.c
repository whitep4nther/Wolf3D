/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_portal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 07:21:59 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 12:24:50 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_minimap_portal(t_portal *portal, t_env *e)
{
	t_segment2	ray;

	ray.points[0].x = portal->pos.x - PORTAL_WIDTH * portal->direction_cos;
	ray.points[0].y = portal->pos.y - PORTAL_WIDTH * portal->direction_sin;
	ray.points[1].x = portal->pos.x + PORTAL_WIDTH * portal->direction_cos;
	ray.points[1].y = portal->pos.y + PORTAL_WIDTH * portal->direction_sin;
	render_minimap_seg(&ray, get_portal_color(portal, e), e);
	ray.points[0] = portal->pos;
	ray.points[1].x = ray.points[0].x + PORTAL_WIDTH * portal->angle_cos;
	ray.points[1].y = ray.points[0].y + PORTAL_WIDTH * portal->angle_sin;
	render_minimap_seg(&ray, get_portal_color(portal, e), e);
}
