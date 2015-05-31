/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 10:00:46 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 10:25:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_right(t_env *e)
{
	t_player	*player;

	player = e->game->player;
	process_player_movement(true_angle(player->angle - 90), player->speed *
		PLAYER_SIDE_RATIO, player, e);
}
