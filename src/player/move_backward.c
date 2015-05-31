/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_backward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:51:17 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 03:14:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_backward(t_env *e)
{
	t_player	*player;

	player = e->game->player;
	process_player_movement(true_angle(player->angle + 180), player->speed,
		player, e);
}
