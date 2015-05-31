/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_portal_visible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 05:38:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 07:26:37 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			is_portal_visible(double angle, t_portal *portal)
{
	if (angles_within_gap(true_angle(angle - 180), portal->angle, 90))
		return (1);
	return (0);
}
