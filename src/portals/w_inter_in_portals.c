/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_inter_in_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 05:03:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 08:13:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_portal		*w_inter_in_portals(t_w_intersection *w_inter,
				t_env *e)
{
	t_portal	*portal;

	portal = e->game->lportal;
	if (portal->wall
		&& portal->wall->id == w_inter->wall->id
		&& fabs(portal->pos.x - w_inter->intersection.x) <= fabs(portal->half_wcos_computed)
		&& fabs(portal->pos.y - w_inter->intersection.y) <= fabs(portal->half_wsin_computed))
		return (portal);
	portal = e->game->rportal;
	if (portal->wall
		&& portal->wall->id == w_inter->wall->id
		&& fabs(portal->pos.x - w_inter->intersection.x) <= fabs(portal->half_wcos_computed)
		&& fabs(portal->pos.y - w_inter->intersection.y) <= fabs(portal->half_wsin_computed))
		return (portal);
	return (NULL);
}
