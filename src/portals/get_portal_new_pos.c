/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_portal_new_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 02:07:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 08:18:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			get_portal_new_pos(t_portal *from, t_point2 *inter,
				t_portal *to, t_point2 *new_pos)
{
	double		from_start_x;
	double		from_start_y;
	double		to_start_x;
	double		to_start_y;
	double		percent;
	
	from_start_x = from->pos.x - from->half_wcos_computed;
	from_start_y = from->pos.y - from->half_wsin_computed;
	to_start_x = to->pos.x - to->half_wcos_computed;
	to_start_y = to->pos.y - to->half_wsin_computed;
	if (fabs(from->direction_cos) > fabs(from->direction_sin))
		percent = (inter->x - from_start_x) / PORTAL_WIDTH * from->direction_cos;
	else
		percent = (inter->y - from_start_y) / PORTAL_WIDTH * from->direction_sin;
	percent = 1 - percent;
	new_pos->x = to_start_x + PORTAL_WIDTH * to->direction_cos * percent + 1 * to->angle_cos;
	new_pos->y = to_start_y + PORTAL_WIDTH * to->direction_sin * percent + 1 * to->angle_sin;
}
