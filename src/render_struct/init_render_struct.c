/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 23:27:20 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 03:29:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			init_render_struct(double ray_angle, double reference_angle,
				t_point2 *reference_pos, t_render *render)
{
	render->reference_angle = reference_angle;
	render->reference_pos = *reference_pos;
	render->tmp_inter = NULL;
	render->tmp_wall = NULL;
	render->tmp_sector = NULL;
	render->ray.points[0] = *reference_pos;
	set_render_struct_ray_angle(ray_angle, PLAYER_SIGHT, render);
}
