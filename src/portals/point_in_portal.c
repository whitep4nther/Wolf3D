/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_in_portal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 00:11:12 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 00:13:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				point_in_portal(t_portal *portal, t_point2 *p)
{
	if (fabs(portal->pos.x - p->x) > PORTAL_WIDTH / 2
		|| fabs(portal->pos.y - p->y) > PORTAL_WIDTH / 2)
		return (0);
	return (1);
}
