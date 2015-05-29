/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_in_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 06:04:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 08:27:00 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				ray_in_portal(t_portal *portal, t_wall *wall, double x, double y)
{
	if (portal->wall->id != wall->id)
		return (0);
	if (fabs(portal->pos.x - x) > PORTAL_WIDTH / 2
		|| fabs(portal->pos.y - y) > PORTAL_WIDTH / 2)
		return (0);
	return (1);
}
