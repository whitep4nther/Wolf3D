/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_other_portal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 00:08:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 00:09:32 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_portal		*the_other_portal(t_portal *from, t_env *e)
{
	if (from == e->game->lportal)
		return (e->game->rportal);
	return (e->game->lportal);
}
