/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 07:04:58 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 07:05:40 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		set_ray(double angle, t_segment2 *ray)
{
	ray->points[1].x = ray->points[0].x + cos(D2R(angle)) * PLAYER_SIGHT;
	ray->points[1].y = ray->points[0].y + sin(D2R(angle)) * PLAYER_SIGHT;
}
