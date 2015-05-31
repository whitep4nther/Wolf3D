/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 08:21:01 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 10:03:06 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int			mouse_move_hook(double delta_x, double delta_y, t_env *e)
{
	set_player_angle(true_angle(e->game->player->angle - delta_x / 15),
		e->game->player);
	(void)delta_y;
	return (0);
}
