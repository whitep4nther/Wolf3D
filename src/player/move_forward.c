/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 04:19:49 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 05:23:38 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_forward(t_env *e)
{
	t_player	*player;

	player = e->game->player;
	process_player_movement(player->angle, player->speed, player, e);
}
