/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_sector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 01:09:11 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 01:26:24 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_sector		*next_sector(t_wall *wall, t_sector *sector, t_sector *sectors)
{
	if (wall->sectors_id[0] == sector->id)
		return (sectors + wall->sectors_id[1]);
	return (sectors + wall->sectors_id[0]);
}
