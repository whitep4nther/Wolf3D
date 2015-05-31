/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_portal_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 06:24:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 01:55:00 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				get_portal_color(t_portal *portal, t_env *e)
{
	if (portal == e->game->lportal)
		return (LPORTAL_COLOR);
	return (RPORTAL_COLOR);
}
