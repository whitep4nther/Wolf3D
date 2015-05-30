/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_portal_new_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 02:07:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 05:12:11 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			get_portal_new_pos(t_portal *from, t_point2 *inter,
				t_portal *to, t_point2 *new_pos)
{
	double		percent;
	
	if (fabs(from->wall->cos) > fabs(from->wall->sin))
		percent = (inter->x - from->pos.x) / PORTAL_WIDTH * from->wall->cos;
	else
		percent = (inter->y - from->pos.y) / PORTAL_WIDTH * from->wall->sin;
	new_pos->x = to->pos.x + PORTAL_WIDTH * to->wall->cos * percent + 1 * to->cos;
	new_pos->y = to->pos.y + PORTAL_WIDTH * to->wall->sin * percent + 1 * to->sin;
}
