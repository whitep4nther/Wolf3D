/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render_struct_ray_angle.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 23:40:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 02:42:28 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			set_render_struct_ray_angle(double ray_angle, t_render *render)
{
	render->ray_angle = ray_angle;
	render->cos_ray_ref = cos(D2R(true_angle(ray_angle - render->reference_angle)));
	set_ray(ray_angle, &render->ray);
}
