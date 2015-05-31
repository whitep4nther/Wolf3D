/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_step_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 01:31:09 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 13:50:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_step_up(t_sector *from, t_sector *to,
	   			t_w_intersection *w_inter, t_env *e)
{
	double		z1;
	double		z2;
	int			y1;
	int			y2;

	z1 = get_z_in_sector(from, w_inter->intersection.x, w_inter->intersection.y);
	z2 = get_z_in_sector(to, w_inter->intersection.x, w_inter->intersection.y);
	if (z1 >= z2)
		return ;
	y1 = w_inter->projected_y1;
	y2 = y1 + floor(z2 / w_inter->cos_distance * e->pplane->distance_to_pp);
	render_slice(y1, y2, 0x009918AD, e);
}
