/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_z_in_sector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 02:33:41 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 13:49:05 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

double			get_z_in_sector(t_sector *sector, double x, double y)
{
	t_point2	relative;

	relative.x = x - sector->reference.x;
	relative.y = y - sector->reference.y;
	return (sector->reference.z + relative.x * sector->z1
		+ relative.y * sector->z2);
}
