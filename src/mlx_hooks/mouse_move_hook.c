/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 08:21:01 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 08:51:22 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			mouse_move_hook(double delta_x, double delta_y, t_env *e)
{
	int		y;

	set_player_angle(true_angle(e->game->player->angle - delta_x / 15),
		e->game->player);
	y = e->game->player->z_shift += delta_y;
	if (y < -e->pplane->center_y)
		y = -e->pplane->center_y;
	else if (y > e->pplane->center_y)
		y = e->pplane->center_y;
	e->game->player->z_shift = y;
	e->pplane->shifted_y = e->pplane->center_y + y;
	(void)delta_y;
	return (0);
}
