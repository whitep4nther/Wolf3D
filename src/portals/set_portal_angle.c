/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_portal_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 07:37:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 08:14:43 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		set_portal_angle(double angle, t_portal *portal)
{
	portal->angle = angle;
	portal->angle_cos = cos(D2R(angle));
	portal->angle_sin = sin(D2R(angle));
	angle = true_angle(angle - 90);
	portal->direction_cos = cos(D2R(angle));
	portal->direction_sin = sin(D2R(angle));
	portal->half_wcos_computed = (PORTAL_WIDTH >> 1) * portal->direction_cos
		+ 0.0001;
	portal->half_wsin_computed = (PORTAL_WIDTH >> 1) * portal->direction_sin
		+ 0.0001;
}
