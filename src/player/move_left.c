/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 10:00:40 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 10:16:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_left(t_env *e)
{
	t_player	*player;

	player = e->game->player;
	process_player_movement(true_angle(player->angle + 90), player->speed *
		PLAYER_SIDE_RATIO, player, e);
}
