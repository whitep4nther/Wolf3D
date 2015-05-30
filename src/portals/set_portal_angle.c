/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_portal_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 07:37:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:46:32 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		set_portal_angle(double angle, t_portal *portal)
{
	portal->angle = angle;
	portal->cos = cos(D2R(angle));
	portal->sin = sin(D2R(angle));
}
